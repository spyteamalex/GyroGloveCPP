#include "devicehandler.h"
#include <QtEndian>
#include <QRandomGenerator>
#include "global.h"


DeviceHandler::DeviceHandler(QObject *parent) :
        QObject(parent),
        m_foundOutput(false) {}

DeviceHandler::~DeviceHandler() {
    delete m_service;
    delete m_control;
}


void DeviceHandler::setAddressType(AddressType type) {
    switch (type) {
        case DeviceHandler::AddressType::PublicAddress:
            m_addressType = QLowEnergyController::PublicAddress;
            break;
        case DeviceHandler::AddressType::RandomAddress:
            m_addressType = QLowEnergyController::RandomAddress;
            break;
    }
}

DeviceHandler::AddressType DeviceHandler::addressType() const {
    if (m_addressType == QLowEnergyController::RandomAddress)
        return DeviceHandler::AddressType::RandomAddress;

    return DeviceHandler::AddressType::PublicAddress;
}

void DeviceHandler::connectDevice(QBluetoothDeviceInfo *device) {
    m_currentDevice = device;

    if (m_control) {
        disconnectService();
    }
    if (m_currentDevice) {
        m_control = QLowEnergyController::createCentral(*m_currentDevice, this);
        m_control->setRemoteAddressType(m_addressType);
        connect(m_control, &QLowEnergyController::serviceDiscovered,
                this, &DeviceHandler::serviceDiscovered);
        connect(m_control, &QLowEnergyController::discoveryFinished,
                this, &DeviceHandler::serviceScanDone);

        connect(m_control,
                static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
                this, [this](QLowEnergyController::Error error) {
                    errorln("Cannot connect to remote device.");
                });
        connect(m_control, &QLowEnergyController::connected, this, [this]() {
            logln("Controller connected. Search services...");
            m_control->discoverServices();
        });
        connect(m_control, &QLowEnergyController::disconnected, this, [this]() {
            errorln("Controller disconnected");
        });

        m_control->connectToDevice();
    }
}

void DeviceHandler::serviceDiscovered(const QBluetoothUuid &gatt) {
    if (gatt == QBluetoothUuid(SERVICE)) {
        logln("Service discovered. Waiting for service scan to be done...");
        m_foundOutput = true;
    }
}

void DeviceHandler::serviceScanDone() {
    logln("Service scan done.");

    if (m_service) {
        delete m_service;
        m_service = nullptr;
    }

    if (m_foundOutput)
        m_service = m_control->createServiceObject(QBluetoothUuid(SERVICE), this);

    if (m_service) {
        connect(m_service, &QLowEnergyService::stateChanged, this, &DeviceHandler::serviceStateChanged);
        connect(m_service, &QLowEnergyService::characteristicChanged, this, &DeviceHandler::receiveData);
        connect(m_service, &QLowEnergyService::descriptorWritten, this, &DeviceHandler::confirmedDescriptorWrite);
        m_service->discoverDetails();
    } else {
        errorln("Service not found.");
    }
}

void DeviceHandler::serviceStateChanged(QLowEnergyService::ServiceState s) {
    switch (s) {
        case QLowEnergyService::DiscoveringServices:
            logln("Discovering services...");
            break;
        case QLowEnergyService::ServiceDiscovered: {
            logln("Service discovered.");
            const QLowEnergyCharacteristic outChar = m_service->characteristic(QBluetoothUuid(CHARACTERISTIC));
            if (!outChar.isValid()) {
                errorln("Data not found.");
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

void DeviceHandler::receiveData(const QLowEnergyCharacteristic &c, const QByteArray &value) {
    if (c.uuid() != QBluetoothUuid(CHARACTERISTIC))
        return;
    emit dataReceived(value);
}

void DeviceHandler::confirmedDescriptorWrite(const QLowEnergyDescriptor &d, const QByteArray &value) {
    if (d.isValid() && d == m_notificationDesc && value == QByteArray::fromHex("0000")) {
        m_control->disconnectFromDevice();
        delete m_service;
        m_service = nullptr;
    }
}

void DeviceHandler::disconnectService() {
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

bool DeviceHandler::alive() const {
    if (m_service)
        return m_service->state() == QLowEnergyService::ServiceDiscovered;

    return false;
}
