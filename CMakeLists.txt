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
SET(SOURCES BLE/device_connector.cpp BLE/device_connector.h BLE/device_finder.cpp BLE/device_finder.h global.h Tools/mouse_mover.cpp Tools/mouse_mover.h Handlers/device_handler.cpp Handlers/device_handler.h Tools/decoder.cpp Tools/decoder.h Tools/quaternion.cpp Tools/quaternion.h Handlers/Adapters/mouse_adapter.cpp Handlers/Adapters/mouse_adapter.h Tools/my_math.cpp Tools/my_math.h Handlers/Adapters/adapter.h)

add_executable(GloveMouseCPP main.cpp ${SOURCES})
target_link_libraries(GloveMouseCPP
        Qt5::Core
        Qt5::Bluetooth
        )

