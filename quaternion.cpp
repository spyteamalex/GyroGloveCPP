//
// Created by spyteamalex on 09.06.22.
//

#include "quaternion.h"

Quaternion::Quaternion(float w, float x, float y, float z) : _w(w), _x(x), _y(y), _z(z) {}

float Quaternion::w() const {
    return _w;
}

float Quaternion::x() const {
    return _x;
}

float Quaternion::y() const {
    return _y;
}

float Quaternion::z() const {
    return _z;
}
