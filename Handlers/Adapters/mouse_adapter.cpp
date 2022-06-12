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
    double spd = sign(v) * xa_s * std::pow(std::abs(v), xb_s);
    xDebt_s += spd;
    int mv = (int)xDebt_s;
    xDebt_s -= mv;
    return mv;
}

int MouseAdapter::getYScroll(double v) {
    double spd = sign(v) * ya_s * std::pow(std::abs(v), yb_s);
    yDebt_s += spd;
    int mv = (int)yDebt_s;
    yDebt_s -= mv;
    return mv;
}

void MouseAdapter::setSpeedByQuaternion(const Quaternion &q) {
    double res[3];
    q.quaternion2Euler(res, Quaternion::RotSeq::zxy);
    double x = res[0];
    double y = res[1];
    lastX = x;
    lastY = y;
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

MouseAdapter::MouseAdapter(const Mouse& m) : m(m) {
    connect(&timer, &QTimer::timeout, this, &MouseAdapter::loop);
    timer.setInterval(10);
    timer.start();
}

MouseAdapter::~MouseAdapter() = default;

void MouseAdapter::moveEvent(const Quaternion &q) {
    setSpeedByQuaternion(q);
//    logln(prefix,
//            "move " + tos(q.getWidth()) + " " + tos(q.getX()) + " " + tos(q.getY()) + " " +
//            tos(q.getZ()));
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
        m.setKey(Mouse::LEFT, true);
    }
    CASE(Decoder::RELEASE, 3, 3){
        m.setKey(Mouse::LEFT, false);
    }
    CASE(Decoder::CLICK, 1, 3){
        m.setKey(Mouse::LEFT, true);
        m.setKey(Mouse::LEFT, false);
    }
    CASE(Decoder::CLICK, 2, 3){
        m.setKey(Mouse::RIGHT, true);
        m.setKey(Mouse::RIGHT, false);
    }
    CASE(Decoder::CLICK, 3, 3){
        m.setKey(Mouse::MIDDLE, true);
        m.setKey(Mouse::MIDDLE, false);
    }
    logln(prefix, "click " + tos(event) + " " + tos(count) + " " + tos(button));
}
#undef check
#undef __