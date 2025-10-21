#include <algorithm>
#include <numeric>
#include "Car.h"
#include "GreaterThan.h"
#include "MyBinOp.h"
#include "MyPrint.h"
#include "MyUnOp.h"

int main() {
    const int arrsize = 10;
    Car carArray[arrsize] = {

        Car("Audi", 1543),
        Car("Audi", 1367),
        Car("BMW", 1465),
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
    std::cout << std::endl;
    std::cout << "4. Kolla om arrayen och vectorn har samma innehåll, det görs med std::equal" << std::endl;

    auto sameContainers = std::equal(cars.begin(), cars.end(), carArray);

    if (sameContainers == true) {
        std::cout << "Arr och vec har samma innehåll" << std::endl;
    }
    else {
        std::cout << "Ej samma innehåll" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "5. Kolla om arrayen och vectorn har samma innehåll, det görs med std::equal" << std::endl;
    std::vector<Car> subSequence;
    subSequence.push_back(cars[4]);
    subSequence.push_back(cars[5]);
    subSequence.push_back(cars[6]);
    auto subSeqFound = std::search(cars.begin(), cars.end(), subSequence.begin(), subSequence.end());
    auto found_at_idx = subSeqFound - cars.begin();

    if (subSeqFound != cars.end()) {
        std::cout << "Hittade subSequence från index: " << found_at_idx << std::endl;
        for (auto const &c : subSequence) {
            printer(c);
        }
    }
    else {
        std::cout << "Hittade ej subSequence" << std::endl;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "6. Hitta medelvärdet (vikt) av alla bilar i vec med std::accumulate" << std::endl;
    MyBinOp mbo;
    double init = 0.0;
    auto avg = std::accumulate(cars.begin(), cars.end(), init, mbo);
    auto mean = avg / cars.size();
    std::cout << "Mean: " << mean << " kg" <<std::endl;

    std::cout << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "7. skapa v2 vec och hämta vikten från vec1 och använd transform" << std::endl;
    std::vector<double> carsV2;
    carsV2.resize(cars.size());
    MyUnOp mup;
    std::transform(cars.begin(), cars.end(), carsV2.begin(), mup);
    for (auto const &c : carsV2) {
        std::cout << c << " kg"<< std::endl;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "8. " << std::endl;


    return 0;
}