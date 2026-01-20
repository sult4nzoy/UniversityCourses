//
// Created by OmarK on 2025-10-14.
//

#include "Email.h"

Email::Email(std::string who, std::string date,std::string subject) : who(who), date(date),subject(subject)
{}

bool CompWhoDateSubject::operator()(const Email& lhs, const Email& rhs) const {
    if (lhs.who != rhs.who) {
        return lhs.who < rhs.who;
    }
    if (lhs.date != rhs.date) {
        return lhs.date < rhs.date;
    }
    return lhs.subject < rhs.subject;
}

bool CompDateWhoSubject::operator()(const Email& lhs, const Email& rhs) const {
    if (lhs.date != rhs.date) {
        return lhs.date < rhs.date;
    }
    if (lhs.who != rhs.who) {
        return lhs.who < rhs.who;
    }
    return lhs.subject < rhs.subject;
}

bool CompSubjectWheDate::operator()(const Email& lhs, const Email& rhs) const {
    if (lhs.subject != rhs.subject) {
        return lhs.subject < rhs.subject;
    }
    if (lhs.who != rhs.who) {
        return lhs.who < rhs.who;
    }
    return lhs.date < rhs.date;
}