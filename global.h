//
// Created by spyteamalex on 09.06.22.
//

#ifndef GLOVEMOUSECPP_GLOBAL_H
#define GLOVEMOUSECPP_GLOBAL_H

#include "iostream"
#define error(msg) std::cerr << msg
#define log(msg) std::clog << msg
#define print(msg) std::cout << msg
#define errorln(msg) std::cerr << msg << std::endl
#define logln(msg) std::clog << msg << std::endl
#define println(msg) std::cout << msg << std::endl

#define SERVICE (quint16)0xFFE0
#define CHARACTERISTIC (quint16)0xFFE1

#endif //GLOVEMOUSECPP_GLOBAL_H
