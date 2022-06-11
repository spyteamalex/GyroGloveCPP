//
// Created by spyteamalex on 09.06.22.
//

#include "decoder.h"

int32_t Decoder::ba2i32(QByteArray::const_iterator begin){
    int32_t a;
    for(int i = 0; i < 4; i++)
        ((uint8_t*)&a)[i] = *(begin+i);
    return a;
}

Quaternion Decoder::decodeQuaternion(const QByteArray::const_iterator &begin) {
    return {
            ba2i32(begin + 1) / 100000000.0,
            ba2i32(begin + 5) / 100000000.0,
            ba2i32(begin + 9) / 100000000.0,
            ba2i32(begin + 13) / 100000000.0
    };
}

QPair<int, int> Decoder::decodeClickDetails(const QByteArray::const_iterator &begin) {
    return { *(begin+1), *(begin+2)};
}

int Decoder::getType(const QByteArray::const_iterator &begin) {
    return *begin;
}
