#include "device_finder.h"
#include "device_connector.h"
#include "../global.h"

#define prefix "BLE scanner"

DeviceFinder::DeviceFinder(QObject *parent) :
        QObject(parent) {
    deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(5000);

    connect(deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &DeviceFinder::addDevice);
    connect(deviceDiscoveryAgent, static_cast<void (QBluetoothDeviceDiscoveryAgent::*)(
                    QBluetoothDeviceDiscoveryAgent::Error)>(&QBluetoothDeviceDiscoveryAgent::error),
            this, &DeviceFinder::scanError);

    connect(deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &DeviceFinder::scanFinished);
    connect(deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled, this, &DeviceFinder::scanFinished);
}

DeviceFinder::~DeviceFinder() {
    delete deviceDiscoveryAgent;
}

void DeviceFinder::startSearch() {
    devices.clear();

    deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    logln(prefix, "Scanning for devices...");

    emit devicesChanged();
    emit stateChanged(STATE::SEARCHING);
}

void DeviceFinder::addDevice(const QBluetoothDeviceInfo& device) {
    if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
        devices.append(device);
//        logln("Low Energy device found. Scanning more...");
        emit devicesChanged();
    }
}

void DeviceFinder::scanError(const QBluetoothDeviceDiscoveryAgent::Error &error) {
    if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError)
        errorln(prefix, "The Bluetooth adaptor is powered off.");
    else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError)
        errorln(prefix, "Writing or reading from the device resulted in an error.");
    else
        errorln(prefix, "An unknown error has occurred.");
    emit stateChanged(STATE::ERROR);
}

void DeviceFinder::scanFinished() {
    if (devices.isEmpty())
        errorln(prefix, "No Low Energy getDevices found.");
    else {
        logln(prefix, "Scanning done.");
    }
    emit stateChanged(STATE::FINISHED);
}

const QList<QBluetoothDeviceInfo>& DeviceFinder::getDevices() {
    return devices;
}

DeviceFinder::STATE DeviceFinder::getState() {
    return state;
}