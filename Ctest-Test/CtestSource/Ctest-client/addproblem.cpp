#include "addproblem.h"
#include "ui_addproblem.h"

AddProblem::AddProblem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProblem)
{
    ui->setupUi(this);
    setWindowTitle("Add problem");
    isOnlyOut=0;
    success=0;
}

AddProblem::~AddProblem()
{
    delete ui;
}

void AddProblem::on_pushButton_Cancle_clicked()
{
    accept();
}

void AddProblem::on_pushButton_Reset_clicked()
{
    ui->lineEdit_ProblemName->clear();
    ui->textEdit_Problem->clear();
    ui->textEdit_SamInput->clear();
    ui->textEdit_SamOutput->clear();
    ui->textEdit_StdOutput->clear();
}

void AddProblem::on_pushButton_Accept_clicked()
{
    ProblemName=ui->lineEdit_ProblemName->text();
    Problem=ui->textEdit_Problem->toPlainText();
    Input=ui->textEdit_SamInput->toPlainText();
    Output=ui->textEdit_SamOutput->toPlainText();
    StdOutput=ui->textEdit_StdOutput->toPlainText();
    if(!StdOutput.isEmpty())
        isOnlyOut=1;
    success=1;
    accept();
}
void AddProblem::setProblem(QString PName,QString Pro,QString Inp,QString Out,QString Sout)
{
    ui->lineEdit_ProblemName->setText(PName);
    ui->textEdit_Problem->setText(Pro);
    ui->textEdit_SamInput->setText(Inp);
    ui->textEdit_SamOutput->setText(Out);
    ui->textEdit_StdOutput->setText(Sout);
}
