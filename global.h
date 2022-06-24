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
#define DEVICE_NAME "GloveMouse" //todo change

#define EV_NONE 0
#define EV_CLICK 1
#define EV_PRESS 2
#define EV_RELEASE 3
#define EV_MOVE 4

//#define SECTOR_BORDER_DEFAULT Qt::transparent
//#define SELECTED_SECTOR_BORDER_DEFAULT Qt::transparent
//#define SECTOR_COLOR_DEFAULT QColor::fromRgb(100, 100, 100, 100)
//#define SELECTED_SECTOR_COLOR_DEFAULT QColor::fromRgb(100, 100, 100, 200)
//#define SECTOR_DISTANCE_DEFAULT (0.5)
//#define INNER_RADIUS_DEFAULT (225)
//#define OUTER_RADIUS_DEFAULT (325)
//#define START_ANGLE_DEFAULT (-90)
//#define FINISH_ANGLE_DEFAULT (270)
//#define ICON_HEIGHT_DEFAULT (60)
//#define ICON_WIDTH_DEFAULT (60)

#define SECTOR_BORDER_DEFAULT QColor::fromRgb(0,0,0)
#define SELECTED_SECTOR_BORDER_DEFAULT QColor::fromRgb(255,255,255)
#define SECTOR_COLOR_DEFAULT QColor::fromRgb(0,0,0)
#define SELECTED_SECTOR_COLOR_DEFAULT QColor::fromRgb(255,255,255)
#define SECTOR_DISTANCE_DEFAULT (0)
#define INNER_RADIUS_DEFAULT (0)
#define OUTER_RADIUS_DEFAULT (325)
#define START_ANGLE_DEFAULT (0)
#define FINISH_ANGLE_DEFAULT (360)
#define ICON_HEIGHT_DEFAULT (40)
#define ICON_WIDTH_DEFAULT (40)

#define CONFIG "/etc/opt/gyroglove/config.json"
#define SERVICE_NAME "org.spyteamalex.GyroGlove"
#define PATH "/org/spyteamalex/GyroGlove"
#define INTERFACE "org.spyteamalex.GyroGlove"

#define XA_M_DEFAULT (-939.68)
#define YA_M_DEFAULT (-939.68)
#define XB_M_DEFAULT (2.285)
#define YB_M_DEFAULT (2.285)

#define XA_S_DEFAULT (-46.984)
#define YA_S_DEFAULT (46.984)
#define XB_S_DEFAULT (2.285)
#define YB_S_DEFAULT (2.285)

#define DX_SEL_DEFAULT (-0.1)
#define DY_SEL_DEFAULT (-0.1)

#define ID_A 1
#define ID_B 2

#endif //GYROGLOVECPP_GLOBAL_H
