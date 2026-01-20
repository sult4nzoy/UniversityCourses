//
// Created by OmarK on 2025-09-26.
//

#include "circle.h"
#include <numbers>

Circle::Circle(std::string color, double radius) : Shape(color), radius(radius)
{
}

double Circle::get_Area()
{
    return std::numbers::pi * radius * radius;
}
