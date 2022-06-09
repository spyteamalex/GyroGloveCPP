//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_QUATERNION_H
#define GLOVEMOUSECPP_QUATERNION_H


class Quaternion {


private:
    float _w,_x,_y,_z;
public:
    float w() const;

    float x() const;

    float y() const;

    float z() const;

public:
    Quaternion(float w, float x, float y, float z);


};


#endif //GLOVEMOUSECPP_QUATERNION_H
