// #include <iostream>
// #include <string>

// class Car
// {
// private:
//     int model_year;
//     std::string model_name;

// public:
//     Car(int modelYear, std::string modelName)
//     {
//         this->model_year = modelYear;
//         this->model_name = modelName;
//     }

//     int getYear()
//     {
//         return model_year;
//     }

//     std::string getModel()
//     {
//         return model_name;
//     }
//     friend std::ostream &operator<<(std::ostream &o, Car &car)
//     {

//         o << "Modell: " << car.getModel() << ", producerad: " << car.getYear();

//         return o;
//     }
// };

// int main()
// {
//     int a;
//     std::string b;
//     std::cin >> a >> b;

//     Car car(a, b);
//     std::cout << car.getModel() << " " << car.getYear() << std::endl;

//     Car car2(a, b);

//     std::cout << car2 << std::endl;

//     return 0;
// }
// #include <iostream>
// #include <string>

// class BankAccount
// {
    
//     unsigned int account_no;
//     std::string owner_name;
//     double balance = 0;

//     public:
    
//     BankAccount(unsigned int a_no, const std::string& o_n) 
//     {
//         this->account_no = a_no;
//         this->owner_name = o_n;
//     }

//     void deposit(double amount)
//     {
//         balance += amount;
//     }

//     double withdraw(double amount)
//     {
//         if (amount > balance)
//         {
//             return balance;
//         }
    
//         balance -= amount;

//         return balance;
//     }

// };

// int main() {
// int a; std::string b; double c, d;
// std::cin >> a >> b >> c >> d;

// // skapa ett objekt av din klass genom att anropa konstruktorn med a och b som argum

// BankAccount account(a,b);
// // gör en insättning med c som argument
// account.deposit(c);


// // gör ett uttag med d som argument och skicka resultatet till cout

// std::cout << account.withdraw(d);

// return 0;
// }