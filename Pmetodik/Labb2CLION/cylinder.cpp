//
// Created by OmarK on 2025-09-26.
//

#include "cylinder.h"

#include "rectangle.h"

Cylinder::Cylinder(std::string color, double height, double radius) : Circle(color, radius), height(height)
{
}

double Cylinder::get_Area()
{
    Circle c("", radius);
    float circumference = std::numbers::pi * (radius + radius);
    Rectangle r("", height, circumference);
    return 2 * (Circle::get_Area() * std::numbers::pi) * height + Circle::get_Area();
}
