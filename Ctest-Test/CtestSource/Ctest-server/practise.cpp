#include "practise.h"
#include "ui_practise.h"
#include<QDebug>
#include<QTextCodec>
practise::practise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::practise)
{

    ui->setupUi(this);
   // setWindowFlags(Qt::CustomizeWindowHint);
    ProblemList =ui->listWidget_ProblemList;
    //ProblemList->addItem(tr("问题一"));
    Problempath="problem/problem";

    ProblemNum=0;
    memset(Score,0,sizeof(Score));
#ifdef GB
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
        if (codec) {
            QTextCodec::setCodecForTr(codec);
            QTextCodec::setCodecForLocale(codec);
            QTextCodec::setCodecForCStrings(codec);
        }
#endif
    load_Problem();
    connect(ProblemList,SIGNAL(currentRowChanged(int)),this,SLOT(change(int)));
}

practise::~practise()
{
    delete ui;
}
void practise::load_Problem()
{

    int i=1;
    char tc[10];
    QFile *File;
    QString FileName;
    QTextStream *in;
    QString line;
    qDebug()<<"Loading";
    do
    {
        sprintf(tc,"%d",i);
        FileName=Problempath+tc+".txt";
        //qDebug()<<"Open the file:"<<FileName;
        File=new QFile(FileName);
        if (!File->open(QIODevice::ReadOnly | QIODevice::Text))
        {
               //qDebug()<<"Open fail";

        }
        else
        {
            line =line.fromLocal8Bit(File->readLine());
            QStringList SL=line.split('\n');
            line=SL.at(0);
            qDebug()<<"File's first Line"<<line;
            ProblemList->addItem(line);
            ProblemNum++;
            ProblemName[i]=line;
            File->close();
        }

        i++;
    }while(i<=PROBLEMSUM);

    File=new QFile("score.dat");
    if (!File->open(QIODevice::ReadOnly | QIODevice::Text))
    {
           qDebug()<<"Open score fail";

    }
    else
    {

        in=new QTextStream(File);
        i=1;
        while(!in->atEnd())
        {
            Score[i]=in->readLine().toInt();
            i++;
        }
        File->close();

    }

}
int practise::GetOrd(QString name)
{
    int i=0;
    int ans=0;
    while(i<PROBLEMSUM)
    {
        if(ProblemName[i]==name)
        {
            ans=i;
            break;
        }
        i++;
    }
    return ans;
}
void practise::change(int row)
{
    if(row<0)
        return ;
    char tc[10];
    QString FileTmp,FileName,FileIn,FileOut;
    QFile *File;
    QTextStream *in;
    int Ord=GetOrd(ProblemList->currentItem()->text());
    sprintf(tc,"%d",Ord);
    //if(Ord>0)
    //   qDebug()<<ProblemList->currentItem()->text()<<Ord;
    //sprintf(tc,"%d",row+1);

    ui->textEdit_SamInput->clear();
    ui->textEdit_SamOutput->clear();

    FileTmp=Problempath+tc;
    FileName=FileTmp+".txt";
    FileIn=FileTmp+".in";
    FileOut=FileTmp+".out";
    //qDebug()<<"arrived at the file:"<<FileTmp;

    File=new QFile(FileName);
    if(!File->open(QFile::ReadOnly|QFile::Text))
    {
        //QMessageBox::warning(this,tr("Open file"),tr("can't open"));

    }
    in=new QTextStream(File);
    ui->textEdit_problmeText->setText(in->readAll());
    File->close();

    File=new QFile(FileIn);
    if(!File->open(QFile::ReadOnly|QFile::Text))
    {
        //QMessageBox::warning(this,tr("Open file"),tr("can't open"));

    }
    in=new QTextStream(File);
    ui->textEdit_SamInput->setText(in->readAll());
    File->close();

    File=new QFile(FileOut);
    if(!File->open(QFile::ReadOnly|QFile::Text))
    {
        //QMessageBox::warning(this,tr("Open file"),tr("can't open"));

    }
    in=new QTextStream(File);
    ui->textEdit_SamOutput->setText(in->readAll());
    File->close();

    ui->lineEdit_Score->setText(QString::number(Score[Ord]));

}

