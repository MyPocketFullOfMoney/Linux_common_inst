/********************************************************************************
** Form generated from reading UI file 'process.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESS_H
#define UI_PROCESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Process
{
public:
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Compile;
    QPushButton *pushButton_Run;
    QLineEdit *lineEdit_Path;
    QTextEdit *textEdit_Compile;
    QTextEdit *textEdit_Result;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_Submit;
    QLabel *label_4;

    void setupUi(QDialog *Process)
    {
        if (Process->objectName().isEmpty())
            Process->setObjectName(QString::fromUtf8("Process"));
        Process->resize(678, 503);
        pushButton_Open = new QPushButton(Process);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setGeometry(QRect(530, 80, 41, 41));
        pushButton_Compile = new QPushButton(Process);
        pushButton_Compile->setObjectName(QString::fromUtf8("pushButton_Compile"));
        pushButton_Compile->setGeometry(QRect(530, 220, 41, 41));
        pushButton_Run = new QPushButton(Process);
        pushButton_Run->setObjectName(QString::fromUtf8("pushButton_Run"));
        pushButton_Run->setGeometry(QRect(530, 370, 41, 41));
        lineEdit_Path = new QLineEdit(Process);
        lineEdit_Path->setObjectName(QString::fromUtf8("lineEdit_Path"));
        lineEdit_Path->setGeometry(QRect(70, 80, 391, 31));
        textEdit_Compile = new QTextEdit(Process);
        textEdit_Compile->setObjectName(QString::fromUtf8("textEdit_Compile"));
        textEdit_Compile->setGeometry(QRect(70, 180, 391, 111));
        textEdit_Result = new QTextEdit(Process);
        textEdit_Result->setObjectName(QString::fromUtf8("textEdit_Result"));
        textEdit_Result->setGeometry(QRect(70, 350, 391, 111));
        label = new QLabel(Process);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 45, 221, 21));
        label_2 = new QLabel(Process);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 150, 91, 16));
        label_3 = new QLabel(Process);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 320, 91, 20));
        pushButton_Submit = new QPushButton(Process);
        pushButton_Submit->setObjectName(QString::fromUtf8("pushButton_Submit"));
        pushButton_Submit->setGeometry(QRect(600, 440, 61, 51));
        label_4 = new QLabel(Process);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 281, 31));

        retranslateUi(Process);

        QMetaObject::connectSlotsByName(Process);
    } // setupUi

    void retranslateUi(QDialog *Process)
    {
        Process->setWindowTitle(QApplication::translate("Process", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_Open->setText(QApplication::translate("Process", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        pushButton_Compile->setText(QApplication::translate("Process", "\347\274\226\350\257\221", 0, QApplication::UnicodeUTF8));
        pushButton_Run->setText(QApplication::translate("Process", "\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Process", "\344\270\200\343\200\201\346\211\223\345\274\200\346\272\220\344\273\243\347\240\201(\346\211\251\345\261\225\345\220\215\344\270\272.c\347\232\204\346\226\207\344\273\266)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Process", "\344\272\214\343\200\201\347\274\226\350\257\221\346\272\220\344\273\243\347\240\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Process", "\344\270\211\343\200\201\350\277\220\350\241\214", 0, QApplication::UnicodeUTF8));
        pushButton_Submit->setText(QApplication::translate("Process", "\346\217\220\344\272\244", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Process", "\350\257\267\346\214\211\346\255\245\351\252\244\350\277\233\350\241\214\346\223\215\344\275\234\357\274\214\345\271\266\346\217\220\344\272\244\347\273\223\346\236\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Process: public Ui_Process {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESS_H
