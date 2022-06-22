#include <QApplication>
#include <QLoggingCategory>

#include "BLE/device_finder.h"
#include "BLE/device_connector.h"
#include "global.h"
#include "Handlers/device_handler.h"
#include "Gui/selector_ring.h"
#include "dbus_adapter.h"
#include <QStyle>
#include <QDBusConnection>

int main(int argc, char *argv[])
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = false"));
    QApplication app(argc, argv);

    DBusAdapter dBusAdapter;
    dBusAdapter.update();

    return app.exec();
}
