#include "process.h"
#include "ui_process.h"

Process::Process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Process)
{
    ui->setupUi(this);
    cmd1=new QProcess;
    cmd2=new QProcess;
    CompileResult=tr("");
    RunResult=tr("");
    InputFile="";
    OutputFile="";
    connect(cmd1, SIGNAL(readyReadStandardOutput ()), this, SLOT(readOutput1()));
    connect(cmd1,SIGNAL(readyReadStandardError()),this,SLOT(readOutputError1()));
    connect(cmd1,SIGNAL(finished(int)),this,SLOT(check1()));

    connect(cmd2,SIGNAL(readyReadStandardOutput ()), this, SLOT(readOutput2())) ;
    connect(cmd2,SIGNAL(readyReadStandardError()),this,SLOT(readOutputError2()));
    connect(cmd2,SIGNAL(finished(int)),this,SLOT(check2()));

}

Process::~Process()
{
    delete ui;
}
void Process::on_pushButton_Open_clicked()
{
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        ui->lineEdit_Path->setText(fileName);
    }
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("Open the illegal file!"));

    }

}


void Process::on_pushButton_Compile_clicked()
{

    QString gcc=tr("gcc");
    QStringList arguments;
    ui->textEdit_Compile->clear();
    CompileResult=tr("");

    arguments<<fileName;
    cmd1->start(gcc,arguments);
    /*
     *gcc a+b.c
     *a.exe
     QObject *parent;
     ...
     QString program = "./path/to/Qt/examples/widgets/analogclock";
     QStringList arguments;
     arguments << "-style" << "motif";

     QProcess *myProcess = new QProcess(parent);
     myProcess->start(program, arguments);
    */
}

void Process::readOutput1()
{
    CompileResult+=cmd1->readAll();
    //ui->textEdit_Compile->setText(CompileResult);
}
void Process::readOutputError1()
{
    CompileResult+=cmd1->readAllStandardError();
    //ui->textEdit_Compile->setText(CompileResult);
}

void Process::check1()
{

    if(CompileResult.isEmpty())
    {
        ui->textEdit_Compile->setText(tr("Success!"));
        CompileSuccess=1;
    }
    else
    {
        ui->textEdit_Compile->setText(CompileResult);
        CompileSuccess=0;
    }
}

void Process::on_pushButton_Run_clicked()
{

   QString tmp=tr("a.exe");
   QStringList arguments;
   QFile File(tmp);
   ui->textEdit_Result->clear();
   //RunResult=tr("");
   if(CompileSuccess==1)
   {
       if(!File.exists())
           ui->textEdit_Result->setText("Not find '.exe' Program");
       else
       {
           if(!InputFile.isEmpty())
                cmd2->setStandardInputFile(InputFile);
            //cmd2->setStandardOutputFile("test.out");
           cmd2->start(tmp,arguments);
        }
   }
   else
   {
       ui->textEdit_Result->setText("Please Compile first!");
   }
}
void Process::readOutput2()
{
    RunResult=cmd2->readAll();

}
void Process::readOutputError2()
{
    RunResult+=cmd2->readAllStandardError();

}
void Process::check2()
{

    if(RunResult.isEmpty())
        ui->textEdit_Result->setText(tr("Run fail!"));
    else
        ui->textEdit_Result->setText(RunResult);

}
void Process::setInputFile(QString file)
{
    InputFile=file;
}

void Process::setOutputFile(QString file)
{
    OutputFile=file;
}

void Process::on_pushButton_Submit_clicked()
{
    system("del a.exe");
    this->accept();

}
