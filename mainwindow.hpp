#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "adddialog.hpp"
#include <QDebug>
#include <participants.hpp>
#include <participant.hpp>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPixmap>
#include <QMessageBox>
#include <QKeyEvent>

#include <iostream>

using namespace std;

const QString UP_ARROW = "://images/up-arrow.png";
const QString DOWN_ARROW = "://images/down-arrow.png";
const int NUM_BEERS_PER_PERSON = 12;

namespace Ui {
class MainWindow;
}

enum DIRECTION { FORWARD, REVERSE, DIRECTION_COUNT };

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    AddDialog* addDialog;
    Participants* model;
    QList<Participant> randomized;
    int pointer;
    QTimer* timer;
    float averageTime;
    int served;
    int sum;
    bool active;
    int numBeersDist;
    int totalNumBeers;
    bool endOfList;
    bool firstRun;

    DIRECTION direction;

    QString getName(const int loc) const;
    void resetTimer();
    float computeAverage(int time);
    void createConnections();
    void initVariables();
    void initInterface();

public:
    explicit MainWindow(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent* event);
    bool isActive() const { return active; }

    ~MainWindow();

private slots:
    void onAdd();
    void onRemove();
    void onClear();
    void onArrange();
    void onNext();
    void addParticipant(QString);
    void updateTimer();
    void updateUI();
};

#endif // MAINWINDOW_HPP
