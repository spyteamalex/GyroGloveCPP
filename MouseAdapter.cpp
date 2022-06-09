//
// Created by spyteamalex on 09.06.22.
//

#include "MouseAdapter.h"

int MouseAdapter::xSpeed(float v, long long per) {
    float spd = sign(v) * per * 10E-7 * xa_m * std::pow(std::abs(v), xb_m);
    xDebt_m += spd;
    int mv = int(xDebt_m);
    xDebt_m -= (float)mv;
    return mv;
}

int MouseAdapter::ySpeed(float v, long long per) {
    float spd = sign(v) * per * 10E-7 * ya_m * std::pow(std::abs(v), yb_m);
    yDebt_m += spd;
    int mv = int(yDebt_m);
    yDebt_m -= (float)mv;
    return mv;
}

void MouseAdapter::move(const Quaternion &q, long long period) {
    double res[3];
    quaternion2Euler(q, res, RotSeq::zxy);
    double x = res[0];
    x = edges(x, -xMax, xMax, -xMin, xMin);
    m.move(xSpeed(x, period), ySpeed(yAngle, period));
}

MouseAdapter::MouseAdapter() = default;
