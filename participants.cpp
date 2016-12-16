#include "participants.hpp"

/*******************************************************************************
 *
 */
Participants::Participants(QObject* parent) : QAbstractListModel(parent) {
    savePath = QDir::currentPath().toStdString() + "/" + FILENAME;
    cout << savePath << endl;
    load();
}

/*******************************************************************************
 *
 */
int Participants::rowCount(const QModelIndex &parent) const {
    if(parent.isValid()) ;
    return participants.size();
}

/*******************************************************************************
 *
 */
int Participants::columnCount(const QModelIndex &parent) const {
    if(parent.isValid()) ;
    return 1;
}

/*******************************************************************************
 *
 */
QVariant Participants::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int col = index.column();

    if(role == Qt::DisplayRole) {
        switch(col) {
        case 0:
            Participant p = participants.at(row);
            return QString("%1").arg(p.getName());
        }

    }

    return QVariant();
}

/*******************************************************************************
 *
 */
bool Participants::removeRow(int row, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row);
    participants.removeAt(row);
    endRemoveRows();
    emit dataChanged(QModelIndex(), QModelIndex());
}

/*******************************************************************************
 *
 */
QList<Participant> Participants::randomize() {
    if(size() <= 0) {
        cout << "There is nothing to do." << endl;
        return participants;
    }
    for(int k = 0; k < 50; ++k) {
        for(int x = 0; x < participants.size(); ++x) {
            int rnd = getRandom();
            Participant a = participants.at(rnd);
            Participant b = participants.at(x);
            participants.removeAt(rnd);
            participants.insert(rnd, b);
            participants.removeAt(x);
            participants.insert(x, a);
        }
    }

    emit dataChanged(QModelIndex(), QModelIndex());

    return participants;
}

/*******************************************************************************
 *
 */
QString Participants::get(const int index) {
    if(index < 0) {
        return "Cannot access negative index";
    }

    if(index >= size()) {
        return "No more remains";
    }

    return participants.at(index).getName();
}

/*******************************************************************************
 *
 */
void Participants::addParticipant(Participant p) {
    beginInsertRows(QModelIndex(),
                    rowCount(QModelIndex()),
                    rowCount(QModelIndex()));
        participants.append(p);
    endInsertRows();
}

/*******************************************************************************
 *
 */
void Participants::clearParticipants() {
    while(size()) {
        removeRow(0, QModelIndex());
    }
}

/*******************************************************************************
 *
 */
void Participants::load() {
    ifstream fin(savePath.c_str());
    if(fin.is_open()) {
        string fname;

        while(fin.good()) {
            getline(fin, fname, ',');
            QString name;
            name.append(QString::fromStdString(fname));
            if(!name.isEmpty()) {
                participants.append(Participant(name));
            }
        }
		fin.close();
    } else {
		cout << "File does not exist" << endl;
	}
}

/*******************************************************************************
 *
 */
void Participants::save() {

    ofstream fout(savePath.c_str());

    for(int k = 0; k < participants.size(); ++k) {
        Participant p = participants.at(k);
        fout << p << ",";
    }
	fout.close();
}

/*******************************************************************************
 *
 */
int Participants::getRandom() const {
    return rand() % (participants.size());
}
