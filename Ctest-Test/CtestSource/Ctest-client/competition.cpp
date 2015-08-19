#include "competition.h"
#include "ui_competition.h"
#include<ctime>
#include<QTextCodec>
competition::competition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition)
{
    ui->setupUi(this);
    setWindowTitle("contest is running");
    ProblemList =ui->listWidget_ProblemList;
    Problempath="problem/problem";
    ProblemNum=0;
    ProblemSum=4;
    ResultScore=0;
    success=0;
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

competition::~competition()
{
    delete ui;
}
void competition::load_Problem()
{

    int i,t;
    char tc[10];
    QFile *File;
    QString FileName;
    QString line;
    memset(Score,0,sizeof(Score));
    int RandNum[RANDSUM+1]={0};
    int n=RANDSUM;
    srand((unsigned) time(0));
    qDebug()<<"rand Ord is";
    //生成随机位置，位置为空才填充i
    t=1;
    for(i=1;i<=n;i++)
    {
        while(RandNum[t=rand()%10+1]);
        RandNum[t]=i;

        //RandNum[i]=rand()%10+1;
        qDebug()<<i<<t;
    }

    //随机生成题目
    t=0;
    for(i=1;i<=PROBLEMSUM;i++)
    {
        if(t>=ProblemSum)
            break;
        sprintf(tc,"%d",RandNum[i]);
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
            //qDebug()<<"File's first Line"<<line;
            ProblemNum++;
            ProblemName[RandNum[i]]=line;
            qDebug()<<"RandOrd is accept"<<RandNum[i];
            t++;
            ProblemList->addItem(line);

            File->close();
        }

    }

    if(t<ProblemSum)
        qDebug()<<"Problem less!!";


}
int competition::GetOrd(QString name)
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
void competition::change(int row)
{
    if(row<0)
        return ;
    char tc[10];
    QString FileTmp,FileName,FileIn,FileOut;
    QFile *File;
    QTextStream *in;
    int Ord=GetOrd(ProblemList->currentItem()->text());
    sprintf(tc,"%d",Ord);
    //sprintf(tc,"%d",row+1);
    FileTmp=Problempath+tc;
    FileName=FileTmp+".txt";
    FileIn=FileTmp+".in";
    FileOut=FileTmp+".out";
    qDebug()<<"arrived at the file:"<<FileTmp;

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

void competition::on_pushButton_Practise_clicked()
{
    int row=GetOrd(ProblemList->currentItem()->text());
    //int row=ProblemList->currentRow()+1;
    if(row>=0&&row<=PROBLEMSUM)
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
        if(Result1==Result2)
        {
            QMessageBox::warning(this,tr("Accepted"),tr("You get 100 points!"));
            if(Score[row]==0)
            {
            Score[row]=100;
            ui->lineEdit_Score->setText("100");
            ResultScore+=100;
            }
        }
        else
            QMessageBox::warning(this,tr("Wrong answer"),tr("Please try again!"));
    }
    else
    {
        QMessageBox::warning(this,tr("Practise"),tr("Please choose the problem first!"));

    }
}



void competition::on_pushButton_Sumit_clicked()
{
    success=1;
    close();

}
void competition::closeEvent(QCloseEvent *event)
{
    if(ResultScore<ProblemSum*100)
    {
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, QString::fromUtf8("提交"),
    QString(QString::fromUtf8("题目未全部完成，确定要提交吗？")),
         (QMessageBox::Yes | QMessageBox::No));
        if (button == QMessageBox::No) {
            event->ignore();  //忽略退出信号，程序继续运行
        }
        else if (button == QMessageBox::Yes) {
            event->accept();  //接受退出信号，程序退出
        }
    }

}
void competition::profile(int num)
{
    ProblemSum=num;
}
