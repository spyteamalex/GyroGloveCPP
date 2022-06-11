#ifndef GLOVEMOUSECPP_DEVICE_HANDLER_H
#define GLOVEMOUSECPP_DEVICE_HANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>
#include <QBluetoothDeviceInfo>
#include "../BLE/device_connector.h"
#include "../global.h"
#include "../Tools/decoder.h"
#include "Adapters/mouse_adapter.h"
#include <chrono>

class DeviceHandler : public QObject
{

Q_OBJECT

public:
    explicit DeviceHandler(const QBluetoothDeviceInfo&, QObject * = nullptr);
    ~DeviceHandler() override;

private slots:
    void handle(const QByteArray &value);

private:
    DeviceConnector connector;
    const QBluetoothDeviceInfo &device;
    QByteArray data;
    Adapter *adapter;
};


#endif //GLOVEMOUSECPP_DEVICE_HANDLER_H
