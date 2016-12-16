#include "mainwindow.hpp"
#include "ui_mainwindow.h"

/*******************************************************************************
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initVariables();
    initInterface();
    createConnections();
    updateUI();
    ui->btnAdd->setFocus();
}

/*******************************************************************************
 *
 */
void MainWindow::onAdd() {
    delete addDialog;
    addDialog = new AddDialog(this);

    connect(addDialog,
            SIGNAL(addParticipant(QString)),
            this,
            SLOT(addParticipant(QString)));

    addDialog->open();
}

/*******************************************************************************
 *
 */
void MainWindow::addParticipant(QString name) {
    model->addParticipant(Participant(name));
    updateUI();
}

/*******************************************************************************
 *
 */
void MainWindow::onRemove() {
    int row = ui->listView->currentIndex().row();
    model->removeRow(row, QModelIndex());
}

/*******************************************************************************
 *
 */
void MainWindow::onClear() {
    model->clearParticipants();
}

/*******************************************************************************
 *
 */
void MainWindow::onArrange() {

    randomized = model->randomize();

    if(randomized.size() <= 0) {
        QString m = "Unable to arrange...nothing!  Please add something.";
        cout << m.toStdString() << endl;
        QMessageBox* msg = new QMessageBox(QMessageBox::Critical,
                                           "Emtpy List",
                                           m,
                                           QMessageBox::Ok);
        msg->open();
        return;
    }

    QPixmap down = QPixmap(DOWN_ARROW);
    ui->lblArrow->show();
    down.scaled(25, 125, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->lblArrow->setPixmap(down);

    pointer = 0;
    ui->runFrame->show();

    direction = FORWARD;

    ui->listView->setCurrentIndex(model->index(0));

    ui->lblNegTwo->setText(getName(randomized.size() - 2));
    ui->lblNegOne->setText(getName(randomized.size() - 1));
    ui->lblOnDeck->setText(getName(0));
    ui->lblPlusOne->setText(getName(1));
    ui->lblPlusTwo->setText(getName(2));

    averageTime = 0.0f;
    served = 0;
    sum = 0;
    ui->clock->display("0");
    ui->lblAverage->hide();
    timer->stop();
    timer->start();
    ui->btnNext->setFocus();
    totalNumBeers = model->rowCount(QModelIndex()) * NUM_BEERS_PER_PERSON;
    cout << totalNumBeers << endl;
    ui->lblTotalBeers->setText(QString::number(totalNumBeers));
    ui->lblRemaining->setText(QString::number(totalNumBeers));
    ui->lblDistributed->setText("0");
    active = true;
    endOfList = false;
    firstRun = true;
}

/*******************************************************************************
 *
 */
void MainWindow::onNext() {

    if(!isActive()) {
        return;
    }
    ++served;

    ++numBeersDist;

    resetTimer();

    if(endOfList == true) {
        endOfList = false;
        updateUI();
        return;
    }

    int negTwo, negOne, plusOne, plusTwo;

    if( (pointer + 1) >= randomized.size() && !firstRun) {
        direction = REVERSE;
    } else if(pointer <= 0 && !firstRun) {
        direction = FORWARD;
    }

    if(firstRun) {
        firstRun = false;
    }

    if(direction == FORWARD) {
        ++pointer;
    } else {
        --pointer;
    }
    negTwo;
    negOne = pointer - 1;
    if(pointer == 0) {
        negOne = randomized.size() - 1;
        negTwo = negOne - 1;
    }

    negTwo = negOne - 1;
    if(negTwo < 0) {
        negTwo = randomized.size() - 1;
    }

    plusOne = pointer + 1;
    if(plusOne >= randomized.size()) {
        plusOne = 0;
    }

    plusTwo = plusOne + 1;
    if(plusTwo >= randomized.size()) {
        plusTwo = 0;
    }

    ui->lblNegTwo->setText(getName(negTwo));
    ui->lblNegOne->setText(getName(negOne));
    ui->lblOnDeck->setText(getName(pointer));
    ui->lblPlusOne->setText(getName(plusOne));
    ui->lblPlusTwo->setText(getName(plusTwo));

    ui->listView->setCurrentIndex(model->index(pointer));

    if(pointer == 0) {
        QPixmap down = QPixmap(DOWN_ARROW);
        down.scaledToWidth(25);
        ui->lblArrow->setPixmap(down);
        endOfList = true;
    }

    if(pointer == randomized.size()-1) {
        QPixmap up = QPixmap(UP_ARROW);
        up.scaledToWidth(25);
        ui->lblArrow->setPixmap(up);
        endOfList = true;
    }
    updateUI();
}

/*******************************************************************************
 *
 */
void MainWindow::updateUI() {
    ui->btnClear->setEnabled( (model->isEmpty() ? false : true) );
    int c = ui->listView->selectionModel()->selectedRows().size();
     ui->btnRemove->setEnabled(c > 0);
     ui->lblDistributed->setText(QString::number(numBeersDist));
     ui->lblRemaining->setText(QString::number(totalNumBeers - numBeersDist));
}

/*******************************************************************************
 *
 */
QString MainWindow::getName(const int loc) const {
    return randomized.at(loc).getName();
}

/*******************************************************************************
 *
 */
void MainWindow::updateTimer() {
    int time = ui->clock->intValue();
    time += 1;
    ui->clock->display(QString::number(time));
}

/*******************************************************************************
 *
 */
void MainWindow::resetTimer() {
    timer->stop();
    int time = ui->clock->intValue();
    ui->clock->display("0");
    computeAverage(time);
    timer->start();
}

/*******************************************************************************
 *
 */
float MainWindow::computeAverage(int time) {

    sum += time;
    averageTime = sum / served;
    ui->lblAverage->setText(QString::number(averageTime));
    ui->lblArrow->show();
    ui->lblAverage->show();
    ui->lblSeconds->show();
    ui->lblAverageTimeLabel->show();

}

/*******************************************************************************
 *
 */
void MainWindow::createConnections() {
    connect(ui->btnAdd, SIGNAL(clicked(bool)), this, SLOT(onAdd()));
    connect(ui->btnRemove, SIGNAL(clicked(bool)), this, SLOT(onRemove()));
    connect(ui->btnClear, SIGNAL(clicked(bool)), this, SLOT(onClear()));
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(updateUI()));
    connect(ui->btnArrange, SIGNAL(clicked(bool)), this, SLOT(onArrange()));
    connect(ui->btnNext, SIGNAL(clicked(bool)), this, SLOT(onNext()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
}

/*******************************************************************************
 *
 */
void MainWindow::initVariables() {
    model = new Participants(this);
    pointer = 0;
    addDialog = NULL;
    timer = new QTimer(ui->clock);
    timer->setInterval(1000);
    averageTime = 0.0f;
    sum = served = 0;
    active = false;
    numBeersDist = 0;
}

/*******************************************************************************
 *
 */
void MainWindow::initInterface() {
    ui->lblNegTwo->setText("");
    ui->lblNegOne->setText("");
    ui->lblOnDeck->setText("");
    ui->lblPlusOne->setText("");
    ui->lblPlusTwo->setText("");
    ui->runFrame->hide();
    ui->lblArrow->hide();
    ui->lblAverage->hide();
    ui->lblSeconds->hide();
    ui->lblAverageTimeLabel->hide();
    ui->listView->setModel(model);
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    event->accept();
    switch(event->key()) {
    case Qt::Key_PageDown:
        onNext();
        break;
    }
}

/*******************************************************************************
 *
 */
MainWindow::~MainWindow() {
    delete ui;
    delete addDialog;
    delete timer;
    delete model;
}
