//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_MY_MATH_H
#define GLOVEMOUSECPP_MY_MATH_H

#define PI 3.14159265358979323846

#define sign(x) (x > 0) - (x < 0)

#define edges(x, l, r, ld, rd) do {\
if (ld <= x && x <= rd){           \
return 0;                          \
}                                  \
return std::max(l, std::min(r, x)); \
}


#endif //GLOVEMOUSECPP_MY_MATH_H
