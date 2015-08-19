#ifndef COMPETITION_H
#define COMPETITION_H
#define PROBLEMSUM 100
#define RANDSUM 10
#include <QDialog>
#include<QListWidget>
#include<QFile>
#include<QtGui>
#include<QTextStream>
#include"process.h"
#include"addproblem.h"
namespace Ui {
class competition;
}

class competition : public QDialog
{
    Q_OBJECT

public:
    explicit competition(QWidget *parent = 0);
    ~competition();
    void load_Problem();
    void profile(int num);

    QListWidget *ProblemList;
    long ProblemNum;
    int ProblemSum;

    QString ProblemName[PROBLEMSUM];
    int Score[PROBLEMSUM];
    int TestNum[PROBLEMSUM];
    QString Problempath;
    void closeEvent(QCloseEvent *event);
    int GetOrd(QString name);
    int ResultScore;
    int success;
private:
    Ui::competition *ui;
private slots:
    void change(int row);
    void on_pushButton_Practise_clicked();

    void on_pushButton_Sumit_clicked();
};

#endif // COMPETITION_H
