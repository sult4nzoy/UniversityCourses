//
// Created by OmarK on 2025-10-02.
//

#ifndef LABB2CLION_SQUARE_H
#define LABB2CLION_SQUARE_H


class Square : public Shape
{

public:
        Square(std::string color, double width);
        double get_Area() override;

protected:
        double width;

};


#endif //LABB2CLION_SQUARE_H