//
// Created by spyteamalex on 15.06.22.
//

#ifndef GYROGLOVECPP_DBUS_ADAPTER_H
#define GYROGLOVECPP_DBUS_ADAPTER_H


#include <QObject>
#include "BLE/device_finder.h"
#include "Handlers/device_handler.h"
#include <QDBusConnection>

#define prefix "DBusAdapter"

class DBusAdapter : public QObject {
    Q_OBJECT

private:
    Mouse m;
    QVector<DeviceHandler*> handlers;
    DeviceFinder deviceFinder;
    bool tryConnect(const QBluetoothAddress& address);

public:
signals:
    Q_SCRIPTABLE void messageSent(QString s);

public slots:
    Q_SCRIPTABLE void update();
    Q_SCRIPTABLE void disconnectAll();
    Q_SCRIPTABLE QString getDevices();
public:
    explicit DBusAdapter(QObject *parent = nullptr);
    ~DBusAdapter() override;
};


#endif //GYROGLOVECPP_DBUS_ADAPTER_H
