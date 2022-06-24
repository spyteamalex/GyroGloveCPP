//
// Created by spyteamalex on 09.06.22.
//

#include "quaternion.h"

#define prefix "Quaternion"

Quaternion::Quaternion(QObject * parent, double w, double x, double y, double z) : w(w), x(x), y(y), z(z), QObject(parent) {}

double Quaternion::getW() const {
    return w;
}

double Quaternion::getX() const {
    return x;
}

double Quaternion::getY() const {
    return y;
}

double Quaternion::getZ() const {
    return z;
}

void Quaternion::twoAxisRot(double r11, double r12, double r21, double r31, double r32, double res[]){
    res[0] = atan2( r11, r12 );
    res[1] = acos ( r21 );
    res[2] = atan2( r31, r32 );
}

void Quaternion::threeAxisRot(double r11, double r12, double r21, double r31, double r32, double res[]){
    res[0] = atan2( r31, r32 );
    res[1] = asin ( r21 );
    res[2] = atan2( r11, r12 );
}

void Quaternion::quaternion2Euler(double res[], RotSeq rotSeq) const{
    switch(rotSeq){
        case zyx:
            threeAxisRot( 2*(x * y + w * z),
                          w * w + x * x - y * y - z * z,
                          -2*(x * z - w * y),
                          2*(y * z + w * x),
                          w * w - x * x - y * y + z * z,
                          res);
            break;

        case zyz:
            twoAxisRot(2 * (y * z - w * x),
                       2 * (x * z + w * y),
                       w * w - x * x - y * y + z * z,
                       2 * (y * z + w * x),
                       -2 * (x * z - w * y),
                       res);
            break;

        case zxy:
            threeAxisRot( -2*(x * y - w * z),
                          w * w - x * x + y * y - z * z,
                          2*(y * z + w * x),
                          -2*(x * z - w * y),
                          w * w - x * x - y * y + z * z,
                          res);
            break;

        case zxz:
            twoAxisRot(2 * (x * z + w * y),
                       -2 * (y * z - w * x),
                       w * w - x * x - y * y + z * z,
                       2 * (x * z - w * y),
                       2 * (y * z + w * x),
                       res);
            break;

        case yxz:
            threeAxisRot( 2*(x * z + w * y),
                          w * w - x * x - y * y + z * z,
                          -2*(y * z - w * x),
                          2*(x * y + w * z),
                          w * w - x * x + y * y - z * z,
                          res);
            break;

        case yxy:
            twoAxisRot(2 * (x * y - w * z),
                       2 * (y * z + w * x),
                       w * w - x * x + y * y - z * z,
                       2 * (x * y + w * z),
                       -2 * (y * z - w * x),
                       res);
            break;

        case yzx:
            threeAxisRot( -2*(x * z - w * y),
                          w * w + x * x - y * y - z * z,
                          2*(x * y + w * z),
                          -2*(y * z - w * x),
                          w * w - x * x + y * y - z * z,
                          res);
            break;

        case yzy:
            twoAxisRot(2 * (y * z + w * x),
                       -2 * (x * y - w * z),
                       w * w - x * x + y * y - z * z,
                       2 * (y * z - w * x),
                       2 * (x * y + w * z),
                       res);
            break;

        case xyz:
            threeAxisRot( -2*(y * z - w * x),
                          w * w - x * x - y * y + z * z,
                          2*(x * z + w * y),
                          -2*(x * y - w * z),
                          w * w + x * x - y * y - z * z,
                          res);
            break;

        case xyx:
            twoAxisRot(2 * (x * y + w * z),
                       -2 * (x * z - w * y),
                       w * w + x * x - y * y - z * z,
                       2 * (x * y - w * z),
                       2 * (x * z + w * y),
                       res);
            break;

        case xzy:
            threeAxisRot( 2*(y * z + w * x),
                          w * w - x * x + y * y - z * z,
                          -2*(x * y - w * z),
                          2*(x * z + w * y),
                          w * w + x * x - y * y - z * z,
                          res);
            break;

        case xzx:
            twoAxisRot(2 * (x * z - w * y),
                       2 * (x * y + w * z),
                       w * w + x * x - y * y - z * z,
                       2 * (x * z + w * y),
                       -2 * (x * y - w * z),
                       res);
            break;
        default:
            errorln(prefix, "Unknown rotation sequence");
            break;
    }
}
