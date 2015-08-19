#ifndef PROCESS_H
#define PROCESS_H

#include <QDialog>
#include<QProcess>
#include<QtGui>
namespace Ui {
class Process;
}

class Process : public QDialog
{
    Q_OBJECT

public:
    explicit Process(QWidget *parent = 0);
    ~Process();
    void setInputFile(QString file);
    void setOutputFile(QString file);
    QString fileName,CompileResult,RunResult,InputFile,OutputFile;
    int CompileSuccess;
    QProcess *cmd1,*cmd2;

private:
    Ui::Process *ui;

private slots:
    void on_pushButton_Open_clicked();


    void on_pushButton_Compile_clicked();

    void on_pushButton_Run_clicked();

    void readOutput1();

    void readOutputError1();

    void readOutput2();

    void readOutputError2();

    void check1();

    void check2();




    void on_pushButton_Submit_clicked();
};

#endif // PROCESS_H
