#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QtNetwork>
#include"competition.h"
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
    void reinit();
    void closeEvent(QCloseEvent *);
private slots:
    void on_pushButton_practise_clicked();

    void on_pushButton_example_clicked();

    void authenServer();

    void acceptConnecion();

    void updateServerProcess();

    void searchServer();

    void on_pushButton_end_clicked();

    void on_label_Time_linkActivated(const QString &link);

    void on_label_Time_objectNameChanged(const QString &objectName);

    void on_label_state_windowTitleChanged(const QString &title);

private:
    Ui::Widget *ui;
    QUdpSocket *sender,*receiver;
    QString localHostName;
    QString localHostIP;
    QString ServerName,ServerAddress;
    quint16 port,porttcp;

    QTcpServer *tcpServer;
    QTcpSocket *tcpServerConnection;

    qint64 totalBytes,bytesReceived,fileNameSize;
    QString fileName;
    QFile *localFile;
    QByteArray inBlock;

    QTimer *timer;
    int speed;
};

#endif // WIDGET_H
