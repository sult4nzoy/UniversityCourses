//
// Created by OmarK on 2025-10-14.
//

#ifndef LABB4CLION_MAILBOX_H
#define LABB4CLION_MAILBOX_H
#include <vector>
#include "Email.h"


class MailBox {


public:
    MailBox();
    void SortWho();
    void SortDate();
    void SortSubject();
    void push_back(const Email& e);
    void printMailinMailBox() const;
private:
    std::vector<Email> mailbox;

};


#endif //LABB4CLION_MAILBOX_H