void practise::on_pushButton_Practise_clicked()
{
    int row=GetOrd(ProblemList->currentItem()->text());
    if(row>0&&row<=ProblemNum)
    {
        char tc[10];
        QString FileTmp,FileIn,FileSout;
        sprintf(tc,"%d",row);
        FileTmp=Problempath+tc;
        FileIn=FileTmp+".in";
        FileSout=FileTmp+".sout";


        Process w;
        QFile *FileInput=new QFile(FileIn);
        if(FileInput->exists())
            w.setInputFile(FileIn);
        w.setWindowTitle(ProblemName[row]);
        w.exec();
        QString Result1=w.RunResult;
        QString Result2=ui->textEdit_SamOutput->toPlainText();
        if(Result2.isEmpty())
        {
            QFile *sout=new QFile(FileSout);
            qDebug()<<"StdOutput";
            if (!sout->open(QIODevice::ReadOnly | QIODevice::Text))
            {
                   qDebug()<<"Open fail";

            }
            else
            {
                Result2=sout->readAll();
                sout->close();
            }

        }        
        qDebug()<<"Result Compare:"<<endl<<Result1.trimmed()<<endl<<Result2.trimmed();
        if(Result1.trimmed()==Result2.trimmed())
        {
            QMessageBox::warning(this,tr("Accepted"),tr("You get 100 points!"));
            Score[row]=100;
            ui->lineEdit_Score->setText("100");
        }
        else
            QMessageBox::warning(this,tr("Wrong answer"),tr("Please try again!"));
    }
    else
    {
        QMessageBox::warning(this,tr("Practise"),tr("Please choose the problem first!"));

    }
}

void practise::on_pushButton_Exit_clicked()
{
    QFile *File;

    File=new QFile("score.dat");
    if (!File->open(QIODevice::WriteOnly | QIODevice::Text))
    {
           qDebug()<<"Open score fail";

    }
    else
    {

        QTextStream out(File);
        for(int i=1;i<=PROBLEMSUM;i++)
            out<<Score[i]<<endl;

        File->close();
    }

    accept();
}

void practise::on_pushButton_ProAdd_clicked()
{
   AddProblem w;
   w.exec();
   if(w.success==1)
   {
       char tc[10];
       QString FileTmp,FileName,FileIn,FileOut,FileSout;
       QFile *File;
       ProblemNum++;
       sprintf(tc,"%ld",ProblemNum);
       FileTmp=Problempath+tc;
       FileName=FileTmp+".txt";
       FileIn=FileTmp+".in";
       FileOut=FileTmp+".out";
       FileSout=FileTmp+".sout";
       File=new QFile(FileName);
       if(!File->open(QFile::WriteOnly|QFile::Text))
       {
           QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

       }
       QTextStream out(File);
       out<<w.ProblemName<<endl<<w.Problem;
       File->close();

       if(w.isOnlyOut==0)
       {
           File=new QFile(FileIn);
           if(!File->open(QFile::WriteOnly|QFile::Text))
           {
               QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

           }
           QTextStream out2(File);
           out2<<w.Input;
           File->close();

           File=new QFile(FileOut);
           if(!File->open(QFile::WriteOnly|QFile::Text))
           {
               QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

           }
           QTextStream out3(File);
           out3<<w.Output;
           File->close();
       }
       else
       {
           File=new QFile(FileSout);
           if(!File->open(QFile::WriteOnly|QFile::Text))
           {
               QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

           }
           QTextStream out4(File);
           out4<<w.StdOutput;
           File->close();
       }

       Score[ProblemNum]=0;

       ProblemList->addItem(w.ProblemName);
       ProblemName[ProblemNum]=w.ProblemName;

   }
}

