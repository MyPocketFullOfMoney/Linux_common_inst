#include "widget.h"
#include "ui_widget.h"
#include"practise.h"
#include"contest.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    QPixmap *pix;
    QString pixname;
    pixname=":/images/syu.png";
    pix=new QPixmap(pixname);
    ui->label_Picture->setPixmap(*pix);


    //统计Client前的初始化


    //获取本机 主机名 IP
    localHostName=QHostInfo::localHostName();
    localHostIP=getHostIPv4(localHostName);
    qDebug()<<localHostName<<localHostIP;


    sender=new QUdpSocket(this);
    receiver=new QUdpSocket(this);
    port=45454;
    porttcp=45458;

    //udp监听端口，关联槽函数
    receiver->bind(port+1,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(acceptServer()));

    //tcp部分
    loadSize=4*1024;
    totalBytes=0;
    bytesWritten=0;
    bytesToWrite=0;

    tcpClient=new QTcpSocket(this);
    //有新连接开始传送文件
    connect(tcpClient,SIGNAL(connected()),
            this,SLOT(sendFileHead()));

    connect(tcpClient,SIGNAL(bytesWritten(qint64)),
            this,SLOT(sendFile(qint64)));

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),
            this,SLOT(displayTime()));
    timer->start(1000);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_practise_clicked()
{
    practise w;
    w.setWindowTitle(tr("Practice"));
    w.exec();
}

void Widget::on_pushButton_example_clicked()
{
    Contest w;
    w.exec();
    if(w.success==1)
    {
        QFile *File;
        QString FileName;
        QByteArray line;
        FileName="Result"+w.Number+".dat";
        File=new QFile(FileName);
        if(File->exists())
        {
            QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("您已经参加过考试，不能再次参加"));
        }
        else
        {
            competition s;
            s.exec();
            if(s.success==1)
            {
                if (!File->open(QIODevice::WriteOnly | QIODevice::Text))
                {
                       qDebug()<<"Open fail";

                }
                else
                {
                    QTextStream out(File);
                    out<<w.Name<<endl;
                    out<<w.Number<<endl;
                    out<<w.Sex<<endl;
                    out<<w.Family<<endl;
                    out<<w.Class<<endl;
                    out<<s.ResultScore<<endl;
                }
                File->close();
                QString dat=w.Name+','+w.Number+',';
                char c=s.ResultScore/100+'0';
                if(c=='0')
                    dat+="0";
                else
                    dat+=c+"00";
                qDebug()<<dat;
                QFile file("ScoreUP.dat");
                if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
                {
                    qDebug()<<"ScoreUP.dat Open error";
                }
                else
                {
                     QTextStream out(&file);
                     out<<dat<<endl;
                     file.close();
                }
            }
        }

    }
    else
    {
         QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("请输入正确的信息"));
    }
}


void Widget::on_pushButton_score_clicked()
{
    score s;
    s.setWindowTitle(QString::fromUtf8("成绩统计"));
    s.exec();
}



QString Widget::getHostIPv4(QString hostName)
{
    QHostInfo Infotemp=QHostInfo::fromName(hostName);
    QString  IP=0;
    foreach(QHostAddress address,Infotemp.addresses())
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol)
        {
            IP=address.toString();
            break;
        }

    }
    return IP;
}

void Widget::acceptServer()
{

    QByteArray datagram=0;
    while(receiver->hasPendingDatagrams())  //拥有等待的数据报
    {

             //拥于存放接收的数据报
            datagram.resize(receiver->pendingDatagramSize());
            //让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
            receiver->readDatagram(datagram.data(),datagram.size());
            //接收数据报，将其存放到datagram中
            QDataStream in(&datagram,QIODevice::ReadOnly);
            QString messageType,message;
            QString HostName,ipAddress;
            in>>messageType>>message;
            in>>HostName>>ipAddress;
            qDebug()<<"received a data package";
            qDebug()<<messageType<<message<<HostName<<ipAddress;
        //}
            if(messageType=="SearchServer")
            {
                //这里需要记录已经连接的Client IP


                //给该Client回复消息
                sendUdpMessage("AcceptS","",ipAddress);
            }
            if(messageType=="RequestP")
            {
                sendProblems(ipAddress,porttcp);
            }
            if(messageType=="RequestTime")
            {
                sendUdpMessage("ServerTime",getServerTime(),ipAddress);
            }
            if(messageType=="ScoreUP")
            {
                QFile file("ScoreUP.dat");
                if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
                {
                    qDebug()<<"ScoreUP.dat Open error";
                }
                else
                {
                     QTextStream out(&file);
                     out<<message<<endl;
                     file.close();
                }


            }
    }
}

