#include "device_connector.h"
#include <QtEndian>
#include <QRandomGenerator>
#include "../global.h"


DeviceConnector::DeviceConnector(QObject *parent, const QBluetoothDeviceInfo *device) :
        QObject(parent),
        m_foundOutput(false) {
    connectDevice(device);
}

DeviceConnector::~DeviceConnector() {
    delete m_service;
    delete m_control;
}


void DeviceConnector::setAddressType(AddressType type) {
    switch (type) {
        case DeviceConnector::AddressType::PublicAddress:
            m_addressType = QLowEnergyController::PublicAddress;
            break;
        case DeviceConnector::AddressType::RandomAddress:
            m_addressType = QLowEnergyController::RandomAddress;
            break;
    }
}

DeviceConnector::AddressType DeviceConnector::addressType() const {
    if (m_addressType == QLowEnergyController::RandomAddress)
        return DeviceConnector::AddressType::RandomAddress;

    return DeviceConnector::AddressType::PublicAddress;
}

void DeviceConnector::connectDevice(const QBluetoothDeviceInfo *device) {
    m_currentDevice = device;

    if (m_control) {
        disconnectService();
    }
    if (m_currentDevice) {
        prefix = device->name().toStdString();
        m_control = QLowEnergyController::createCentral(*m_currentDevice, this);
        m_control->setRemoteAddressType(m_addressType);
        connect(m_control, &QLowEnergyController::serviceDiscovered,
                this, &DeviceConnector::serviceDiscovered);
        connect(m_control, &QLowEnergyController::discoveryFinished,
                this, &DeviceConnector::serviceScanDone);

        connect(m_control,
                static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
                this, [this](QLowEnergyController::Error error) {
                    errorln(prefix, "Cannot connect to remote device.");
                });
        connect(m_control, &QLowEnergyController::connected, this, [this]() {
            logln(prefix, "Controller connected. Search services...");
            m_control->discoverServices();
        });
        connect(m_control, &QLowEnergyController::disconnected, this, [this]() {
            errorln(prefix, "Controller disconnected");
        });

        m_control->connectToDevice();
    }
}

void DeviceConnector::serviceDiscovered(const QBluetoothUuid &gatt) {
    if (gatt == QBluetoothUuid(SERVICE)) {
        logln(prefix, "Service discovered. Waiting for service scan to be done...");
        m_foundOutput = true;
    }
}

void DeviceConnector::serviceScanDone() {
    logln(prefix, "Service scan done.");

    if (m_service) {
        delete m_service;
        m_service = nullptr;
    }

    if (m_foundOutput)
        m_service = m_control->createServiceObject(QBluetoothUuid(SERVICE), this);

    if (m_service) {
        connect(m_service, &QLowEnergyService::stateChanged, this, &DeviceConnector::serviceStateChanged);
        connect(m_service, &QLowEnergyService::characteristicChanged, this, &DeviceConnector::receiveData);
        connect(m_service, &QLowEnergyService::descriptorWritten, this, &DeviceConnector::confirmedDescriptorWrite);
        m_service->discoverDetails();
    } else {
        errorln(prefix, "Service not found.");
    }
}

void DeviceConnector::serviceStateChanged(QLowEnergyService::ServiceState s) {
    switch (s) {
        case QLowEnergyService::DiscoveringServices:
            logln(prefix, "Discovering services...");
            break;
        case QLowEnergyService::ServiceDiscovered: {
            logln(prefix, "Service discovered.");
            const QLowEnergyCharacteristic outChar = m_service->characteristic(QBluetoothUuid(CHARACTERISTIC));
            if (!outChar.isValid()) {
                errorln(prefix, "Data not found.");
                break;
            }

            m_notificationDesc = outChar.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
            if (m_notificationDesc.isValid())
                m_service->writeDescriptor(m_notificationDesc, QByteArray::fromHex("0100"));

            break;
        }
        default:
            break;
    }

}

void DeviceConnector::receiveData(const QLowEnergyCharacteristic &c, const QByteArray &value) {
    if (c.uuid() != QBluetoothUuid(CHARACTERISTIC))
        return;
    emit dataReceived(value);
}

void DeviceConnector::confirmedDescriptorWrite(const QLowEnergyDescriptor &d, const QByteArray &value) {
    if (d.isValid() && d == m_notificationDesc && value == QByteArray::fromHex("0000")) {
        m_control->disconnectFromDevice();
        delete m_service;
        m_service = nullptr;
    }
}

void DeviceConnector::disconnectService() {
    m_foundOutput = false;

    if (m_notificationDesc.isValid() && m_service
        && m_notificationDesc.value() == QByteArray::fromHex("0100")) {
        m_service->writeDescriptor(m_notificationDesc, QByteArray::fromHex("0000"));
    }
    if (m_control) {
        m_control->disconnectFromDevice();
        delete m_control;
        m_control = nullptr;
    }
    if (m_service) {
        delete m_service;
        m_service = nullptr;
    }
}

bool DeviceConnector::alive() const {
    if (m_service)
        return m_service->state() == QLowEnergyService::ServiceDiscovered;

    return false;
}
