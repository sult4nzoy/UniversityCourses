//
// Created by OmarK on 2025-09-26.
//

#ifndef LABB2CLION_SHAPE_H
#define LABB2CLION_SHAPE_H
#include <string>

class Shape
{
public:
    Shape(std::string color);
    virtual double get_Area() = 0;
    std::string get_color();

protected:
    std::string color;
};


#endif //LABB2CLION_SHAPE_H