//
// Created by OmarK on 2025-09-26.
//

#ifndef LABB2CLION_RECTANGLE_H
#define LABB2CLION_RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape{

    public:
    Rectangle(std::string color, double height, double width);
    double get_Area() override;

protected:
    double height;
    double width;

};




#endif //LABB2CLION_RECTANGLE_H
