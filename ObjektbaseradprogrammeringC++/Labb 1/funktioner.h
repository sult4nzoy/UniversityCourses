#ifndef funktioner_h
#define funktioner_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Address
{

    string street;
    int zip;
    string city;
};

struct Person
{

    string name;
    string id;
    Address location;
};

vector<Person> read_file(string filename);
size_t find_in_names(const vector<Person> &haystack, string name_part);
vector<Person> find_person_from_city(const vector<Person> &haystack, string city);
istream &operator>>(istream &in, Person &p);
void display_city_search(const Person &p);

#endif