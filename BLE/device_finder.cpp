#include "device_finder.h"
#include "device_connector.h"
#include "../global.h"

#define prefix "BLE scanner"

DeviceFinder::DeviceFinder(QObject *parent) :
        QObject(parent) {
    m_deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    m_deviceDiscoveryAgent->setLowEnergyDiscoveryTimeout(5000);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &DeviceFinder::addDevice);
    connect(m_deviceDiscoveryAgent, static_cast<void (QBluetoothDeviceDiscoveryAgent::*)(
                    QBluetoothDeviceDiscoveryAgent::Error)>(&QBluetoothDeviceDiscoveryAgent::error),
            this, &DeviceFinder::scanError);

    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &DeviceFinder::scanFinished);
    connect(m_deviceDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::canceled, this, &DeviceFinder::scanFinished);
}

DeviceFinder::~DeviceFinder() {
    delete m_deviceDiscoveryAgent;
}

void DeviceFinder::startSearch() {
    m_devices.clear();

    m_deviceDiscoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
    logln(prefix, "Scanning for devices...");

    emit devicesChanged();
    emit stateChanged(STATE::SEARCHING);
}

void DeviceFinder::addDevice(const QBluetoothDeviceInfo& device) {
    if (device.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) {
        m_devices.append(device);
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
    if (m_devices.isEmpty())
        errorln(prefix, "No Low Energy devices found.");
    else {
        logln(prefix, "Scanning done.");
    }
    emit stateChanged(STATE::FINISHED);
}

const QList<QBluetoothDeviceInfo>& DeviceFinder::devices() {
    return m_devices;
}

DeviceFinder::STATE DeviceFinder::state() {
    return m_state;
}