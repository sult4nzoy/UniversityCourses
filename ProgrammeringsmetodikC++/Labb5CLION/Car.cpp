//
// Created by OmarK on 2025-10-16.
//

#include "Car.h"

Car::Car(std::string name, double weight) : name(name), weight(weight) {}

std::string Car::getName() const {
    return name;
}

double Car::getWeight() const {
    return weight;
}

bool operator==(const Car &lhs, const Car &rhs) {
    return lhs.name == rhs.name;
}
