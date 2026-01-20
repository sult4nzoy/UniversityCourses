//
// Created by OmarK on 2025-10-02.
//


#include "shape.h"
#include "square.h"

Square::Square(std::string color, double width) : Shape(color), width(width)
{
}

double Square::get_Area()
{
    return width * width;
}
