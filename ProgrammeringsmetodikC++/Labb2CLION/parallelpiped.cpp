//
// Created by OmarK on 2025-09-26.
//

#include "parallelpiped.h"

Parallelpiped::Parallelpiped(std::string color, double height, double width, double depth) : Rectangle(color, height, width), depth(depth)
{
}

double Parallelpiped::get_Area()
{
    return 2 * Rectangle::get_Area() + (height * depth) + (width * depth);
}
