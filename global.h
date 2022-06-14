#ifndef GYROGLOVECPP_GLOBAL_H
#define GYROGLOVECPP_GLOBAL_H

#include "iostream"
//#define error(prefix, msg) std::cerr << (prefix) << ": " << (msg)
//#define log(prefix, msg) std::clog << (prefix) << ": " << (msg)
//#define print(prefix, msg) std::cout << (prefix) << ": " << (msg)
#define errorln(prefix, msg) std::cerr << (prefix) << ": " << (msg) << std::endl
#define logln(prefix, msg) std::clog << (prefix) << ": " << (msg) << std::endl
#define println(prefix, msg) std::cout << (prefix) << ": " << (msg) << std::endl
#define tos(a) std::to_string(a)

#define SERVICE (quint16)0xFFE0
#define CHARACTERISTIC (quint16)0xFFE1
#define NAME "GloveMouse" //todo change

#define EV_NONE 0
#define EV_CLICK 1
#define EV_PRESS 2
#define EV_RELEASE 3
#define EV_MOVE 4

#define SECTOR_BORDER Qt::transparent
#define SELECTED_SECTOR_BORDER Qt::transparent
#define SECTOR_COLOR QColor::fromRgb(100, 100, 100, 100)
#define SELECTED_SECTOR_COLOR QColor::fromRgb(100, 100, 100, 200)
#define SECTOR_DISTANCE 0.5
#define INNER_RADIUS 225
#define OUTER_RADIUS 325
#define START_ANGLE -90
#define FINISH_ANGLE 270
#define ICON_SIZE QSize(80,80)

#define ID_A 1
#define ID_B 2

#endif //GYROGLOVECPP_GLOBAL_H
