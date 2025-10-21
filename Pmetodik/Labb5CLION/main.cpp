#include <algorithm>
// #include <iostream>

#include "Car.h"
#include "GreaterThan.h"
#include "MyPrint.h"

int main() {
    const int arrsize = 10;
    Car carArray[arrsize] = {

        Car("Audi", 1543),
        Car("BMW", 1367),
        Car("Audi", 1465),
        Car("Subaru", 1187),
        Car("Honda", 1987),
        Car("Volvo", 2500),
        Car("Lamborghini", 5000),
        Car("Bugatti", 2212),
        Car("Rolls Royce", 4324),
        Car("Siyes Cykel", 2134),
    };

    std::vector<Car> cars;
    for (auto const &c : carArray) {
        cars.push_back(c);
    }

    MyPrint printer;

    std::cout << "1. Skriv ut alla element i vectorn med for_each" << std::endl;

    std::for_each(cars.begin(), cars.end(), printer);

    std::cout << "-------------------------------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "2. Hitta första objektet som har en weight > 1564  med find_if och dens position" << std::endl;

    auto findings = std::find_if(cars.begin(), cars.end(), GreaterThan(1564));
    auto Findingpot = findings - cars.begin();
    if (findings != cars.end()) {
        printer(*findings);
    }
    else {
        std::cout << "Hitta ej" << std::endl;
    }
    std::cout << "Ovan hittades i index " << Findingpot << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "3. Gå igenom vector med adjacent_find och hitta alla bilar med samma namn." << std::endl;
    auto SameName = std::adjacent_find(cars.begin(), cars.end());
    if (SameName != cars.end()) {
        printer(*SameName);
    }
    else {
        std::cout << "Hitta ej" << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;

    return 0;
}