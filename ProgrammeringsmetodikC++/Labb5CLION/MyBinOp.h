//
// Created by OmarK on 2025-10-21.
//

#ifndef LABB5CLION_MYBINOP_H
#define LABB5CLION_MYBINOP_H
#include "Car.h"

class MyBinOp {
public:
    double operator()(double weight, const Car& car);

};


#endif //LABB5CLION_MYBINOP_H