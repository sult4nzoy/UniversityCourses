//
// Created by OmarK on 2025-10-14.
//

#include "MailBox.h"

#include <algorithm>

#include "Email.h"

MailBox::MailBox()
{}

void MailBox::SortWho() {
    std::sort(mailbox.begin(), mailbox.end(), CompWhoDateSubject());
}

void MailBox::SortDate() {
    std::sort(mailbox.begin(), mailbox.end(), CompDateWhoSubject());
}

void MailBox::SortSubject() {
    std::sort(mailbox.begin(), mailbox.end(), CompSubjectWheDate());
}

void MailBox::push_back(const Email &e) {
    mailbox.push_back(e);
}

void MailBox::printMailinMailBox() const {
        for (auto &e : mailbox) {
            std::cout << e << std::endl;
        }
    }

