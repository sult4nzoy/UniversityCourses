//
// Created by OmarK on 2025-10-20.
//

#include "MyPrint.h"

void MyPrint::operator()(const Car &cars) const {
    std::cout << "Tillverkare är " << cars.getName() << " och bilen väger " << cars.getWeight()  << " kg" << std::endl;
}
