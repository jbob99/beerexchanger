#include "adddialog.hpp"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddDialog) {
    ui->setupUi(this);
}

void AddDialog::accept() {
    // do the stuff...
    QString name = ui->txtName->text();
    emit addParticipant(name);
    // And let the parent do the rest
    QDialog::accept();
}

AddDialog::~AddDialog()
{
    delete ui;
}
