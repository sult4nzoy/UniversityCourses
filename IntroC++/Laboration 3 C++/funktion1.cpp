#include <iostream>
#include <fstream>
#include <string>
#include "funktion1.h"

bool kontrolleraFil(std::string filnamn)
{

    std::ifstream inFile(filnamn);

    int förstaNumret, andraNumret;
    
    if (inFile.fail())
    {
        std::cout << "Den här filen existerar inte." << std::endl;
        return false;
    }

    inFile >> förstaNumret;

    while (!inFile.eof())
    {
        inFile >> andraNumret;

        if (förstaNumret > andraNumret)
        {
            inFile.close();
            return false;
        }
        förstaNumret = andraNumret;
    }

    inFile.close();

    return true;

    return 0;
}
