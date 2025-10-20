#include <vector>
#include "Email.h"
#include "MailBox.h"

int main() {
    MailBox mailbox;
    //who, date, subj
    Email mail1("Omar", "2025-10-5", "Programmeringsmetodik");
    Email mail2("Wichi", "2024-9-1", "Databas");
    Email mail3("Adam", "2026-4-7", "Matematik");
    Email mail4("Siye", "2027-5-9", "Programmering");
    Email mail5("Dani", "2023-2-21", "Webbprogrammering");

    std::cout << "Unsorted mailbox: " << std::endl;
    mailbox.push_back(mail1);
    mailbox.push_back(mail2);
    mailbox.push_back(mail3);
    mailbox.push_back(mail4);
    mailbox.push_back(mail5);
    mailbox.printMailinMailBox();
    std::cout << "-------------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "Sorted mailbox by who" << std::endl;
    mailbox.SortWho();
    mailbox.printMailinMailBox();
    std::cout << "-------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Sorted mailbox by date" << std::endl;
    mailbox.SortDate();
    mailbox.printMailinMailBox();

    std::cout << "-------------------------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "Sorted mailbox by subject" << std::endl;
    mailbox.SortSubject();
    mailbox.printMailinMailBox();
    return 0;
}
