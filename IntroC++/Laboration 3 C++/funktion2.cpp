#include <iostream>
#include <fstream>
#include "funktion2.h"

void mergeFil(std::string inFile, std::string inFile1, std::string outFile)
{

    std::ifstream A(inFile);
    std::ifstream B(inFile1);
    std::ofstream C(outFile);

    int förstaNumret, andraNumret;

    A >> förstaNumret;
    B >> andraNumret;

    while (!A.eof() && !B.eof())
    {

        if (förstaNumret < andraNumret)
        {
            C << förstaNumret << " ";
            A >> förstaNumret;
        }
        else
        {
            C << andraNumret << " ";
            B >> andraNumret;
        }
    }
    while (!A.eof())
    {
        C << förstaNumret << " ";
        A >> förstaNumret;
    }
    while (!B.eof()) 
    {
        C << andraNumret << " ";
        B >> andraNumret;
    }
    
    A.close();
    B.close();
    C.close();

    return;
}