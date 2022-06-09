//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_MOUSEADAPTER_H
#define GLOVEMOUSECPP_MOUSEADAPTER_H

#include "my_math.h"
#include "mouse_mover.h"
#include "quaternion.h"
#include "global.h"
#include <cmath>

#define prefix "MouseAdapter"

/**
 * https://askdev.ru/q/suschestvuet-li-algoritm-preobrazovaniya-kvaternionnyh-vrascheniy-v-uglovye-vrascheniya-eylera-112001/
*/

class MouseAdapter {
private:
    static constexpr float xa_m = -939.68;
    static constexpr float ya_m = -939.68;
    static constexpr float xb_m = 2.285;
    static constexpr float yb_m = 2.285;
    static constexpr float yMax_m = 5 * PI / 12;
    static constexpr float yMin_m = 0.02;
    static constexpr float xMax_m = PI / 2;
    static constexpr float xMin_m = 0.02;

    static constexpr float xa_s = -2;
    static constexpr float ya_s = 2;
    static constexpr float yMax_s = 5 * PI / 12;
    static constexpr float yMin_s = 0.02;
    static constexpr float xMax_s = PI / 2;
    static constexpr float xMin_s = 0.02;

    float xDebt_m = 0, yDebt_m = 0;
    float xDebt_s = 0, yDebt_s = 0;
    int xSpeed(float v, long long per);
    int ySpeed(float v, long long per);

    enum RotSeq{zyx, zyz, zxy, zxz, yxz, yxy, yzx, yzy, xyz, xyx, xzy,xzx};

    static void twoAxisRot(double r11, double r12, double r21, double r31, double r32, double res[]);

    static void threeAxisRot(double r11, double r12, double r21, double r31, double r32, double res[]);

    void quaternion2Euler(const Quaternion& q, double res[], RotSeq rotSeq);

    Mouse m;
public:
    MouseAdapter();
    void move(float xAngle, float yAngle, long long period);
};


#endif //GLOVEMOUSECPP_MOUSEADAPTER_H
