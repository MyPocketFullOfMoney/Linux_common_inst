/********************************************************************************
** Form generated from reading UI file 'contest.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTEST_H
#define UI_CONTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Contest
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_Sex;
    QLineEdit *lineEdit_Number;
    QLineEdit *lineEdit_Family;
    QLineEdit *lineEdit_Class;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_Cancle;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_10;

    void setupUi(QDialog *Contest)
    {
        if (Contest->objectName().isEmpty())
            Contest->setObjectName(QString::fromUtf8("Contest"));
        Contest->resize(630, 488);
        label = new QLabel(Contest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 30, 151, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Aharoni"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(Contest);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 100, 61, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Aharoni"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(Contest);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 160, 61, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(Contest);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 230, 61, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(Contest);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(110, 290, 61, 21));
        label_5->setFont(font1);
        label_6 = new QLabel(Contest);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(110, 350, 61, 21));
        label_6->setFont(font1);
        lineEdit_Name = new QLineEdit(Contest);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setGeometry(QRect(180, 100, 271, 31));
        lineEdit_Sex = new QLineEdit(Contest);
        lineEdit_Sex->setObjectName(QString::fromUtf8("lineEdit_Sex"));
        lineEdit_Sex->setGeometry(QRect(180, 160, 271, 31));
        lineEdit_Number = new QLineEdit(Contest);
        lineEdit_Number->setObjectName(QString::fromUtf8("lineEdit_Number"));
        lineEdit_Number->setGeometry(QRect(180, 220, 271, 31));
        lineEdit_Family = new QLineEdit(Contest);
        lineEdit_Family->setObjectName(QString::fromUtf8("lineEdit_Family"));
        lineEdit_Family->setGeometry(QRect(180, 280, 271, 31));
        lineEdit_Class = new QLineEdit(Contest);
        lineEdit_Class->setObjectName(QString::fromUtf8("lineEdit_Class"));
        lineEdit_Class->setGeometry(QRect(180, 340, 271, 31));
        pushButton_accept = new QPushButton(Contest);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(180, 400, 61, 61));
        pushButton_Cancle = new QPushButton(Contest);
        pushButton_Cancle->setObjectName(QString::fromUtf8("pushButton_Cancle"));
        pushButton_Cancle->setGeometry(QRect(390, 400, 61, 61));
        label_7 = new QLabel(Contest);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(470, 101, 51, 31));
        label_8 = new QLabel(Contest);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(370, 30, 141, 41));
        label_10 = new QLabel(Contest);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(470, 220, 51, 31));

        retranslateUi(Contest);
        QObject::connect(pushButton_Cancle, SIGNAL(clicked()), Contest, SLOT(accept()));

        QMetaObject::connectSlotsByName(Contest);
    } // setupUi

    void retranslateUi(QDialog *Contest)
    {
        Contest->setWindowTitle(QApplication::translate("Contest", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Contest", "\350\257\267\345\241\253\345\206\231\350\200\203\347\224\237\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Contest", "\345\247\223\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Contest", "\346\200\247\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Contest", "\345\255\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Contest", "\347\263\273\345\210\253\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Contest", "\347\217\255\347\272\247\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_accept->setText(QApplication::translate("Contest", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_Cancle->setText(QApplication::translate("Contest", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Contest", "*", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Contest", "(\345\270\246*\345\217\267\347\232\204\344\270\272\345\277\205\345\241\253)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Contest", "*", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Contest: public Ui_Contest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTEST_H
