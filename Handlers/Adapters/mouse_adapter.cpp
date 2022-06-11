//
// Created by spyteamalex on 09.06.22.
//

#include "mouse_adapter.h"

#define prefix "MouseAdapter"

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

int MouseAdapter::getXScroll(double v) {
    double spd = v * xa_s;
    xDebt_s += spd;
    int mv = (int)xDebt_s;
//    mv = edges(mv, -1, 1)
    xDebt_s -= mv;
    return mv;
}

int MouseAdapter::getYScroll(double v) {
    double spd = v * ya_s;
    yDebt_s += spd;
    int mv = (int)yDebt_s;
//    mv = edges(mv, -1, 1)
    yDebt_s -= mv;
    return mv;
}

void MouseAdapter::setSpeedByQuaternion(const Quaternion &q) {
    double res[3];
    q.quaternion2Euler(res, Quaternion::RotSeq::zxy);
    double x = res[0];
    double y = res[1];
    lastX = edges(x, -xMax_m, xMax_m, -xMin_m, xMin_m);
    lastY = edges(y, -yMax_m, yMax_m, -yMin_m, yMin_m);
}

void MouseAdapter::setSpeed(double x, double y){
    lastX = x;
    lastY = y;
}

void MouseAdapter::loop() {
    if(scrolling){
        m.scroll(getXScroll(lastX), getYScroll(lastY));
    }else {
        m.move(getXSpeed(lastX), getYSpeed(lastY));
    }
}

MouseAdapter::MouseAdapter() {
    connect(&timer, &QTimer::timeout, this, &MouseAdapter::loop);
    timer.setInterval(10);
    timer.start();
}

MouseAdapter::~MouseAdapter() = default;

void MouseAdapter::moveEvent(const Quaternion &q) {
    setSpeedByQuaternion(q);
//    logln(prefix,
//            "move " + tos(q.w()) + " " + tos(q.x()) + " " + tos(q.y()) + " " +
//            tos(q.z()));
}

#define __ 0)||(true
#define CASE(ev, cnt, btn) if((event == (ev)) && (count == (cnt)) && (button == (btn)))
void MouseAdapter::clickEvent(int event, int count, int button) {
    CASE(Decoder::RELEASE, __, 3) {
        setSpeed(0, 0);
    }


    CASE(Decoder::PRESS, 2, 3) {
        scrolling = true;
    }
    CASE(Decoder::RELEASE, 2, 3) {
        scrolling = false;
    }
    CASE(Decoder::PRESS, 3, 3){
        m.key(Mouse::LEFT, true);
    }
    CASE(Decoder::RELEASE, 3, 3){
        m.key(Mouse::LEFT, false);
    }
    CASE(Decoder::CLICK, 1, 3){
        m.key(Mouse::LEFT, true);
        m.key(Mouse::LEFT, false);
    }
    CASE(Decoder::CLICK, 2, 3){
        m.key(Mouse::RIGHT, true);
        m.key(Mouse::RIGHT, false);
    }
    CASE(Decoder::CLICK, 3, 3){
        m.key(Mouse::MIDDLE, true);
        m.key(Mouse::MIDDLE, false);
    }
    logln(prefix, "click " + tos(event) + " " + tos(count) + " " + tos(button));
}
#undef check
#undef __