#include <QApplication>
#include <QLoggingCategory>

#include "BLE/device_finder.h"
#include "BLE/device_connector.h"
#include "global.h"
#include "Handlers/device_handler.h"
#include "Gui/selector_ring.h"
#include "Gui/app.h"

int main(int argc, char *argv[])
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = false"));
    QApplication app(argc, argv);

    auto *m = new Mouse();
    QVector<DeviceHandler*> handlers;
    DeviceFinder deviceFinder;
    DeviceFinder::connect(&deviceFinder, &DeviceFinder::stateChanged, &deviceFinder, [&deviceFinder, &handlers, &m](DeviceFinder::STATE s) {
        if(s == DeviceFinder::STATE::FINISHED){
            for(const auto &i : deviceFinder.getDevices()){
                if(i.name() == QString(NAME)){
                    handlers += new DeviceHandler(i, *m);
                }
            }
        }
    });
    deviceFinder.startSearch();
    App a(nullptr);
    return app.exec();
}
