//
// Created by OmarK on 2025-09-26.
//

#ifndef LABB2CLION_PARALELLPIPED_H
#define LABB2CLION_PARALELLPIPED_H
#include "rectangle.h"

class Parallelpiped : public Rectangle
{
    public:
    Parallelpiped(std::string color, double height, double width, double depth);
    double get_Area() override;

protected:

    double depth;

};




#endif //LABB2CLION_PARALELLPIPED_H
