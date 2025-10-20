#include "funktioner.h"
using namespace std;

istream &operator>>(istream &in, Person &p)
{
    getline(in, p.name);
    getline(in, p.id);

    string addressLine;
    getline(in, addressLine);
    
    if (p.name.empty() || p.id.empty() || addressLine.empty()) // kontrollerar om name, id eller adressLine är tomt, om ja returnera in (inström)
    {
        return in;
    }
    
    size_t commaPosition = addressLine.find(','); //hittar positionen på ',' och returnerar indexet där den är
    p.location.street = addressLine.substr(0, commaPosition); //från index 0 fram till kommat = street
    
    size_t firstHalfZip = addressLine.find_first_of("0123456789", commaPosition + 1);
    size_t spaceAfterFirstZip = addressLine.find(' ', firstHalfZip);
    size_t secondHalfZip = addressLine.find_first_of("0123456789", spaceAfterFirstZip + 1);
    size_t spaceAfterSecondZip = addressLine.find(' ', secondHalfZip + 1);
   
    string fullZip = addressLine.substr(firstHalfZip, spaceAfterSecondZip - firstHalfZip);

    fullZip.erase(3, 1); // radera 1 tecken i position 3 (mellanslaget i postnummret)l

    p.location.zip = stoi(fullZip);
    
    size_t cityStart = addressLine.find_first_not_of(' ', spaceAfterSecondZip + 1);

    p.location.city = addressLine.substr(cityStart);

    while (p.location.city.back() == ' ') //radera alla whitespaces längst bak på city tills det inte finns nå whitespace kvar
    {
        p.location.city.pop_back();
    }

    return in;
}

vector<Person> read_file(string filename)
{
    ifstream läsaren(filename);
    vector<Person> people;

    if (!läsaren.is_open())
    {
        cout << "Kunde inte öppna filen." << endl;
        return people;
    }

    Person p;

    while (läsaren >> p)
    { 
        people.push_back(p);
    }
    return people;
}

size_t find_in_names(const vector<Person>& haystack, string name_part)
{
    size_t count = 0;

    transform(name_part.begin(), name_part.end(), name_part.begin(), ::tolower);

    for (const auto &person : haystack)
    {
        string personName = person.name;

        transform(personName.begin(), personName.end(), personName.begin(), ::tolower);

        if (personName.find(name_part) != string::npos)
        {
            count++;
        }

    }

    return count;
}

vector<Person> find_person_from_city(const vector<Person> &haystack, string city) 
{

    vector<Person> result;

    transform(city.begin(), city.end(), city.begin(), ::toupper); //toupper på det användaren skriver i terminalen pga alla städer i names.txt är skrivna med stora bokstäver

    for (const auto &person : haystack)
    {
        string person_city = person.location.city;

        if (person_city == city) 
        {
            result.push_back(person);
        }
    }

    return result;
}

void display_city_search(const Person& p) // enkel display funktion
{
    cout << p.id << ", " << p.name << ", " << p.location.zip << ", " << p.location.city << endl;
}