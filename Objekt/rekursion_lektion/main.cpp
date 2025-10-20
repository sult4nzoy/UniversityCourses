#include <iostream>
#include <vector>
#include <string>

// // class MyInt
// // {
// //     private:

// //     int* ptr;

// //     public:

// //     MyInt(int num)
// //     {
// //         ptr = new int(num);
// //     }

// //     ~MyInt()
// //     {
// //         delete ptr;
// //         ptr = nullptr;
// //     }

// //     MyInt& operator=(MyInt& rhs)
// //     {
// //         ptr = new int (*rhs.ptr);
// //         return *this;
// //     }

// //     void set(int num)
// //     {
// //         ptr = new int(num);
// //     }

// //     int get()
// //     {
// //         return *ptr;
// //     }

// // };

// // int main()
// // {
// //     int a,b,c;
// //     std::cin >> a  >> b >> c;
// //     MyInt i(a);

// //     std::cout << i.get() << std::endl;

// //     i.set(b);

// //     std::cout << i.get() << std::endl;

// //     MyInt j(c);

// //     i = j;

// //     std::cout << i.get() << std::endl;

// //     return 0;
// // }

// class NameList
// {
//     private:
//     std::vector<std::string> names;

//     public:
//     NameList()
//     {

//     }
//     NameList(const NameList& yo)
//     {
//         names = yo.names;
//     }
//     void push_name(std::string yo)
//     {
//         names.push_back(yo);
//     }
//     friend std::ostream& operator<<(std::ostream& o, const NameList& list)
//     {
//         for(int i = 0; i < list.names.size(); i++)
//         {
//             o << list.names[i] << " ";
//         }

//         return o;
//     }
// };

// int main()
// {
//     std::string n1, n2, n3;
//     std::cin >> n1 >> n2 >> n3;

//     NameList objekt1;
//     objekt1.push_name(n1);
//     objekt1.push_name(n2);
//     objekt1.push_name(n3);

//     std::cout << objekt1 << std::endl;

//     NameList objekt2(objekt1);

//     std::cout << objekt2 << std::endl;

//     return 0;
// }

// // class Playlist
// // {
// //     private:

// //     std::vector<std::string> tracks;
// //     unsigned int current_track_index;

// //     public:

// //     void add_track(std::string x)
// //     {
// //         tracks.push_back(x);
// //     }

// //     std::string get_current_track()
// //     {
// //         return tracks[current_track_index];
// //     }

// //     void prev()
// //     {
// //         if (current_track_index == 0)
// //         {
// //             current_track_index = tracks.size() - 1;
// //         }
// //         else
// //         {
// //             current_track_index--;
// //         }

// //     }
// //     void next()
// //     {
// //         if (current_track_index == tracks.size() - 1)
// //         {
// //             current_track_index = 0;
// //         }
// //         else
// //         {
// //             current_track_index++;
// //         }
// //     }
// //     Playlist()
// //     {
// //         current_track_index = 0;
// //     }

// //     friend std::ostream& operator<<(std::ostream& o, const Playlist& yoski)
// //     {
// //         for(int i = 0; i < yoski.tracks.size(); i++)
// //         {
// //             o << yoski.tracks[i] << " ";
// //         }
// //         return o;
// //     }

// // };

// // int main()
// // {
// //     std::string n1, n2, n3;
// //     std::cin >> n1 >> n2 >> n3;

// //     Playlist obj1;

// //     obj1.add_track(n1);
// //     obj1.add_track(n2);
// //     obj1.add_track(n3);

// //     obj1.prev();
// //     std::cout << obj1.get_current_track() << std::endl;

// //     obj1.next();
// //     obj1.next();
// //     std::cout << obj1.get_current_track() << std::endl;

// //     std::cout << obj1 << std::endl;

// //     return 0;
// // }

// // class NameList
// // {
// //     private:
// //     std::vector<std::string> names;

// //     public:
// //     NameList()
// //     {

// //     }
// //     NameList(NameList &obj)
// //     {
// //         names = obj.names;
// //     }
// //     void push_names(std::string name)
// //     {
// //         names.push_back(name);
// //     }
// //     friend std::ostream& operator<<(std::ostream& o, NameList& yo)
// //     {
// //         for(int i = 0; i < yo.names.size(); i++)
// //         {
// //             o << yo.names[i] << " ";
// //         }

// //         return o;
// //     }
// // };

// // int main()
// // {

// //     std::string n1, n2, n3;
// //     std::cin >> n1 >> n2 >> n3;

// //     NameList objekt1;
// //     objekt1.push_names(n1);
// //     objekt1.push_names(n2);
// //     objekt1.push_names(n3);
// //     std::cout << objekt1 << std::endl;
// //     NameList objekt2(objekt1);
// //     std::cout << objekt2 << std::endl;

// //     return 0;

// // }

// // class Book
// // {
// // private:
// //     std::string title;
// //     unsigned int pages;
// //     unsigned int current_page;

// // public:
// //     Book(std::string title, unsigned int pages)
// //     {
// //     }
// //     void change_page(unsigned int newPage)
// //     {
// //         current_page = newPage;
// //     }
// //     void next_page()
// //     {
// //         current_page++;
// //     }
// //     void prev_page()
// //     {
// //         current_page--;
// //     }
// //     unsigned int get_page() const
// //     {
// //         return current_page;
// //     }
// //     friend std::ostream &operator<<(std::ostream &o, Book &b)
// //     {
// //         o << b.get_page();
// //         return o;
// //     }
// // };

