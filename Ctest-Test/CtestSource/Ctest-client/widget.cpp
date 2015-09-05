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
    pixname=":images/syu.png";
    pix=new QPixmap(pixname);
    ui->label_Picture->setPixmap(*pix);
    ui->label_state->setText(QString::fromUtf8("服务器未连接"));

    //获取本机 主机名 IP
    localHostName=QHostInfo::localHostName();
    localHostIP=getHostIPv4(localHostName);
    qDebug()<<localHostName<<localHostIP;


    //初始化服务器信息
    ServerName.clear();
    ServerAddress.clear();

    sender=new QUdpSocket(this);
    receiver=new QUdpSocket(this);
    port=45454;
    porttcp=45458;

    //UDP监听端口，关联槽函数
    receiver->bind(port,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(authenServer()));

    //tcp
    totalBytes=0;
    bytesReceived=0;
    fileNameSize=0;
    tcpServer=new QTcpServer(this);
    connect(tcpServer,SIGNAL(newConnection()),
            this,SLOT(acceptConnecion()));


    QHostAddress *ss=new QHostAddress();
    ss->setAddress(localHostIP);
    if(!tcpServer->listen(*ss,porttcp))
    {

        qDebug()<<tcpServer->errorString();
        close();
        return ;
    }

    //广播搜索服务器
    timer=new QTimer();
    speed=1000;
    connect(timer,SIGNAL(timeout()),
            this,SLOT(searchServer()));
    timer->start(speed);


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
                if (!File->open(QIODevice::WriteOnly ))
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
                //dat+="\n";
                qDebug()<<dat;
                sendUdpMessage("ScoreUP",dat,ServerAddress);
            }
        }

    }
    else
    {
         QMessageBox::warning(this,QString::fromUtf8("警告"),QString::fromUtf8("请输入正确的信息"));
    }
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
//搜索服务器的片段
void Widget::searchServer()
{
    //构造数据
    QByteArray datagram;
    //使用数据流
    QDataStream tmpOut(&datagram,QIODevice::WriteOnly);
    //初始化数据
    QString messageType=tr("SearchServer");
    QString message=tr("");
    //按照约定好的协议，依次写入数据。
    tmpOut<<messageType<<message<<localHostName<<localHostIP;
    //设置状态标签
    ui->label_state->setText(tr("寻找服务器..."));
    //写入数据
    sender->writeDatagram(datagram.data(),datagram.size(),
                    QHostAddress::Broadcast,port+1);
    qDebug()<<localHostIP<<"Broadcast for search Server";
}

void Widget:: authenServer()
{
    QByteArray datagram=0;
    if(receiver->hasPendingDatagrams())  //拥有等待的数据报
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
            qDebug()<<messageType<<HostName<<ipAddress;

            if(messageType=="AcceptS")
            {

                ServerName=HostName;
                ServerAddress=ipAddress;
                ui->label_state->setText(QString::fromUtf8("服务器已连接"));
                sendUdpMessage("RequestP","",ServerAddress);
                sendUdpMessage("RequestTime","",ServerAddress);
            }
            if(messageType=="ServerTime")
            {
                ui->label_Time->setText(message);
            }
            if(messageType=="ResetResult")
            {
                QString FileName="Result*";
                QString cmd;

                cmd="del /f "+FileName;
                qDebug()<<cmd;
                system((cmd.toStdString()).c_str());
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
                    host,port+1);
    qDebug()<<localHostName<<localHostIP<<"Send data package";
}

