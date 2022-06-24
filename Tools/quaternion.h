//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_QUATERNION_H
#define GYROGLOVECPP_QUATERNION_H
#include <cmath>
#include <QObject>
#include "../global.h"


class Quaternion : public QObject {
    Q_OBJECT

private:
    double w,x,y,z;

    static void threeAxisRot(double r11, double r12, double r21, double r31, double r32, double *res);

    static void twoAxisRot(double r11, double r12, double r21, double r31, double r32, double *res);
public:
    [[nodiscard]] double getW() const;

    [[nodiscard]] double getX() const;

    [[nodiscard]] double getY() const;

    [[nodiscard]] double getZ() const;


    enum RotSeq{zyx, zyz, zxy, zxz, yxz, yxy, yzx, yzy, xyz, xyx, xzy,xzx};

    Quaternion(QObject *, double w, double x, double y, double z);

    void quaternion2Euler(double *res, RotSeq rotSeq) const;
};


#endif //GYROGLOVECPP_QUATERNION_H
