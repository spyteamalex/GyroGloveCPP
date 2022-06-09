cmake_minimum_required(VERSION 3.22)
project(GloveMouseCPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/spyteamalex/Qt5.12.12/5.12.12/gcc_64/")

find_package(Qt5 COMPONENTS
        Core
        REQUIRED
        COMPONENTS Bluetooth)

#target_link_libraries(mytarget PRIVATE Qt5::Bluetooth)
SET(SOURCES BLE/device_connector.cpp BLE/device_connector.h BLE/device_finder.cpp BLE/device_finder.h global.h mouse_mover.cpp mouse_mover.h device_handler.cpp device_handler.h decoder.cpp decoder.h quaternion.cpp quaternion.h MouseAdapter.cpp MouseAdapter.h my_math.cpp my_math.h)

add_executable(GloveMouseCPP main.cpp ${SOURCES})
target_link_libraries(GloveMouseCPP
        Qt5::Core
        Qt5::Bluetooth
        )

