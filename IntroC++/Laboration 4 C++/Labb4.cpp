#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool compareByFrequency(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
{
    return a.second > b.second;
}

int main()
{
    int siffrorSomAnvändarenValt;

    std::cout << "Hur många av de mest förekommande orden vill du se?: ";
    std::cin >> siffrorSomAnvändarenValt;

    std::ifstream inFile("hitchhikersguide.txt");
    if (!inFile.is_open())
    {
        std::cout << "Kunde inte öppna filen." << std::endl;
        return 1;
    }

    std::vector<std::string> ord;
    std::string ordTemp;

    while (inFile >> ordTemp)
    {
        std::transform(ordTemp.begin(), ordTemp.end(), ordTemp.begin(), ::tolower);

        while (!ordTemp.empty() && !isalpha(ordTemp.front()))
        {
            ordTemp.erase(ordTemp.begin());
        }

        while (!ordTemp.empty() && !isalpha(ordTemp.back()))
        {
            ordTemp.pop_back();
        }

        if (!ordTemp.empty())
        {
            ord.push_back(ordTemp);
        }
    }

    inFile.close();

    std::map<std::string, int> förekomstOrd;

    for (const auto &word : ord)
    {
        förekomstOrd[word]++;
    }

    std::vector<std::pair<std::string, int>> ordLista(förekomstOrd.begin(), förekomstOrd.end());

    std::sort(ordLista.begin(), ordLista.end(), compareByFrequency);

    std::cout << "De " << siffrorSomAnvändarenValt << " mest förekommande orden är:" << std::endl;
    int i = 0;

    for (const auto &pair : ordLista)
    {
        if (siffrorSomAnvändarenValt == i)
        {
            break;
        }
        std::cout << pair.first << ": " << pair.second << " gånger" << std::endl;
        i++;
    }

    return 0;
}
