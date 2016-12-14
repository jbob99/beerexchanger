#include "participant.hpp"

Participant::Participant(QString pName) : name(pName) {
}

Participant& Participant::operator=(const Participant& other) {
    name = other.name;
    order = other.order;
    return *this;
}
