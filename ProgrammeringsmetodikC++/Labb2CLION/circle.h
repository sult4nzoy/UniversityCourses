//
// Created by OmarK on 2025-09-26.
//

#ifndef LABB2CLION_CIRCLE_H
#define LABB2CLION_CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
public:
    Circle(std::string color, double radius);
    double get_Area() override;

protected:
    double radius;
};


#endif //LABB2CLION_CIRCLE_H