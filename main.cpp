#include <QCoreApplication>
#include <QLoggingCategory>

#include "devicefinder.h"
#include "devicehandler.h"
#include "global.h"

#include <chrono>

int main(int argc, char *argv[])
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    QCoreApplication app(argc, argv);

    DeviceHandler dh;
    DeviceFinder deviceFinder;
    DeviceFinder::connect(&deviceFinder, &DeviceFinder::stateChanged, &deviceFinder, [&deviceFinder, &dh](DeviceFinder::STATE s) {
        if(s == DeviceFinder::STATE::FINISHED){
            for(auto &i : deviceFinder.devices().value<QList<QBluetoothDeviceInfo>>()){
                if(i.address().toString() == QString("00:65:01:0A:45:C2")){
                    DeviceHandler::connect(&dh, &DeviceHandler::dataReceived, &dh, [](const QByteArray& ba){
                        
                    });
                    dh.connectDevice(&i);
                }
            }
        }
    });
    deviceFinder.startSearch();

    //todo расставить каналы
    //https://www.unknowncheats.me/forum/counterstrike-global-offensive/204642-tutorial-simulating-hardware-mouse-event-linux.html
    //https://www.kernel.org/doc/html/v4.12/input/uinput.html

    return app.exec();
}
