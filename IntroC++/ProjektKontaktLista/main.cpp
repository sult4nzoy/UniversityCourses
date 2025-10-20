#include "allaFunktioner.h" 

int main()
{
    int avslutaProgram = 4;
    int användarensVal = 0;
    while (användarensVal != avslutaProgram)
    {
        std::cout << "---MENY---" << std::endl;
        std::cout << "|1| Lägga till en kontakt." << std::endl;
        std::cout << "|2| Ta bort en kontakt." << std::endl;
        std::cout << "|3| Sök efter en kontakt." << std::endl;
        std::cout << "|4| Avsluta program." << std::endl;
        std::cout << std::endl;
        std::cout << "Val: ";

        std::cin >> användarensVal;

        switch (användarensVal)
        {
        case 1:
            
            läggTillKontakt();
            break;

        case 2:
            
            taBortKontakt(); 
            break;

        case 3:
            
            sökKontakt(); 
            break;

        case 4:
            
            std::cout << "Programmet avslutas..." << std::endl;
            break;

        default:
            std::cout << std::endl;
            std::cout << "Ogiltigt val. Försök igen." << std::endl;
            std::cout << std::endl;
            break;
        }
    }
    return 0;
}