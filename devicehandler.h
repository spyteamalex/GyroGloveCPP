#ifndef DEVICEHANDLER_H
#define DEVICEHANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>

#include <QLowEnergyController>
#include <QLowEnergyService>

class DeviceInfo;

class DeviceHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool alive READ alive NOTIFY aliveChanged)
    Q_PROPERTY(AddressType addressType READ addressType WRITE setAddressType)
    Q_PROPERTY(QByteArray data NOTIFY dataReceived)

public:
    enum class AddressType {
        PublicAddress,
        RandomAddress
    };
    Q_ENUM(AddressType)

    DeviceHandler(QObject *parent = nullptr);
    ~DeviceHandler();

    void connectDevice(QBluetoothDeviceInfo *device);
    void setAddressType(AddressType type);
    AddressType addressType() const;

    bool alive() const;
signals:
    void aliveChanged();
    void dataReceived(const QByteArray&);

public slots:
    void disconnectService();

private slots:
    void serviceDiscovered(const QBluetoothUuid &);
    void serviceScanDone();

    void serviceStateChanged(QLowEnergyService::ServiceState s);
    void receiveData(const QLowEnergyCharacteristic &c,
                     const QByteArray &value);
    void confirmedDescriptorWrite(const QLowEnergyDescriptor &d,
                              const QByteArray &value);

private:

    QLowEnergyController *m_control = nullptr;
    QLowEnergyService *m_service = nullptr;
    QLowEnergyDescriptor m_notificationDesc;
    QBluetoothDeviceInfo *m_currentDevice = nullptr;
    QLowEnergyController::RemoteAddressType m_addressType = QLowEnergyController::PublicAddress;

    bool m_foundOutput = false;
};

#endif