/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButton_practise;
    QPushButton *pushButton_example;
    QPushButton *pushButton_end;
    QLabel *label_Picture;
    QLabel *label_3;
    QLabel *label_state;
    QLabel *label_Time;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(545, 428);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 261, 21));
        pushButton_practise = new QPushButton(Widget);
        pushButton_practise->setObjectName(QString::fromUtf8("pushButton_practise"));
        pushButton_practise->setGeometry(QRect(80, 90, 91, 41));
        pushButton_example = new QPushButton(Widget);
        pushButton_example->setObjectName(QString::fromUtf8("pushButton_example"));
        pushButton_example->setGeometry(QRect(80, 190, 91, 41));
        pushButton_end = new QPushButton(Widget);
        pushButton_end->setObjectName(QString::fromUtf8("pushButton_end"));
        pushButton_end->setGeometry(QRect(80, 280, 91, 41));
        label_Picture = new QLabel(Widget);
        label_Picture->setObjectName(QString::fromUtf8("label_Picture"));
        label_Picture->setGeometry(QRect(290, 90, 211, 221));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 390, 121, 16));
        label_state = new QLabel(Widget);
        label_state->setObjectName(QString::fromUtf8("label_state"));
        label_state->setGeometry(QRect(70, 370, 101, 31));
        label_Time = new QLabel(Widget);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setGeometry(QRect(320, 31, 151, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\346\254\242\350\277\216\344\275\277\347\224\250\351\202\265\351\230\263\345\255\246\351\231\242C\350\257\255\350\250\200\347\274\226\347\250\213\350\256\255\347\273\203\350\275\257\344\273\266 ", 0, QApplication::UnicodeUTF8));
        pushButton_practise->setText(QApplication::translate("Widget", "\346\265\213\350\257\225\350\256\255\347\273\203", 0, QApplication::UnicodeUTF8));
        pushButton_example->setText(QApplication::translate("Widget", "\346\250\241\346\213\237\350\200\203\350\257\225", 0, QApplication::UnicodeUTF8));
        pushButton_end->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_Picture->setText(QString());
        label_3->setText(QApplication::translate("Widget", "Time:2014.3", 0, QApplication::UnicodeUTF8));
        label_state->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250\346\234\252\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        label_Time->setText(QApplication::translate("Widget", "\346\227\240\346\263\225\350\216\267\345\217\226\346\234\215\345\212\241\345\231\250\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
