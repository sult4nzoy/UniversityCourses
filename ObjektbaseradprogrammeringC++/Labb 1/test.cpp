#include "header4test.h"

 int main()
 {
   // Account a(); // funkar inte pga the most vexing parse det liknar en för mycket en funktion
    Account a;

    a.withdraw(50);

    Account b("Pelle", 500);

    Account c(b);

    Account e(10);

    return 0;
 }