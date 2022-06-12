//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_MOUSE_ADAPTER_H
#define GYROGLOVECPP_MOUSE_ADAPTER_H

#include "../../Tools/my_math.h"
#include "../../Tools/mouse_mover.h"
#include "../../Tools/quaternion.h"
#include "../../Tools/decoder.h"
#include "../../global.h"
#include "adapter.h"
#include <cmath>
#include <QTimer>

/**
 * https://askdev.ru/q/suschestvuet-li-algoritm-preobrazovaniya-kvaternionnyh-vrascheniy-v-uglovye-vrascheniya-eylera-112001/
*/

class MouseAdapter: public QObject, public Adapter{
    Q_OBJECT
private:
    QTimer timer;

    //Константы движения курсора
    static constexpr double xa_m = -939.68;
    static constexpr double ya_m = -939.68;
    static constexpr double xb_m = 2.285;
    static constexpr double yb_m = 2.285;
//    static constexpr double yMax_m = 5 * PI / 12;
//    static constexpr double yMin_m = 0.01;
//    static constexpr double xMax_m = PI / 2;
//    static constexpr double xMin_m = 0.01;

    //Константы скролла
    static constexpr double xa_s = -9.3968*5;
    static constexpr double ya_s = -9.3968*5;
    static constexpr double xb_s = 2.285;
    static constexpr double yb_s = 2.285;
//    static constexpr double yMax_s = 5 * PI / 12;
//    static constexpr double yMin_s = 0.01;
//    static constexpr double xMax_s = PI / 2;
//    static constexpr double xMin_s = 0.01;

    bool scrolling = false;
    double xDebt_m = 0, yDebt_m = 0;
    double xDebt_s = 0, yDebt_s = 0;
    int getXSpeed(double v);
    int getYSpeed(double v);
    int getXScroll(double v);
    int getYScroll(double v);

    const Mouse &m;
    double lastX = 0, lastY = 0;

private slots:
    void loop();
public:
    MouseAdapter(const Mouse &m);

    ~MouseAdapter();

    void setSpeedByQuaternion(const Quaternion &q);

    void setSpeed(double x, double y);

    void moveEvent(const Quaternion &quaternion) override;

    void clickEvent(int event, int count, int button) override;
};


#endif //GYROGLOVECPP_MOUSE_ADAPTER_H