// // int main()
// // {
// //     std::string a;
// //     unsigned int b, c;
// //     std::cin >> a >> b >> c;

// //     // skapa en bok genom att anropa konstruktorn med a och b som argument
// //     // Book bok1(std::string a, unsigned int b);
// //     Book bok1(a, b);

// //     // bläddra till sida c
// //     bok1.change_page(c);
// //     std::cout << "--------------------------------------------------" << std::endl;

// //     // skriv ut aktuell sida till cout, inklusive radbrytning.
// //     std::cout << bok1.get_page() << std::endl;

// //     // bläddra till nästa sida

// //     bok1.next_page();

// //     // skriv ut aktuell sida till cout, inklusive radbrytning.

// //     std::cout << bok1.get_page() << std::endl;

// //     // bläddra till föregående sida

// //     bok1.prev_page();

// //     // skriv ut aktuell sida till cout, inklusive radbrytning.

// //     std::cout << bok1.get_page() << std::endl;

// //     // bläddra till föregående sida

// //     bok1.prev_page();

// //     // skriv ut aktuell sida till cout, inklusive radbrytning.

// //     std::cout << bok1.get_page() << std::endl;

// //     return 0;
// // }

// // class MyInt
// // {
// //     private:

// //     int* ptr;

// //     public:

// //     MyInt(int num)
// //     {
// //         ptr = new int(num);
// //     }
// //     ~MyInt()
// //     {
// //         delete ptr;
// //         ptr = nullptr;
// //     }
// //     MyInt& operator=(MyInt& rhs)
// //     {
// //         ptr = new int(*rhs.ptr);
// //         return *this;
// //     }

// //     void set(int num)
// //     {
// //         ptr = new int(num);
// //     }
// //     int get()
// //     {
// //         return *ptr;
// //     }

// // };

// // int main()
// // {
// //     int a,b,c;
// //     std::cin >> a >> b >> c;

// //     MyInt i(a);

// //     std::cout << i.get() << std::endl;

// //     i.set(b);

// //     std::cout << i.get() << std::endl;

// //     MyInt j(c);

// //     i = j;

// //     std::cout << i.get() << std::endl;

// //     return 0;
// // }

// class Car
// {
//     private:
//     int model_year;
//     std::string model_name;

//     public:
//     Car(int year, std::string model)
//     {
//         this->model_year = year;
//         this->model_name = model;
//     }

//     int model_year_getter()
//     {
//         return model_year;
//     }
//     std::string model_name_getter()
//     {
//         return model_name;
//     }

//     friend std::ostream& operator<<(std::ostream & o, Car & car)
//     {
//         o << "Modell: " << car.model_name_getter() << ", producerad: " << car.model_year_getter();

//         return o;
//     }

// };

// int main()
// {
//  int a; std::string b;
//  std::cin >> a >> b;

//  Car car(a, b);

//  // skapa ett objekt av din klass genom att anropa konstruktorn med a och b som argument
//  // skriv ut modellnamn[space]modellår för ditt objekt
// //  std::cout << car.model_name_getter() << " " << car.model_year_getter();

//  Car car1(a,b);

//  std::cout << car1;

//  return 0;
// }

// int factorial(int n)
// {
//     int f = 1;
//     for (int i = n; i > 1; i--)
//     {
//         f *= i;
//     }
//     return f;
// }

// int factorial_rek(int n)
// {
//     //base case
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }

//     return factorial_rek(n-1) * n;
// }

// int main()
// {
//     int a;
//     // hämta input från cin
//     std::cin >> a;

//     // anropa din funktion och skicka resultatet till cout
//     std::cout << "factoral av " << a << " = " <<  factorial_rek(a) << std::endl;
//     return 0;
// }

// int compute(std::string str, int result)
// {
//     //base case
//     if(str.length() <= 1)
//     {
//         return result;
//     }
//     if(str[0] == str[1] || str[0] == str[2])
//     {
//         result += 1;
//     }

//     return compute(str.substr(1), result);

// }

// int main()
// {
//     std::string s;

//     std::cin >> s;

//     std::cout << compute(s, 0) << std::endl;

//     return 0;
// }



// bool palindrome(std::string word)
// {

//     //base case
//     if (word.front() == word.back())
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }

//     return palindrome(word);

// }
// int main()
// {
//     // hämta input från cin
//     std::string a;
//     std::cin >> a;
//     // anropa din funktion och skicka resultatet till cout
//     std::cout <<  palindrome(a) << std::endl;
//     return 0;
// }

// class MyInt
// {
//     private:

//     int* ptr;

//     public:

//     MyInt(int num)
//     {
//         ptr = new int(num);
//     }

//     ~MyInt()
//     {
//         delete ptr;
//         ptr = nullptr;
//     }

//     MyInt& operator=(const MyInt& rhs)
//     {
//         ptr = new int(*rhs.ptr);

//         return *this;
//     }

//     void set(int num)
//     {
//         ptr = new int(num);
//     }

//     int get()
//     {
//         return *ptr;
//     }

// };

// int fib(int num)
// {
//     //base case
//     if (num == 0)
//     {
//         return 0;
//     }
//     if(num == 1)
//     {
//         return 1;
//     }

//     return fib(num - 1) + fib(num - 2);
// }
// int main()
// {
//     int a;
//     std::cin>>a;

//     std::cout << fib(a) << std::endl;


//     return 0;
// }