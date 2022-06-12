//
// Created by spyteamalex on 11.06.22.
//

#ifndef GYROGLOVECPP_ADAPTER_H
#define GYROGLOVECPP_ADAPTER_H


#include "../../Tools/quaternion.h"

class Adapter {
public:
    virtual void moveEvent(const Quaternion&) = 0;
    virtual void clickEvent(int event, int count, int button) = 0;
    virtual ~Adapter() = default;;
};


#endif //GYROGLOVECPP_ADAPTER_H
