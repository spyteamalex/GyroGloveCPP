//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_MY_MATH_H
#define GYROGLOVECPP_MY_MATH_H

#define PI 3.14159265358979323846

#define sign(x) (((x) > 0) - ((x) < 0))

#include <cmath>
#define edges(x, l, r, ld, rd) (((ld) <= (x) && (x) <= (rd)) ? 0 : std::max((l), std::min((r), (x))))


#endif //GYROGLOVECPP_MY_MATH_H
