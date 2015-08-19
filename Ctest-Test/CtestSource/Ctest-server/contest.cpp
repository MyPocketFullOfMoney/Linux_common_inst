#include "contest.h"
#include "ui_contest.h"

Contest::Contest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contest)
{
    ui->setupUi(this);
    setWindowTitle("Login");
    success=0;
}

Contest::~Contest()
{
    delete ui;
}

void Contest::on_pushButton_accept_clicked()
{
    Name=ui->lineEdit_Name->text();
    Number=ui->lineEdit_Number->text();
    Family=ui->lineEdit_Family->text();
    Sex=ui->lineEdit_Sex->text();
    Class=ui->lineEdit_Class->text();
    if(!Name.isEmpty()&&!Number.isEmpty())
        success=1;
    accept();
}
