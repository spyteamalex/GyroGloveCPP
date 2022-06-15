#ifndef GYROGLOVECPP_DEVICE_HANDLER_H
#define GYROGLOVECPP_DEVICE_HANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>
#include <QBluetoothDeviceInfo>
#include "../BLE/device_connector.h"
#include "../global.h"
#include "../Tools/decoder.h"
#include "mouse_adapter.h"
#include <chrono>

class DeviceHandler : public QObject{

Q_OBJECT

public:
    explicit DeviceHandler(const QBluetoothDeviceInfo&, const Mouse& m, QObject * = nullptr);
    ~DeviceHandler() override;
    [[nodiscard]] const QBluetoothDeviceInfo &getDevice() const;
    void connectDevice();
    void disconnectDevice();
    [[nodiscard]] DeviceConnector::State getState() const;

signals:
    void stateChanged(DeviceConnector::State s);

private slots:
    void handle(const QByteArray &value);

private:
    DeviceConnector connector;
    const QBluetoothDeviceInfo &device;
    QByteArray data;
    Adapter *adapter{};
};


#endif //GYROGLOVECPP_DEVICE_HANDLER_H
