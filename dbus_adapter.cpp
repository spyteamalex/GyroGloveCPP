//
// Created by spyteamalex on 15.06.22.
//

#include "dbus_adapter.h"

void DBusAdapter::update() {
    disconnectAll();
    auto * const connection = new QMetaObject::Connection;
    *connection = DeviceFinder::connect(&deviceFinder, &DeviceFinder::stateChanged, &deviceFinder, [connection, this](DeviceFinder::STATE s) {
        if(s == DeviceFinder::STATE::FINISHED){
            QObject::disconnect(*connection);
            delete connection;
            for(const auto& i : deviceFinder.getDevices()){
                if(i.name() == DEVICE_NAME && tryConnect(i.address())){
                    logln(prefix, "Device with address " + i.address().toString().toStdString() + " found. Connecting...");
                }
            }
        }
    });
    deviceFinder.startSearch();
}

void DBusAdapter::disconnectAll(){
    for(const auto i : handlers){
        i->disconnectDevice();
        handlers.removeAll(i);
        delete i;
    }
}

QString DBusAdapter::getDevices(){
    if(deviceFinder.getState() != DeviceFinder::STATE::FINISHED){
        return "Searching...";
    }
    QString ans = "";
    for(auto i : handlers){
        ans.append(i->getDevice().address().toString()).append("\n");
    }
    return ans;
}

bool DBusAdapter::tryConnect(const QBluetoothAddress& address) {
    bool found = false;
    for(const auto &i : deviceFinder.getDevices()){
        if(i.address() == address){
            auto *hh = new DeviceHandler(i, m, this);
            handlers += hh;
            hh->connectDevice();
            DeviceHandler::connect(hh, &DeviceHandler::stateChanged, this, [this, hh](DeviceConnector::State s){
                switch (s) {
                    case DeviceConnector::State::ServiceConnected:
                    case DeviceConnector::State::Connected:
                        break;
                    case DeviceConnector::State::Error:
                    case DeviceConnector::State::BadDevice:
                    case DeviceConnector::State::Disconnected:
                        handlers.removeAll(hh);
                        delete hh;
                        break;
                }
            });
            found = true;
            break;
        }
    }
    return found;
}

DBusAdapter::~DBusAdapter() {
    qDeleteAll(handlers);
}

DBusAdapter::DBusAdapter(QObject *parent) : QObject(parent), deviceFinder(parent) {
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerService(SERVICE_NAME);
    connection.registerObject(PATH, INTERFACE,this, QDBusConnection::ExportScriptableContents);
}
