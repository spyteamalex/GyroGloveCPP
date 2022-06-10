//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_MOUSE_ADAPTER_H
#define GLOVEMOUSECPP_MOUSE_ADAPTER_H

#include "my_math.h"
#include "mouse_mover.h"
#include "quaternion.h"
#include "global.h"
#include <cmath>
#include <QTimer>

#define prefix "MouseAdapter"

/**
 * https://askdev.ru/q/suschestvuet-li-algoritm-preobrazovaniya-kvaternionnyh-vrascheniy-v-uglovye-vrascheniya-eylera-112001/
*/

class MouseAdapter: public QObject {
    Q_OBJECT
private:
    QTimer timer;
    static constexpr double xa_m = -939.68;
    static constexpr double ya_m = -939.68;
    static constexpr double xb_m = 2.285;
    static constexpr double yb_m = 2.285;
    static constexpr double yMax_m = 5 * PI / 12;
    static constexpr double yMin_m = 0.01;
    static constexpr double xMax_m = PI / 2;
    static constexpr double xMin_m = 0.01;

    static constexpr double xa_s = -2;
    static constexpr double ya_s = 2;
    static constexpr double yMax_s = 5 * PI / 12;
    static constexpr double yMin_s = 0.02;
    static constexpr double xMax_s = PI / 2;
    static constexpr double xMin_s = 0.02;

    double xDebt_m = 0, yDebt_m = 0;
    double xDebt_s = 0, yDebt_s = 0;
    int getXSpeed(double v);
    int getYSpeed(double v);

    Mouse m;
    double lastX = 0, lastY = 0;

private slots:
    void loop();
public:
    MouseAdapter();
    void setSpeedByQuaternion(const Quaternion &q);

    void setSpeed(double x, double y);
};


#endif //GLOVEMOUSECPP_MOUSE_ADAPTER_H
