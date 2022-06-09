#include "device_handler.h"

#define prefix device.name().toStdString()

DeviceHandler::DeviceHandler(const QBluetoothDeviceInfo &d, QObject *parent)
        : QObject(parent), connector(nullptr, &d),
          device(d),
          last_ev(std::chrono::system_clock::now()) {
    connect(&connector, &DeviceConnector::dataReceived, this, &DeviceHandler::handle);
}

void DeviceHandler::handle(const QByteArray &value) {
    data += value;
    int i = 0;
    for (; i < data.length();) {
        int type = Decoder::getType(data.cbegin() + i);
        if (type == Decoder::NONE) {
            i++;
        } else if (type == Decoder::MOVE) {
            if (i + 16 < data.length()) {
                Quaternion q = Decoder::decodeQuaternion(data.cbegin() + i);

                long long per = updateTimer();


                println(prefix,
                        "move  " + tos(per) + " " + tos(q.w()) + " " + tos(q.x()) + " " + tos(q.y()) + " " +
                        tos(q.z()));


                i += 17;
            } else break;
        } else if (i + 2 < data.length()) {
            auto res = Decoder::decodeClickDetails(data.cbegin() + i);
            int cnt = res.first;
            int btn = res.second;

            long long per = updateTimer();
            println(prefix, "click " + tos(per) + " " + tos(type) + " " + tos(cnt) + " " + tos(btn));


            i += 3;
        } else break;
    }

    QByteArray data2;
    for (; i < data.length(); i++)
        data2 += data.at(i);
    data = data2;
}

long long DeviceHandler::updateTimer() {
    auto now = std::chrono::system_clock::now();
    long long res = std::chrono::duration_cast<std::chrono::nanoseconds>(now - last_ev).count();
    last_ev = now;
    return res;
}
