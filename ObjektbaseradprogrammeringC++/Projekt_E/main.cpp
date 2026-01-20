/*
    Namn: Omar Sultanzoy
    Kurs: Objektbaseradprogrammering i C++
    Kursansvarig: Jimmy Åhlander
    Aktuellt datum: 2025-05-18
    Betyg som jag siktar på: E
*/

#include "maze.h"

int main()
{
    int userMenuChoice = 0;
    const int endProgram = 2;
    while (userMenuChoice != endProgram)
    {
        std::cout << "---MENU---" << std::endl;
        std::cout << "1. Generate maze" << std::endl;
        std::cout << "2. End program" << std::endl;
        std::cout << "Choice: ";
        std::cin >> userMenuChoice;

        if (userMenuChoice == 1)
        {
            maze maze(15, 15);
            maze.setEntryAndExitPoint();
            maze.dfs();
            maze.visualizeMaze();
        }
        else if (userMenuChoice == endProgram)
        {
            std::cout << "Ending program..." << std::endl;
            break;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input." << std::endl;
        }
    }

    return 0;
}
          
        
