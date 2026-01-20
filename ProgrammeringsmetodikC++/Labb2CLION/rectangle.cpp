//
// Created by OmarK on 2025-09-26.
//

#include "rectangle.h"

Rectangle::Rectangle(std::string color, double height, double width) : Shape(color), height(height), width(width)
{
}

double Rectangle::get_Area()
{
    return height * width;
}
