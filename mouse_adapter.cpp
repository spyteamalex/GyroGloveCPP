//
// Created by spyteamalex on 09.06.22.
//

#include "mouse_adapter.h"

int MouseAdapter::getXSpeed(double v) {
    double spd = sign(v) * xa_m * std::pow(std::abs(v), xb_m);
    xDebt_m += spd;
    int mv = (int)xDebt_m;
    xDebt_m -= (double)mv;
    return mv;
}

int MouseAdapter::getYSpeed(double v) {
    double spd = sign(v) * ya_m * std::pow(std::abs(v), yb_m);
    yDebt_m += spd;
    int mv = (int)yDebt_m;
    yDebt_m -= (double)mv;
    return mv;
}

void MouseAdapter::setSpeedByQuaternion(const Quaternion &q) {
    double res[3];
    q.quaternion2Euler(res, Quaternion::RotSeq::zxy);
    double x = res[0];
    double y = res[1];
    lastX = edges(x, -xMax_m, xMax_m, -xMin_m, xMin_m);
    lastY = edges(y, -yMax_m, yMax_m, -yMin_m, yMin_m);
//    println(getXSpeed(x, period), getYSpeed(y, period));
//    xSpeed = getXSpeed(x, period);
//    ySpeed = getYSpeed(y, period);
//    m.move(getXSpeed(x, period), getYSpeed(y, period));
}

void MouseAdapter::setSpeed(double x, double y){
    lastX = x;
    lastY = y;
}

void MouseAdapter::loop() {
    m.move(getXSpeed(lastX), getYSpeed(lastY));
}

MouseAdapter::MouseAdapter() {
    connect(&timer, &QTimer::timeout, this, &MouseAdapter::loop);
    timer.setInterval(10);
    timer.start();
}
