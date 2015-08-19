#ifndef CONTEST_H
#define CONTEST_H

#include <QDialog>

namespace Ui {
class Contest;
}

class Contest : public QDialog
{
    Q_OBJECT

public:
    explicit Contest(QWidget *parent = 0);
    ~Contest();
    QString Name,Number,Sex,Family,Class;
    int success;

private slots:
    void on_pushButton_accept_clicked();

private:
    Ui::Contest *ui;
};

#endif // CONTEST_H
