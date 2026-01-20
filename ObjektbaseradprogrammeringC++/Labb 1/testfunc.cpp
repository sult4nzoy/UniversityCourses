#include "header4test.h"

Account::Account() // scoping operator
{
    balance = 0;
    owner_name = "";

}

Account::Account(int balance)
{
    owner_name = "no one";
    this->balance = balance;

}


Account::Account(std::string owner_name, int balance)
{
    this->owner_name = owner_name;  // en pekare som refererar till oss själva
    this->balance = balance;
}

Account::Account(const Account& src)
{
    owner_name = src.owner_name;
    balance = src.balance;

}

int Account::withdraw(int amount) {
    if (amount <= balance)
    {
        balance -= amount;
    }
    else 
    {
        std::cout << "Not enough balance, your balance is: " << balance << std::endl;
    }
    return amount;
}


Account& Account::operator=(const Account & rhs) {
    
    balance = rhs.balance;
    owner_name = rhs.owner_name;

    return *this;
}