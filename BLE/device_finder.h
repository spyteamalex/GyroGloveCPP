#ifndef DEVICEFINDER_H
#define DEVICEFINDER_H

#include <QTimer>
#include <QVariant>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>

class DeviceFinder: public QObject
{
    Q_OBJECT

    Q_PROPERTY(STATE state READ state NOTIFY stateChanged)
//    Q_PROPERTY(QVariant devices READ devices NOTIFY devicesChanged)

public:
    enum class STATE {
        FINISHED,
        ERROR,
        SEARCHING
    };
    Q_ENUM(STATE)

    DeviceFinder(QObject *parent = nullptr);
    ~DeviceFinder();

    const QList<QBluetoothDeviceInfo>& devices();
    STATE state();

public slots:
    void startSearch();

private slots:
    void addDevice(const QBluetoothDeviceInfo&);
    void scanError(const QBluetoothDeviceDiscoveryAgent::Error &error);
    void scanFinished();

signals:
    void stateChanged(STATE);
    void devicesChanged();

private:
    QBluetoothDeviceDiscoveryAgent *m_deviceDiscoveryAgent;
    QList<QBluetoothDeviceInfo> m_devices;

    STATE m_state = STATE::FINISHED;
};

#endif