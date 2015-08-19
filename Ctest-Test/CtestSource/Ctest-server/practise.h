#ifndef PRACTISE_H
#define PRACTISE_H

#include <QDialog>
#include<QListWidget>
#include<QFile>
#include<QtGui>
#include<QTextStream>
#include"process.h"
#include"addproblem.h"
#define PROBLEMSUM 100
namespace Ui {
class practise;
}

class practise : public QDialog
{
    Q_OBJECT

public:
    explicit practise(QWidget *parent = 0);
    ~practise();
    void load_Problem();
    int GetOrd(QString name);
    QListWidget *ProblemList;
    long ProblemNum;
    QString ProblemName[PROBLEMSUM+1];
    int Score[PROBLEMSUM+1];
    QString Problempath;
private:
    Ui::practise *ui;
private slots:
    void change(int row);
    void on_pushButton_Practise_clicked();
    void on_pushButton_Exit_clicked();
    void on_pushButton_ProAdd_clicked();
    void on_pushButton_ProDel_clicked();
    void on_pushButton_ProEdit_clicked();
};

#endif // PRACTISE_H
