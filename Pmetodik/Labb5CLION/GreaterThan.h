//
// Created by OmarK on 2025-10-21.
//

#ifndef LABB5CLION_GREATERTHAN_H
#define LABB5CLION_GREATERTHAN_H
#include "Car.h"

class GreaterThan {
private:
    double weight;

public:

    GreaterThan(double weight);
    bool operator()(const Car& car);
};


#endif //LABB5CLION_GREATERTHAN_H