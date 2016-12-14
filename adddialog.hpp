#ifndef ADDDIALOG_HPP
#define ADDDIALOG_HPP

#include <QDialog>

namespace Ui { class AddDialog; }

class AddDialog : public QDialog {
    Q_OBJECT
private:
    Ui::AddDialog *ui;

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

private slots:
    void accept();

signals:
    void addParticipant(QString);

};

#endif // ADDDIALOG_HPP
