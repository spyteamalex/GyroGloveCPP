//
// Created by spyteamalex on 15.06.22.
//

#include "dbus_adapter.h"

void DBusAdapter::reconnect(const QString& name) {

}

void DBusAdapter::connect(const QString& address, bool find, int attempts) {
    if(attempts < 1) {
        emit messageSent("Device with address "+address+" not found. Connecting...");
        return;
    }
    if(find){
        auto * const connection = new QMetaObject::Connection;
        *connection = DeviceFinder::connect(&deviceFinder, &DeviceFinder::stateChanged, &deviceFinder, [&connection, this, &address, attempts](DeviceFinder::STATE s) {
            if(s == DeviceFinder::STATE::FINISHED){
                QObject::disconnect(*connection);
                delete connection;
                connect(address, false, attempts);
            }
        });
        deviceFinder.startSearch();
    }else{
        bool found = false;
        for(const auto &i : deviceFinder.getDevices()){
            if(i.address().toString() == address){
                auto *hh = new DeviceHandler(i, m);
                handlers += hh;
                hh->connectDevice();
                DeviceHandler::connect(hh, &DeviceHandler::stateChanged, this, [](){
                    //todo
                });
                found = true;
                break;
            }
        }
        if(found){
            emit messageSent("Device with address "+address+" found. Connecting...");
        }else{
            connect(address, true, attempts-1);
        }
    }
}

void DBusAdapter::disconnect(const QString& name) {
    //todo
}

void DBusAdapter::searchFinished() {
    //todo
}

DBusAdapter::~DBusAdapter() {
    qDeleteAll(handlers);
}
