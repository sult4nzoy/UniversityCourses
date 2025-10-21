//
// Created by OmarK on 2025-10-16.
//


#ifndef LABB5CLION_CAR_H
#define LABB5CLION_CAR_H
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class Car {

public:
    std::string name;
    double weight;

    Car(std::string name, double weight);
    friend bool operator==(const Car& lhs, const Car& rhs);
    std::string getName() const;
    double getWeight() const;

};


#endif //LABB5CLION_CAR_H