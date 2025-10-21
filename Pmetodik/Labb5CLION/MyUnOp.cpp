//
// Created by OmarK on 2025-10-21.
//

#include "MyUnOp.h"

double MyUnOp::operator()(const Car &car) {
    return car.getWeight();
}
