//
// Created by spyteamalex on 09.06.22.
//

#include <QPair>
#include "decoder.h"

float ba2f(QByteArray::const_iterator begin){
    float a;
    for(int i = 0; i < 4; i++)
        ((uint8_t*)&a)[i] = *(begin+i);
    return a;
}

Quaternion Decoder::decodeQuaternion(const QByteArray::const_iterator &begin) {
    return {
            ba2f(begin+1),
            ba2f(begin+5),
            ba2f(begin+9),
            ba2f(begin+13)};
}

QPair<int, int> Decoder::decodeClickDetails(const QByteArray::const_iterator &begin) {
    return { *(begin+1), *(begin+2)};
}

int Decoder::getType(const QByteArray::const_iterator &begin) {
    return *begin;
}
