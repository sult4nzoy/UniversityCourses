//
// Created by OmarK on 2025-09-26.
//

#ifndef LABB2CLION_ROUNDED_RECTANGLE_H
#define LABB2CLION_ROUNDED_RECTANGLE_H
#include "rectangle.h"


class Rounded_rectangle : public Rectangle
{
    public:
    Rounded_rectangle(std::string color, double height, double width, double radius);
    double get_Area() override;

protected:

    double radius;
};




#endif //LABB2CLION_ROUNDED_RECTANGLE_H
