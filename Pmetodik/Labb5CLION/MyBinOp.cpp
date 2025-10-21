//
// Created by OmarK on 2025-10-21.
//

#include "MyBinOp.h"

double MyBinOp::operator()(double weight, const Car &car) {
    return car.getWeight() + weight;
}
