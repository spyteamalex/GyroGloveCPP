#ifndef DEVICEHANDLER_H
#define DEVICEHANDLER_H

#include <QDateTime>
#include <QTimer>
#include <QVector>

#include <QLowEnergyController>
#include <QLowEnergyService>

class DeviceConnector : public QObject
{
    Q_OBJECT

public:
    enum class AddressType {
        PublicAddress,
        RandomAddress
    };
    enum class State {
        Connected,      //Connection finished
        Disconnected,
        BadDevice,      //Characteristic not found
        ServiceConnected,    //Characteristic found,
        Error
    };
    Q_ENUM(AddressType)
    Q_ENUM(State)

    explicit DeviceConnector(QObject *parent = nullptr, const QBluetoothDeviceInfo *device = nullptr);
    ~DeviceConnector() override;

    void connectDevice();
    void setAddressType(AddressType type);
    [[nodiscard]] AddressType getAddressType() const;
    [[nodiscard]] State getState() const;
    void disconnectDevice();

signals:
    void stateChanged(State);
    void dataReceived(const QByteArray&);

private slots:
    void serviceDiscovered(const QBluetoothUuid &);
    void serviceScanDone();

    void serviceStateChanged(QLowEnergyService::ServiceState s);
    void receiveData(const QLowEnergyCharacteristic &c,
                     const QByteArray &value);
    void confirmedDescriptorWrite(const QLowEnergyDescriptor &d,
                              const QByteArray &value);

private:

    QLowEnergyController *control = nullptr;
    QLowEnergyService *service = nullptr;
    QLowEnergyDescriptor notificationDesc;
    const QBluetoothDeviceInfo *currentDevice = nullptr;
    QLowEnergyController::RemoteAddressType _addressType = QLowEnergyController::PublicAddress;

    bool foundOutput = false;
    State state = State::Disconnected;
    const QBluetoothDeviceInfo* device;

    void setState(State s);
};

#endif