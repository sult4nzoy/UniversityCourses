/*  !C++
    Filnamn: Laboration1.cpp
    Skrivet av: Omar Sultanzoy
    Skapat datum: 2024-11-05
    Senast ändrad: 2024-11-05
    Kurs: Introduktion till programmering
    Kursanvsarig: Nayeb Maleki & Jan-Erik
    Beskrinvning: Detta program låter användaren skriva X antal tal i Terminal, hittar min- och maxvärdet och tar sedan reda på medelvärdet */

#include <iostream>

int main()
{

    int nummer;
    int maxVärdet;
    int minVärdet;
    int summa = 0;
    int antalSiffror = 0;

    std::cin >> nummer;
    maxVärdet = nummer;
    minVärdet = nummer;

    summa += nummer;

    antalSiffror++;

    while (std::cin >> nummer)
    {

        if (nummer < minVärdet)   
        {
            minVärdet = nummer;   
        }
        if (nummer > maxVärdet)
        {
            maxVärdet = nummer;
        }

        summa += nummer;

        antalSiffror++;
    }

    double medelvärdet = static_cast<double>(summa) / antalSiffror;

    std::cout << "Minimum värdet: " << minVärdet << std::endl;
    std::cout << "Maximum värdet: " << maxVärdet << std::endl;
    std::cout << "Medelvärdet: " << medelvärdet << std::endl;

    int x = 10;
    int* p = &x;
    std::cout << p << std::endl;



    return 0;
}