void Widget::reinit()
{
    totalBytes=0;
    bytesReceived=0;
    fileNameSize=0;
}
void Widget::acceptConnecion()
{
    tcpServerConnection=tcpServer->nextPendingConnection();
    connect(tcpServerConnection,SIGNAL(readyRead()),
            this,SLOT(updateServerProcess()));
    QDir *tempDir = new QDir;
    bool exist = tempDir->exists("problem");
    if(!exist) {
        ui->label_state->setText("接受服务器数据连接");
    }


}
void Widget::updateServerProcess()
{
    QDataStream in(tcpServerConnection);
    in.setVersion(QDataStream::Qt_4_8);
    if(bytesReceived<=sizeof(qint64)*2)
    {

        if(tcpServerConnection->bytesAvailable()>=sizeof(qint64)*2 && (fileNameSize==0))
        {
            in>>totalBytes>>fileNameSize;
            bytesReceived+=sizeof(qint64)*2;

        }
        if(tcpServerConnection->bytesAvailable()>=fileNameSize && (fileNameSize!=0))
        {

            in>>fileName;

            QDir *tempDir = new QDir;
            bool exist = tempDir->exists("problem");
            if(!exist) {
               if( tempDir->mkdir("problem") )
               qDebug() << (tr("文件夹创建成功！"));
            }
            localFile=new QFile("problem//"+fileName);
            if(localFile->exists()) {
                ui->label_state->setText("考题下载完成！");
                //return ;
            } else {
            ui->label_state->setText(tr("接收考题文件 %1 ...")
                                            .arg(fileName));
            }

            bytesReceived+=fileNameSize;

            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug()<<"Open file fail";
                return ;
            }
        }
        else
            return ;
    }
    if(bytesReceived<totalBytes)
    {

        bytesReceived+=tcpServerConnection->bytesAvailable();
        inBlock=tcpServerConnection->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    if(bytesReceived==totalBytes)
    {
        //tcpServerConnection->disconnectFromHost();
        //tcpServerConnection->waitForDisconnected(1000);
        //tcpServerConnection->close();

        //tcpServer->close();
        localFile->close();
        //qDebug() << (tr("考题%1传输完毕！").arg(fileName));

        reinit();
    }

}

void Widget::on_pushButton_end_clicked()
{
    close();
}

bool Widget::removeFolderContent(const QString &folderDir)
{
    QDir dir(folderDir);
    QFileInfoList fileList;
    QFileInfo curFile;
    if(!dir.exists())  {return false;}//文件不存，则返回false
    fileList=dir.entryInfoList(QDir::Dirs|QDir::Files
                               |QDir::Readable|QDir::Writable
                               |QDir::Hidden|QDir::NoDotAndDotDot
                               ,QDir::Name);
    while(fileList.size()>0)//跳出条件
    {
        int infoNum=fileList.size();
        for(int i=infoNum-1;i>=0;i--)
        {
            curFile=fileList[i];
            if(curFile.isFile())//如果是文件，删除文件
            {
                QFile fileTemp(curFile.filePath());
                fileTemp.remove();
                fileList.removeAt(i);
            }
            if(curFile.isDir())//如果是文件夹
            {
                QDir dirTemp(curFile.filePath());
                QFileInfoList fileList1=dirTemp.entryInfoList(QDir::Dirs|QDir::Files
                                                              |QDir::Readable|QDir::Writable
                                                              |QDir::Hidden|QDir::NoDotAndDotDot
                                                              ,QDir::Name);
                if(fileList1.size()==0)//下层没有文件或文件夹
                {
                    dirTemp.rmdir(".");
                    fileList.removeAt(i);
                }
                else//下层有文件夹或文件
                {
                    for(int j=0;j<fileList1.size();j++)
                    {
                        if(!(fileList.contains(fileList1[j])))
                            fileList.append(fileList1[j]);
                    }
                }
            }
        }
    }
   return true;
}
void Widget::closeEvent(QCloseEvent *event)
{
//    QString FilePath="problem";
//    QString cmd;

//    cmd="del /q /s "+FilePath;
//    qDebug()<<cmd;
//    system((cmd.toStdString()).c_str());
    QDir *dir = new QDir;
    if(removeFolderContent("problem"))
        if(dir->rmdir("problem"))
            qDebug() << (tr("所有考题删除成功！"));
        else
            qDebug() << (tr("考题删除失败！"));
    else
        qDebug() << (tr("考题删除失败！"));

    event->accept();
}
