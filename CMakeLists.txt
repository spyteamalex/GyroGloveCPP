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

SET(SOURCES devicehandler.cpp devicehandler.h devicefinder.cpp devicefinder.h global.h)

add_executable(GloveMouseCPP main.cpp ${SOURCES})
target_link_libraries(GloveMouseCPP
        Qt5::Core
        Qt5::Bluetooth
        )

