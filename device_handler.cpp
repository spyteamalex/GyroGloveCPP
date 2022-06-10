#include "device_handler.h"

#define prefix device.name().toStdString()

DeviceHandler::DeviceHandler(const QBluetoothDeviceInfo &d, QObject *parent)
        : QObject(parent), connector(nullptr, &d),
          device(d),
          ma(new MouseAdapter()) {
    connect(&connector, &DeviceConnector::dataReceived, this, &DeviceHandler::handle);
}

DeviceHandler::~DeviceHandler(){
    delete ma;
}

void DeviceHandler::handle(const QByteArray &value) {
    assert(ma != nullptr);
    data += value;
    int i = 0;
    for (; i < data.length();) {
        int type = Decoder::getType(data.cbegin() + i);
        if (type == Decoder::NONE) {
            i++;
            logln(prefix, "skip");
        } else if (type == Decoder::MOVE) {
            if (i + 16 < data.length()) {
                Quaternion q = Decoder::decodeQuaternion(data.cbegin() + i);
                ma->setSpeedByQuaternion(q);
                logln(prefix,
                        "move  " + tos(q.w()) + " " + tos(q.x()) + " " + tos(q.y()) + " " +
                        tos(q.z()));
                i += 17;
            } else break;
        } else if (i + 2 < data.length()) {
            auto res = Decoder::decodeClickDetails(data.cbegin() + i);
            int cnt = res.first;
            int btn = res.second;



            if(type == Decoder::RELEASE && btn == 3) {
                ma->setSpeed(0,0);
            }
            logln(prefix, "click " + tos(type) + " " + tos(cnt) + " " + tos(btn));


            i += 3;
        } else break;
    }

    QByteArray data2;
    for (; i < data.length(); i++)
        data2 += data.at(i);
    data = data2;
}