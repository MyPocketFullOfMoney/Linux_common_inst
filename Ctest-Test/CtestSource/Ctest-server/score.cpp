#include "score.h"
#include "ui_score.h"

score::score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::score)
{
    ui->setupUi(this);
    QFile file("ScoreUP.dat");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Load ScoreUP error";
    }
    else
    {
        while (!file.atEnd())
        {
                QString line = file.readLine();
                QStringList  list=line.split(",");
                QString ls;
                int littleLength=40,tmp;
                for(int i=0;i<list.size();i++)
                {
                    ls+=list.at(i);
                    if(i<list.size()-1)
                    {
                        tmp=littleLength-list.at(i).length();
                        for(int j=0;j<=tmp;j++)
                        {
                            ls+=" ";
                        }
                        //ls+=">";
                    }
               }
                ui->textEdit->append(ls);
         }
        file.close();
    }
}

score::~score()
{
    delete ui;
}

void score::on_pushButton_reset_clicked()
{


    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, QString::fromUtf8("清除"),
    QString(QString::fromUtf8("确定要清除所有分数信息吗？")),
         (QMessageBox::Yes | QMessageBox::No));
        if (button == QMessageBox::No)
        {
            //button;  //忽略退出信号，程序继续运行
        }
        else if (button == QMessageBox::Yes)
        {
            ui->textEdit->clear();
            QFile file("ScoreUP.dat");
            if(!file.open(QIODevice::WriteOnly))
            {
                qDebug()<<"Load ScoreUP error";
            }
            else
                file.write("",0);
            file.close();
            //event->accept();  //接受退出信号，程序退出
        }

}
