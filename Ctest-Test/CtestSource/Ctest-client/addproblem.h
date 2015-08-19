#ifndef ADDPROBLEM_H
#define ADDPROBLEM_H

#include <QDialog>

namespace Ui {
class AddProblem;
}

class AddProblem : public QDialog
{
    Q_OBJECT

public:
    explicit AddProblem(QWidget *parent = 0);
    ~AddProblem();
    QString ProblemName,Problem,Input,Output,StdOutput;
    int isOnlyOut;
    int success;
    void setProblem(QString PName,QString Pro,QString Inp,QString Out,QString Sout);
private slots:
    void on_pushButton_Cancle_clicked();

    void on_pushButton_Reset_clicked();

    void on_pushButton_Accept_clicked();

private:
    Ui::AddProblem *ui;
};

#endif // ADDPROBLEM_H
