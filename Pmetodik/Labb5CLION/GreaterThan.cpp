//
// Created by OmarK on 2025-10-21.
//

#include "GreaterThan.h"

GreaterThan::GreaterThan(double weight) : weight(weight)
{}

bool GreaterThan::operator()(const Car& car){
    return car.getWeight() > weight;
}