void Widget::sendUdpMessage(QString messageType, QString message, QString IPaddress)
{
    QByteArray datagram;
    QDataStream out(&datagram,QIODevice::WriteOnly);
    QHostAddress host;
    host.setAddress(IPaddress);
    out<<messageType<<message<<localHostName<<localHostIP;
    sender->writeDatagram(datagram.data(),datagram.size(),
                    host,port);
    qDebug()<<localHostName<<localHostIP<<"Send data package";
}

void Widget::lianjieTCP(QString IPaddress, quint16 port)
{
    bytesWritten=0;
    QHostAddress *ss=new QHostAddress();
    ss->setAddress(IPaddress);
    tcpClient->connectToHost(*ss,port);

}
void Widget::sendFileHead()
{

    localFile=new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {

        qDebug()<<"Open file error";
        return ;
    }

    totalBytes=localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_8);
    QString currentFileName=fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFileName;
    totalBytes+=outBlock.size();

    sendOut.device()->seek(0);
    sendOut<<totalBytes<<qint64(outBlock.size()-sizeof(qint64)*2);
    bytesToWrite=totalBytes-tcpClient->write(outBlock);
    outBlock.resize(0);
}
void Widget::sendFile(qint64 numBytes)
{
    bytesWritten+=(int)numBytes;
    if(bytesToWrite>0)
    {

        outBlock=localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -=(int)tcpClient->write(outBlock);
        outBlock.resize(0);
    }
    else
        localFile->close();

    if(bytesWritten==totalBytes)
    {


        //tcpClient->disconnectFromHost();
        //tcpClient->waitForDisconnected();
        localFile->close();
        //tcpClient->close();
    }
}
void Widget::sendProblems(QString IPaddress,quint16 port)
{
    QString problemPath="problem/problem";
    int i=1;
    char tc[10];
    QFile *File;
    QString ProFileName,InFileName,OutFileName,SoutFileName;
    int Psum=100;
    for(i=1;i<=Psum;i++)
    {
        sprintf(tc,"%d",i);
        ProFileName=problemPath+tc+".txt";
        InFileName=problemPath+tc+".in";
        OutFileName=problemPath+tc+".out";
        SoutFileName=problemPath+tc+".sout";
        File=new QFile(ProFileName);
        if(File->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            TcpsendFile(ProFileName,IPaddress,port);
            qDebug()<<ProFileName<<"Open success";
            File->close();
        }
        File=new QFile(InFileName);
        if(File->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            TcpsendFile(InFileName,IPaddress,port);
            qDebug()<<InFileName<<"Open success";
            File->close();
        }
        File=new QFile(OutFileName);
        if(File->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            TcpsendFile(OutFileName,IPaddress,port);
            qDebug()<<OutFileName<<"Open success";
            File->close();
        }
        File=new QFile(SoutFileName);
        if(File->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            TcpsendFile(SoutFileName,IPaddress,port);
            qDebug()<<SoutFileName<<"Open success";
            File->close();
        }

    }
}
bool Widget::TcpsendFile(QString fileN,QString IPaddress,quint16 port)
{
    fileName=fileN;
    lianjieTCP(IPaddress,port);
    tcpClient->disconnectFromHost();
    tcpClient->waitForDisconnected(500);
    return true;
}

QString Widget::getServerTime()
{
    QDateTime ServerTime=QDateTime::currentDateTime();
    QString str = ServerTime.toString("hh:mm:ss");
    return str;
}

void Widget::displayTime()
{
    QString time=getServerTime();
    ui->label_Time->setText(time);
}

void Widget::on_pushButton_reSet_clicked()
{
    QString FileName="Result*";
    QString cmd;

    cmd="del /f "+FileName;
    qDebug()<<cmd;
    system((cmd.toStdString()).c_str());
    QFile file("ScoreUP.dat");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"Load ScoreUP error";
    }
    else
        file.write("",0);
    sendUdpMessage("ResetResult","","255.255.255.255");
}
