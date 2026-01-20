//
// Created by OmarK on 2025-09-26.
//

#ifndef LABB2CLION_CYLINDER_H
#define LABB2CLION_CYLINDER_H
#include "circle.h"

class Cylinder : public Circle
{
public:
    Cylinder(std::string color, double height, double radius);
    double get_Area() override;

protected:
    double height;
};


#endif //LABB2CLION_CYLINDER_H