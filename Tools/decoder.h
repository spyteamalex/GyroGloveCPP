//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_DECODER_H
#define GYROGLOVECPP_DECODER_H


#include <QByteArray>
#include "quaternion.h"
#include <QPair>

class Decoder {
public:
    static const uint8_t NONE = 0;
    static const uint8_t CLICK = 1;
    static const uint8_t PRESS = 2;
    static const uint8_t RELEASE = 3;
    static const uint8_t MOVE = 4;


    static int getType(const QByteArray::const_iterator &begin);

    static Quaternion decodeQuaternion(const QByteArray::const_iterator &begin);

    static QPair<int, int> decodeClickDetails(const QByteArray::const_iterator &begin);

private:
    static int32_t ba2i32(const char *begin);
};


#endif //GYROGLOVECPP_DECODER_H
