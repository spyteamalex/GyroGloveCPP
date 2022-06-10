#ifndef GLOVEMOUSECPP_DEVICE_HANDLER_H
#define GLOVEMOUSECPP_DEVICE_HANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>
#include <QBluetoothDeviceInfo>
#include "BLE/device_connector.h"
#include "global.h"
#include "decoder.h"
#include "mouse_adapter.h"
#include <chrono>

class DeviceHandler : public QObject
{

Q_OBJECT

public:
    DeviceHandler(const QBluetoothDeviceInfo&, QObject * = nullptr);
    ~DeviceHandler();

private slots:
    void handle(const QByteArray &value);

private:
    MouseAdapter *ma = nullptr;
    DeviceConnector connector;
    const QBluetoothDeviceInfo &device;
    QByteArray data;
};


#endif //GLOVEMOUSECPP_DEVICE_HANDLER_H
