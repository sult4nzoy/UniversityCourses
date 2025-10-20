//
// Created by OmarK on 2025-09-26.
//

#include "rounded_rectangle.h"

#include "circle.h"


Rounded_rectangle::Rounded_rectangle(std::string color, double height, double width, double radius) : Rectangle(color, height, width), radius(radius)
{
}

double Rounded_rectangle::get_Area()
{
    Circle c("", radius);
    return Rectangle::get_Area() - (radius * radius * 4) + c.get_Area();
}

double radius;