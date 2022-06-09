#ifndef DEVICEHANDLER_H
#define DEVICEHANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>

#include <QLowEnergyController>
#include <QLowEnergyService>

class DeviceInfo;

class DeviceConnector : public QObject
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

    DeviceConnector(QObject *parent = nullptr, const QBluetoothDeviceInfo *device = nullptr);
    ~DeviceConnector();

    void connectDevice(const QBluetoothDeviceInfo *device);
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
    const QBluetoothDeviceInfo *m_currentDevice = nullptr;
    QLowEnergyController::RemoteAddressType m_addressType = QLowEnergyController::PublicAddress;

    bool m_foundOutput = false;
    std::string prefix;
};

#endif