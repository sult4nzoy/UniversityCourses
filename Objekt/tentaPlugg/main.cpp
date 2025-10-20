#include <iostream>
#include <string>

class BankAccount
{
    unsigned int account_no {};
    std::string owner_name {};
    double balance {};


public:
    BankAccount() = default;
    BankAccount(unsigned int a_no, const std::string& o_n) : account_no(a_no), owner_name(o_n){}

    void deposit(double amount)
    {
        balance += amount;
    }

    double withdraw(double amount)
    {
        if (amount > balance)
        {
            return balance;
        }

        balance -= amount;

        return balance;
    }

    friend std::istream& operator>>(std::istream& i, BankAccount& a);
    friend std::ostream& operator<<(std::ostream& o, const BankAccount& a);
};
    std::istream& operator>>(std::istream& i, BankAccount& a) {
        i >> a.account_no >> a.owner_name >> a.balance;
        return i;

    }
    std::ostream& operator<<(std::ostream& o, const BankAccount& a) {
        o << "Account " << a.account_no << ", owned by " << a.owner_name << " has the balance " << a.balance;
        return o;
    }
bool pali(std::string word) {
        if (word.size() <= 1)
            return true;
        if (word[0] != word[word.size() - 1])
            return false;
        return pali(word.substr(1, word.size() -2 ));
    }

int main() {
    int *p, *q = new int(5);
    p = q;
    *p = *q;
    delete p;
    delete q;
    p = q = nullptr;
        std::cout << *q << std::endl;
    return 0;

}
