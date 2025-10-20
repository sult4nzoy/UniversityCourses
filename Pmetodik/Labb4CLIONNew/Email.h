//
// Created by OmarK on 2025-10-14.
//

#ifndef LABB4CLION_EMAIL_H
#define LABB4CLION_EMAIL_H

#include <iostream>
#include <string>
#include <tuple>


class Email {

public:
    std::string who;
    std::string subject;
    std::string date;
    Email(std::string who, std::string date, std::string subject);

    friend std::ostream& operator<<(std::ostream& os, const Email& e) {
        os << "Who: "<< e.who << ", Date: " << e.date << ", Subject: " << e.subject;
        return os;
    }
};

struct CompWhoDateSubject{
    bool operator()(const Email& lhs, const Email& rhs) const;
};


struct CompDateWhoSubject{
    bool operator()(const Email& lhs, const Email& rhs) const;
};

struct CompSubjectWheDate{
    bool operator()(const Email& lhs, const Email& rhs) const;
};

#endif //LABB4CLION_EMAIL_H