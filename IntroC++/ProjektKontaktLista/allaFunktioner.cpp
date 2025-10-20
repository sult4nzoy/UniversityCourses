#include "allaFunktioner.h"

void läggTillKontakt()
{
    std::string förnamn, efternamn, epost, telefonnummer, födelsedag, adress, övrigt, läggaTillKontakt;
    std::ofstream outFile("Kontaktbok", std::ios::app);

    std::cout << "Personens förnamn: ";
    std::cin >> förnamn;
    std::cout << "Personens efternamn: ";
    std::cin >> efternamn;
    std::cout << "Personens adress: ";
    std::cin.ignore();
    std::getline(std::cin, adress);
    std::cout << "Personens e-post: ";
    std::cin >> epost;
    std::cout << "Personens telefonnummer : ";
    std::cin >> telefonnummer;
    std::cout << "Personens födelsedatum: ";
    std::cin >> födelsedag;
    std::cout << "Övrigt, t.ex kön: ";
    std::cin >> övrigt;

    outFile << "---------------------------" << std::endl;
    outFile << förnamn << std::endl;
    outFile << efternamn << std::endl;
    outFile << adress << std::endl;
    outFile << epost << std::endl;
    outFile << telefonnummer << std::endl;
    outFile << födelsedag << std::endl;
    outFile << övrigt << std::endl;
    outFile << "---------------------------" << std::endl;
    outFile.close();

    std::cout << std::endl;
    std::cout << "Kontakten lades till i kontaktboken!" << std::endl;
    std::cout << std::endl;
}

void taBortKontakt()
{
    std::ifstream inFile("Kontaktbok");
    std::vector<std::string> allaKontakter;
    std::string rad;

    while (std::getline(inFile, rad))
    {
        allaKontakter.push_back(rad);
    }
    inFile.close();

    for (const auto &rad : allaKontakter)
    {
        std::cout << rad + "\n";
    }

    std::string förnamnTaBort;
    std::cout << "Ange förnamnet på personen du vill ta bort: ";
    std::cin >> förnamnTaBort;

    std::vector<std::string> behållKontakt;
    std::vector<std::string> temporärVek;
    bool letaren = false;

    for (const auto &rad : allaKontakter)
    {
        temporärVek.push_back(rad);

        if (temporärVek.size() == 9)
        {
            std::string förnamn = temporärVek[1];

            if (förnamn == förnamnTaBort)
            {
                letaren = true;
            }
            else
            {
                behållKontakt.insert(behållKontakt.end(), temporärVek.begin(), temporärVek.end());
            }
            temporärVek.clear();
        }
    }

    if (letaren)
    {
        std::ofstream outFile("Kontaktbok", std::ios::trunc);
        for (const auto &kontakt : behållKontakt)
        {
            outFile << kontakt << std::endl;
        }
        outFile.close();
        std::cout << std::endl;
        std::cout << "Kontakten med förnamnet " << förnamnTaBort << " har tagits bort.";
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Ingen kontakt hittades med förnamnet: " << förnamnTaBort;
        std::cout << std::endl;
    }
}

void sökKontakt()
{
    std::ifstream inFile("Kontaktbok");
    std::string rad, förnamnSök;
    std::vector<std::string> allaKontakter;
    bool kontaktHittad = false;

    std::cout << "Ange förnamnet på personen du vill söka efter: ";
    std::cin >> förnamnSök;

    while (std::getline(inFile, rad))
    {
        allaKontakter.push_back(rad);

        if (allaKontakter.size() == 9)
        {
            std::string förnamn = allaKontakter[1];

            if (förnamn == förnamnSök)
            {
                std::cout << std::endl;
                std::cout << "Kontakt hittad: " << std::endl;
                std::cout << std::endl;
                for (const auto &kontaktRad : allaKontakter)
                {
                    std::cout << kontaktRad << "\n";
                }
                kontaktHittad = true;
                std::cout << std::endl;
            }

            allaKontakter.clear();
        }
    }

    inFile.close();

    if (!kontaktHittad)
    {
        std::cout << "Ingen kontakt hittades med förnamnet: " << förnamnSök << std::endl;
    }
}