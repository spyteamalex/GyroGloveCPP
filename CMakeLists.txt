cmake_minimum_required(VERSION 3.22)
project(GyroGloveCPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/spyteamalex/Qt5.12.12/5.12.12/gcc_64/")

find_package(Qt5 COMPONENTS
        Core
        REQUIRED
        COMPONENTS Bluetooth Gui Widgets DBus)

#target_link_libraries(mytarget PRIVATE Qt5::Bluetooth)
SET(SOURCES
        BLE/device_connector.cpp
        BLE/device_connector.h
        BLE/device_finder.cpp
        BLE/device_finder.h
        global.h
        Tools/mouse_mover.cpp
        Tools/mouse_mover.h
        Handlers/device_handler.cpp
        Handlers/device_handler.h
        Tools/decoder.cpp
        Tools/decoder.h
        Tools/quaternion.cpp
        Tools/quaternion.h
        Handlers/mouse_adapter.cpp
        Handlers/mouse_adapter.h
        Tools/my_math.cpp
        Tools/my_math.h
        Handlers/adapter.h
        Gui/selector_ring.cpp
        Gui/selector_ring.h
        Tools/tools.h
        Tools/tools.cpp
        dbus_adapter.cpp
        dbus_adapter.h app.cpp app.h)

add_executable(GyroGloveCPP main.cpp ${SOURCES})
target_link_libraries(GyroGloveCPP
        Qt5::Core
        Qt5::Bluetooth
        Qt5::Gui
        Qt5::Widgets
        Qt5::DBus
        )