void practise::on_pushButton_ProDel_clicked()
{
    QListWidgetItem *Item;
    int row=GetOrd(ProblemList->currentItem()->text());
    qDebug()<<row;
    if(row>0&&row<=ProblemNum)
    {
        Item=ProblemList->currentItem();
        ProblemList->removeItemWidget(Item);

    }
    ui->lineEdit_Score->clear();
    ui->textEdit_problmeText->clear();
    ui->textEdit_SamInput->clear();
    ui->textEdit_SamOutput->clear();

    char tc[10];
    QString FileTmp,FileName,FileIn,FileOut,FileSout;
    QString FilePath="problem\\problem";
    QString cmd;
    sprintf(tc,"%d",row);
    FileTmp=FilePath+tc;
    FileName=FileTmp+".txt";
    FileIn=FileTmp+".in";
    FileOut=FileTmp+".out";
    FileSout=FileTmp+".sout";

    cmd="del /f "+FileName;
    qDebug()<<cmd;
    system((cmd.toStdString()).c_str());

    cmd="del /f "+FileIn;
    qDebug()<<cmd;
    system((cmd.toStdString()).c_str());

    cmd="del /f "+FileOut;
    qDebug()<<cmd;
    system((cmd.toStdString()).c_str());

    cmd="del /f "+FileSout;
    system((cmd.toStdString()).c_str());

    qDebug()<<"del OK";

    ProblemList->clear();
    ProblemNum=0;
    load_Problem();
    //QMessageBox::warning(this,tr("Remove"),tr("The problem has been removed,restart the soft will take effect"));
}

void practise::on_pushButton_ProEdit_clicked()
{

    AddProblem w;
    char tc[10];
    QFile *File;
    QString FileName,FileSout,PName,Problem,Input,Output,StdOutput;

    QByteArray line;

    int row=GetOrd(ProblemList->currentItem()->text());

    sprintf(tc,"%d",row);
    FileName=Problempath+tc+".txt";
    FileSout=Problempath+tc+".sout";

    qDebug()<<"Open the file:"<<FileName;

    File=new QFile(FileName);
    if (!File->open(QIODevice::ReadOnly | QIODevice::Text))
    {
           qDebug()<<"Open fail";

    }
    else
    {
        PName= File->readLine();
        qDebug()<<"File's first Line"<<line;
        while(!File->atEnd())
            Problem+=File->readLine();
        File->close();
    }

    File=new QFile(FileSout);
    if (!File->open(QIODevice::ReadOnly | QIODevice::Text))
    {
           qDebug()<<"Open fail";

    }
    else
    {
        StdOutput=File->readAll();
        File->close();
    }
    Input=ui->textEdit_SamInput->toPlainText();
    Output=ui->textEdit_SamOutput->toPlainText();
    w.setProblem(PName,Problem,Input,Output,StdOutput);
    w.exec();
    if(w.success==1)
    {
        char tc[10];
        QString FileTmp,FileName,FileIn,FileOut,FileSout;
        QFile *File;
        sprintf(tc,"%d",row);
        FileTmp=Problempath+tc;
        FileName=FileTmp+".txt";
        FileIn=FileTmp+".in";
        FileOut=FileTmp+".out";
        FileSout=FileTmp+".sout";

        File=new QFile(FileName);
        if(File->exists())
            File->remove();
        if(!File->open(QFile::WriteOnly|QFile::Text))
        {
            QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

        }
        QTextStream out(File);
        out<<w.ProblemName<<w.Problem;
        File->close();

        if(w.isOnlyOut==0)
        {
            File=new QFile(FileSout);
            if(File->exists())
                File->remove();

            File=new QFile(FileIn);
            if(File->exists())
                File->remove();
            if(!File->open(QFile::WriteOnly|QFile::Text))
            {
                QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

            }
            QTextStream out2(File);
            out2<<w.Input;
            File->close();

            File=new QFile(FileOut);
            if(File->exists())
                File->remove();
            if(!File->open(QFile::WriteOnly|QFile::Text))
            {
                QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

            }
            QTextStream out3(File);
            out3<<w.Output;
            File->close();
        }
        else
        {
            File=new QFile(FileIn);
            if(File->exists())
                File->remove();
            File=new QFile(FileOut);
            if(File->exists())
                File->remove();

            File=new QFile(FileSout);
            if(File->exists())
                File->remove();
            if(!File->open(QFile::WriteOnly|QFile::Text))
            {
                QMessageBox::warning(this,tr("Creat File"),tr("Can't creat file"));

            }
            QTextStream out4(File);
            out4<<w.StdOutput;
            File->close();

        }
        Score[row]=0;
        ProblemList->clear();
        ProblemNum=0;
        load_Problem();
    }

}
