#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account 
{
private:
    std::string owner_name;
    int balance;
    
public:
    Account(); //default konstruktor

    Account(int);
    
    Account(std::string, int); //parametriseradkonstruktor

    Account(const Account&); // kopieringskonstruktor (skapar ett konto av kontot)

   int withdraw(int amount);

};

#endif