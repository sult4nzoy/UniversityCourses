#include "funktioner.h"
using namespace std;

int main()
{
    vector<Person> people = read_file("names.txt");
    if (people.empty())
    {
        cout << "Kunde inte läsa filen eller filen är tom." << endl;
        return 0;
    }

    int menuChoise = 0;
    const int endProgram = 3;

    while (menuChoise != endProgram)
    {
        cout << "---Meny---" << endl;
        cout << "1. Sök efter namn" << endl;
        cout << "2. Sök efter stad" << endl;
        cout << "3. Avsluta program" << endl;
        cout << "Val: ";
        cin >> menuChoise;
        
        cin.ignore();

        switch (menuChoise)
        {
        case 1:
        {
            cout << "Ange namn att söka efter: ";
            string search_name;
            getline(cin, search_name);

            size_t matches = find_in_names(people, search_name);
            cout << "Hittade " << matches << " träffar" << " med sökningen: " << search_name << endl;
            
            break;
        }
        case 2:
        {
            cout << "Ange stad att söka efter: ";
            string search_city;
            getline(cin, search_city);

            vector<Person> result = find_person_from_city(people, search_city);
            cout << "Hittade " << result.size() << " personer i " << search_city << ":" << endl;


            for (const auto &p : result)
            {
                cout << endl;
                display_city_search(p);
                cout << endl;
            }
            
            break;
        }
        case 3:
            cout << "Programmet avslutas..." << endl;
            break;
        default:
            cout << "Ogiltigt val, försök igen." << endl;
        }
    }

    return 0;
}