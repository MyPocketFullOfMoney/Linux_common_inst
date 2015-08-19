#ifndef SCORE_H
#define SCORE_H

#include <QDialog>
#include<QFile>
#include<QDebug>
#include<QDataStream>
#include<QtGui>
namespace Ui {
class score;
}

class score : public QDialog
{
    Q_OBJECT

public:
    explicit score(QWidget *parent = 0);
    ~score();

private slots:
    void on_pushButton_reset_clicked();

private:
    Ui::score *ui;
};

#endif // SCORE_H
