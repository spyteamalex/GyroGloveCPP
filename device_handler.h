#ifndef GLOVEMOUSECPP_DEVICE_HANDLER_H
#define GLOVEMOUSECPP_DEVICE_HANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>
#include <QBluetoothDeviceInfo>
#include "BLE/device_connector.h"
#include "global.h"
#include "decoder.h"
#include <chrono>

class DeviceHandler : public QObject
{

Q_OBJECT

public:
    DeviceHandler(const QBluetoothDeviceInfo&, QObject * = nullptr);

private slots:
    void handle(const QByteArray &value);

private:
    DeviceConnector connector;
    const QBluetoothDeviceInfo &device;
    QByteArray data;
    std::chrono::time_point<std::chrono::system_clock> last_ev;

    long long updateTimer();
};


#endif //GLOVEMOUSECPP_DEVICE_HANDLER_H
