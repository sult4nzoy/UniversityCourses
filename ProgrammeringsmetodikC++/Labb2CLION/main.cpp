#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "cylinder.h"
#include "parallelpiped.h"
#include "rounded_rectangle.h"
#include "square.h"
#include <vector>
#include <iostream>
#include <memory>



void printShapes(const std::vector<std::unique_ptr<Shape>>& v)
{
    double totalArea = 0;
    for (auto &e : v)
    {
        std::cout << "Färg: " << e->get_color() << ", Area: " << e->get_Area() << std::endl;
        totalArea += e->get_Area();
    }
    std::cout << "Totala arean av alla shapes: " << totalArea << std::endl;
}

int main()
{
    std::vector<std::unique_ptr<Shape>> allShapes;
    allShapes.push_back(std::make_unique<Circle>("blå", 5));
    allShapes.push_back(std::make_unique<Cylinder>("röd", 5, 5));
    allShapes.push_back(std::make_unique<Rectangle>("gul", 5, 5));
    allShapes.push_back(std::make_unique<Square>("square", 5));
    allShapes.push_back(std::make_unique<Parallelpiped>("grön", 5, 5, 5));
    allShapes.push_back(std::make_unique<Rounded_rectangle>("brun", 5, 5, 5));

    printShapes(allShapes);

    return 0;
}
