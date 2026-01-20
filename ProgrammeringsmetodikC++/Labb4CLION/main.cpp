#include <vector>
#include "Email.h"
#include "MailBox.h"

void Show(const std::vector<Email>& mb) {
    for (auto &e : mb) {
        std::cout << e << std::endl;
    }
}


int main() {

    //who, date, subj
    Email mail1("Omar", "2025-10-5", "Programmeringsmetodik");
    Email mail2("Wichi", "2024-9-1", "Databas");
    Email mail3("Adam", "2026-4-7", "Matematik");
    Email mail4("Siye", "2027-5-9", "Programmering");
    Email mail5("Dani", "2023-2-21", "Webbprogrammering");

    std::vector<Email> MailBox;
    MailBox.push_back(mail1);
    MailBox.push_back(mail2);
    MailBox.push_back(mail3);
    MailBox.push_back(mail4);
    MailBox.push_back(mail5);
    Show(MailBox);




    return 0;
}
