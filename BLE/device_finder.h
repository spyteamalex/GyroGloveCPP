#ifndef DEVICEFINDER_H
#define DEVICEFINDER_H

#include <QTimer>
#include <QVariant>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>

class DeviceFinder: public QObject
{
    Q_OBJECT

    Q_PROPERTY(STATE getState READ getState NOTIFY stateChanged)
//    Q_PROPERTY(QVariant devices READ getDevices NOTIFY devicesChanged)

public:
    enum class STATE {
        FINISHED,
        ERROR,
        SEARCHING
    };
    Q_ENUM(STATE)

    DeviceFinder(QObject *parent = nullptr);
    ~DeviceFinder();

    const QList<QBluetoothDeviceInfo>& getDevices();
    STATE getState();

public slots:
    void startSearch();

private slots:
    void addDevice(const QBluetoothDeviceInfo&);
    void scanError(const QBluetoothDeviceDiscoveryAgent::Error &error);
    void scanFinished();

signals:
    void stateChanged(DeviceFinder::STATE);
    void devicesChanged();

private:
    QBluetoothDeviceDiscoveryAgent *deviceDiscoveryAgent;
    QList<QBluetoothDeviceInfo> devices;

    STATE state = STATE::FINISHED;
};

#endif