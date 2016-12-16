#ifndef PARTICIPANTS_HPP
#define PARTICIPANTS_HPP

#include <QAbstractListModel>
#include <participant.hpp>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

const string FILENAME = "participants.dat";

class Participants : public QAbstractListModel {
private:
    QList<Participant> participants;

    void load();
    void save();
    int getRandom() const;

public:
    Participants(QObject* parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool removeRow(int row, const QModelIndex &parent);

    QList<Participant> randomize();

    QString get(const int index);

    void addParticipant(Participant p);
    void clearParticipants();

    bool isEmpty() const { return participants.size() == 0; }
    bool size() const { return participants.size(); }

    ~Participants() { save(); }
};

#endif // PARTICIPANTS_HPP
