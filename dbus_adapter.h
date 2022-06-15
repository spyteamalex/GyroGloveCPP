//
// Created by spyteamalex on 15.06.22.
//

#ifndef GYROGLOVECPP_DBUS_ADAPTER_H
#define GYROGLOVECPP_DBUS_ADAPTER_H


#include <QObject>
#include "BLE/device_finder.h"
#include "Handlers/device_handler.h"

class DBusAdapter : QObject {
    Q_OBJECT

private:
    Mouse m;
    QVector<DeviceHandler*> handlers;
    DeviceFinder deviceFinder;

private slots:
    void searchFinished();

signals:
    void messageSent(QString s);


public:
    void connect(const QString& address, bool find = false, int attempts = 2);
    void disconnect(const QString& name);
    void reconnect(const QString& name);

    virtual ~DBusAdapter();
};


#endif //GYROGLOVECPP_DBUS_ADAPTER_H
