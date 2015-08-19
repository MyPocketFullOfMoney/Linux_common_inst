#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"competition.h"
#include"profile.h"
#include"score.h"


#include<QtNetwork>
#include<QTimer>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QString getHostIPv4(QString hostName);

    void sendUdpMessage(QString messageType,QString message,QString IPaddress);

    void lianjieTCP(QString IPaddress,quint16 port);

    void sendProblems(QString IPaddress,quint16 port);

    bool TcpsendFile(QString fileN,QString IPaddress,quint16 port);

    QString getServerTime();

private slots:
    void on_pushButton_practise_clicked();

    void on_pushButton_example_clicked();

    void on_pushButton_score_clicked();

    void acceptServer();

    void sendFileHead();

    void sendFile(qint64 numBytes);

    void displayTime();

    void on_pushButton_reSet_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *sender,*receiver;
    QString localHostName;
    QString localHostIP;
    QString ServerAddress;
    quint16 port;
    quint64 porttcp;
    long ClinetNum;

    QTcpSocket  *tcpClient;
    QFile   *localFile;
    qint64  totalBytes;
    qint64  bytesWritten;
    qint64  bytesToWrite;
    qint64  loadSize;
    QString fileName;
    QByteArray  outBlock;

    QTimer *timer;


};

#endif // WIDGET_H
