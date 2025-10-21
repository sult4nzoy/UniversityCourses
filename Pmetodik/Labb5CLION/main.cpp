#include <algorithm>
// #include <iostream>

#include "Car.h"
#include "MyPrint.h"

int main() {
    const int arrsize = 10;
    Car carArray[arrsize] = {

        Car("Audi", 1543),
        Car("BMW", 1367),
        Car("Toyota", 1465),
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

    std::for_each(cars.begin(), cars.end(), MyPrint());

    return 0;
}