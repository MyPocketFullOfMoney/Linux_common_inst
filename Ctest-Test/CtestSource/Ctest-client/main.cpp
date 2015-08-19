#include "widget.h"
#include <QApplication>
#include<QTextCodec>
#include<QtGui>
#include<QObject>
int main(int argc, char *argv[])
{
    //使用GB2312字符编码，保证中文不出乱码
    QTextCodec *codec = QTextCodec::codecForName("UTF8");
        if (codec) {
            QTextCodec::setCodecForTr(codec);
            QTextCodec::setCodecForLocale(codec);
            QTextCodec::setCodecForCStrings(codec);
        }
        //只运行一个实例
        QSharedMemory mem("SystemName");//以系统exe名称为参数，定义共享内存mem
        if(!mem.create(1))//创建共享内存mem，如果该共享内存已存在，则弹出提示对话框，并退出
        {
                   QMessageBox::information(0,QObject::tr("Warning"),QObject::tr("An instance is running"));
                   return 0;
        }
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle(QString::fromUtf8("考生端"));
    w.show();

    return a.exec();
}
