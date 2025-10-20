/*  !C++
    Filnamn: Laboration1.cpp
    Skrivet av: Omar Sultanzoy
    Skapat datum: 2024-11-05
    Senast ändrad: 2024-11-05
    Kurs: Introduktion till programmering
    Kursanvsarig: Nayeb Maleki & Jan-Erik
    Beskrikvning: Denna kod läser in information från en textfil och sorterar den i en viss ordning */

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inFile("names.txt");
    std::ofstream outFile("Resultat.txt");
    std::string förnamn;
    std::string efternamn;
    std::string personnummer;
    std::string adress;

    std::getline(inFile, förnamn, ' ');
    std::getline(inFile, efternamn);
    std::getline(inFile, personnummer);
    std::getline(inFile, adress);

    while (!inFile.eof())
    {

        outFile << efternamn << ", " << förnamn;
        if ((personnummer[8] % 2) == 0)
        {
            outFile << " [K]";
        }
        else
        {
            outFile << " [M]";
        }
        outFile << std::endl;
        outFile << adress << std::endl;

        std::getline(inFile, förnamn, ' ');
        std::getline(inFile, efternamn);
        std::getline(inFile, personnummer);
        std::getline(inFile, adress);
    }

    return 0;
}