#include "device_handler.h"

#define prefix device.name().toStdString()

DeviceHandler::DeviceHandler(const QBluetoothDeviceInfo &d, const Mouse &m, QObject *parent)
        : QObject(parent),
          connector(nullptr, &d),
          device(d),
          adapter(new MouseAdapter(m)){
    connect(&connector, &DeviceConnector::dataReceived, this, &DeviceHandler::handle);
    connect(&connector, &DeviceConnector::stateChanged, this, [this](DeviceConnector::State s){
        emit stateChanged(s);
    });
}

DeviceHandler::~DeviceHandler(){
    connector.disconnectDevice();
    delete adapter;
}

void DeviceHandler::handle(const QByteArray &value) {
    assert(adapter != nullptr);
    data += value;
    int i = 0;
    for (; i < data.length();) {
        int type = Decoder::getType(data.cbegin() + i);
        if (type == EV_NONE) {
            i++;
        } else if (type == EV_MOVE) {
            if (i + 16 < data.length()) {
                Quaternion q = Decoder::decodeQuaternion(data.cbegin() + i);
                adapter->moveEvent(q);
                i += 17;
            } else break;
        } else if (i + 2 < data.length()) {
            auto res = Decoder::decodeClickDetails(data.cbegin() + i);
            int cnt = res.first;
            int btn = res.second;
            adapter->clickEvent(type, cnt, btn);
            i += 3;
        } else break;
    }

    QByteArray data2;
    for (; i < data.length(); i++)
        data2 += data.at(i);
    data = data2;
}

const QBluetoothDeviceInfo &DeviceHandler::getDevice() const {
    return device;
}

void DeviceHandler::disconnectDevice() {
    connector.disconnectDevice();
}

void DeviceHandler::connectDevice() {
    connector.connectDevice();
}

DeviceConnector::State DeviceHandler::getState() const {
    return connector.getState();
}
