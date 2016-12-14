#ifndef PARTICIPANT_HPP
#define PARTICIPANT_HPP

#include <QString>
#include <iostream>

using std::ostream;

class Participant {
private:
    QString name;
    int order;

public:
    Participant(QString pName);

    QString getName() const { return name; }
    int getOrder() const { return order; }
    void setOrder(int newOrder) { order = newOrder; }
    Participant& operator=(const Participant& other);

    ostream& print(ostream& out) { out << name.toStdString(); return out; }

    ~Participant() {}
};

inline ostream& operator<<(ostream& out, Participant& p) { return p.print(out);}

#endif // PARTICIPANT_HPP
