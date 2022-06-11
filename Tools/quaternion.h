//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_QUATERNION_H
#define GLOVEMOUSECPP_QUATERNION_H
#include <cmath>
#include "../global.h"


class Quaternion {


private:
    double _w,_x,_y,_z;

    static void threeAxisRot(double r11, double r12, double r21, double r31, double r32, double *res);

    static void twoAxisRot(double r11, double r12, double r21, double r31, double r32, double *res);
public:
    [[nodiscard]] double w() const;

    [[nodiscard]] double x() const;

    [[nodiscard]] double y() const;

    [[nodiscard]] double z() const;


    enum RotSeq{zyx, zyz, zxy, zxz, yxz, yxy, yzx, yzy, xyz, xyx, xzy,xzx};

    Quaternion(double w, double x, double y, double z);

    void quaternion2Euler(double *res, RotSeq rotSeq) const;
};


#endif //GLOVEMOUSECPP_QUATERNION_H
