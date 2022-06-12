//
// Created by spyteamalex on 09.06.22.
//

#ifndef GYROGLOVECPP_GLOBAL_H
#define GYROGLOVECPP_GLOBAL_H

#include "iostream"
//#define error(prefix, msg) std::cerr << (prefix) << ": " << (msg)
//#define log(prefix, msg) std::clog << (prefix) << ": " << (msg)
//#define print(prefix, msg) std::cout << (prefix) << ": " << (msg)
#define errorln(prefix, msg) std::cerr << (prefix) << ": " << (msg) << std::endl
#define logln(prefix, msg) std::clog << (prefix) << ": " << (msg) << std::endl
#define println(prefix, msg) std::cout << (prefix) << ": " << (msg) << std::endl
#define tos(a) std::to_string(a)

#define SERVICE (quint16)0xFFE0
#define CHARACTERISTIC (quint16)0xFFE1
#define NAME "GyroGlove"

#endif //GYROGLOVECPP_GLOBAL_H
