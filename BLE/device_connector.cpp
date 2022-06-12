#include "device_connector.h"
#include <QtEndian>
#include <QRandomGenerator>
#include "../global.h"


DeviceConnector::DeviceConnector(QObject *parent, const QBluetoothDeviceInfo *device) :
        QObject(parent),
        foundOutput(false) {
    connectDevice(device);
}

DeviceConnector::~DeviceConnector() {
    delete service;
    delete control;
}


void DeviceConnector::setAddressType(AddressType type) {
    switch (type) {
        case DeviceConnector::AddressType::PublicAddress:
            _addressType = QLowEnergyController::PublicAddress;
            break;
        case DeviceConnector::AddressType::RandomAddress:
            _addressType = QLowEnergyController::RandomAddress;
            break;
    }
}

DeviceConnector::AddressType DeviceConnector::addressType() const {
    if (_addressType == QLowEnergyController::RandomAddress)
        return DeviceConnector::AddressType::RandomAddress;

    return DeviceConnector::AddressType::PublicAddress;
}

void DeviceConnector::connectDevice(const QBluetoothDeviceInfo *device) {
    currentDevice = device;

    if (control) {
        disconnectService();
    }
    if (currentDevice) {
        prefix = device->name().toStdString();
        control = QLowEnergyController::createCentral(*currentDevice, this);
        control->setRemoteAddressType(_addressType);
        connect(control, &QLowEnergyController::serviceDiscovered,
                this, &DeviceConnector::serviceDiscovered);
        connect(control, &QLowEnergyController::discoveryFinished,
                this, &DeviceConnector::serviceScanDone);

        connect(control,
                static_cast<void (QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
                this, [this](QLowEnergyController::Error error) {
                    errorln(prefix, "Cannot connect finishAngle remote device.");
                });
        connect(control, &QLowEnergyController::connected, this, [this]() {
            logln(prefix, "Controller connected. Search services...");
            control->discoverServices();
        });
        connect(control, &QLowEnergyController::disconnected, this, [this]() {
            errorln(prefix, "Controller disconnected");
        });

        control->connectToDevice();
    }
}

void DeviceConnector::serviceDiscovered(const QBluetoothUuid &gatt) {
    if (gatt == QBluetoothUuid(SERVICE)) {
        logln(prefix, "Service discovered. Waiting for service scan finishAngle be done...");
        foundOutput = true;
    }
}

void DeviceConnector::serviceScanDone() {
    logln(prefix, "Service scan done.");

    if (service) {
        delete service;
        service = nullptr;
    }

    if (foundOutput)
        service = control->createServiceObject(QBluetoothUuid(SERVICE), this);

    if (service) {
        connect(service, &QLowEnergyService::stateChanged, this, &DeviceConnector::serviceStateChanged);
        connect(service, &QLowEnergyService::characteristicChanged, this, &DeviceConnector::receiveData);
        connect(service, &QLowEnergyService::descriptorWritten, this, &DeviceConnector::confirmedDescriptorWrite);
        service->discoverDetails();
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
            const QLowEnergyCharacteristic outChar = service->characteristic(QBluetoothUuid(CHARACTERISTIC));
            if (!outChar.isValid()) {
                errorln(prefix, "Data not found.");
                break;
            }

            notificationDesc = outChar.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
            if (notificationDesc.isValid())
                service->writeDescriptor(notificationDesc, QByteArray::fromHex("0100"));

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
    if (d.isValid() && d == notificationDesc && value == QByteArray::fromHex("0000")) {
        control->disconnectFromDevice();
        delete service;
        service = nullptr;
    }
}

void DeviceConnector::disconnectService() {
    foundOutput = false;

    if (notificationDesc.isValid() && service
        && notificationDesc.value() == QByteArray::fromHex("0100")) {
        service->writeDescriptor(notificationDesc, QByteArray::fromHex("0000"));
    }
    if (control) {
        control->disconnectFromDevice();
        delete control;
        control = nullptr;
    }
    if (service) {
        delete service;
        service = nullptr;
    }
}

bool DeviceConnector::alive() const {
    if (service)
        return service->state() == QLowEnergyService::ServiceDiscovered;

    return false;
}
