#include <QCoreApplication>
#include <QLoggingCategory>

#include "BLE/device_finder.h"
#include "BLE/device_connector.h"
#include "global.h"
#include "mouse_mover.h"
#include "device_handler.h"

#include <chrono>

int main(int argc, char *argv[])
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = false"));
    QCoreApplication app(argc, argv);

    QVector<DeviceHandler*> handlers;
    DeviceFinder deviceFinder;
    DeviceFinder::connect(&deviceFinder, &DeviceFinder::stateChanged, &deviceFinder, [&deviceFinder, &handlers](DeviceFinder::STATE s) {
        if(s == DeviceFinder::STATE::FINISHED){
            for(const auto &i : deviceFinder.devices()){
                if(i.name() == QString(NAME)){
                    handlers += new DeviceHandler(i);
                }
            }
        }
    });
    deviceFinder.startSearch();
    return app.exec();

//    todo расставить каналы
//    https://www.unknowncheats.me/forum/counterstrike-global-offensive/204642-tutorial-simulating-hardware-mouse-event-linux.html
//    https://www.kernel.org/doc/html/v4.12/input/uinput.html

//    Mouse m;
//    m.move(1,1);

    return 0;
}
