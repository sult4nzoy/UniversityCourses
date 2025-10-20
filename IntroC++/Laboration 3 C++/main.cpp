#include <iostream>
#include <fstream>
#include "funktion1.h"
#include "funktion2.h"

int main()
{
    std::string inFile;
    std::string inFile1;
    int användarensVal = 0;

    std::cout << "1. Kontrollera om en fil är sorterad" << std::endl;
    std::cout << "2. Merge fil" << std::endl;
    std::cout << "Val: ";
    std::cin >> användarensVal;

    switch (användarensVal)
    {

    case 1:
        std::cout << "Vilken fil vill du kontrollera? Du kan välja mellan: A.txt, A1.txt och B.txt: ";
        std::cin >> inFile;
        if (kontrolleraFil(inFile))
        {
            std::cout << "Filen:" << " " << inFile << " " << "är sorterad." << std::endl;
        }
        else
        {
            std::cout << "Filen:" << " " << inFile << " " << "är inte sorterad." << std::endl;
        }
        break;

    case 2:
        std::cout << "Välj två filer du vill merga. Du kan välja A.txt, A1.txt och B.txt." << std::endl;
        std::cin >> inFile >> inFile1;
        if ((inFile != "A.txt" && inFile != "a.txt" &&
             inFile != "A1.txt" && inFile != "a1.txt" &&
             inFile != "B.txt" && inFile != "b.txt") ||
            (inFile1 != "A.txt" && inFile1 != "a.txt" &&
             inFile1 != "A1.txt" && inFile1 != "a1.txt" &&
             inFile1 != "B.txt" && inFile1 != "b.txt"))
        {
            std::cout << "Ena eller båda filerna existerar inte eller är inte tillåtna." << std::endl;
            break;
        }
        if (!kontrolleraFil(inFile) || !kontrolleraFil(inFile1))
        {
            std::cout << "Kunde inte merga filerna då nån av filerna inte är sorterad." << std::endl;
        }

        else
        {     
            mergeFil(inFile, inFile1, "C.txt");
            std::cout << "Filerna har mergats till C.txt." << std::endl;
        }
    
        break;

    default:
        std::cout << "Ej giltigt val. " << std::endl;
    }

    return 0;
}
