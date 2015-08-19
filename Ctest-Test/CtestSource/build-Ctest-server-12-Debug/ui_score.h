/********************************************************************************
** Form generated from reading UI file 'score.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORE_H
#define UI_SCORE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_score
{
public:
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_close;
    QPushButton *pushButton_reset;

    void setupUi(QDialog *score)
    {
        if (score->objectName().isEmpty())
            score->setObjectName(QString::fromUtf8("score"));
        score->resize(682, 517);
        textEdit = new QTextEdit(score);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(30, 70, 621, 381));
        label_2 = new QLabel(score);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 30, 71, 21));
        label_3 = new QLabel(score);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 30, 54, 12));
        label_4 = new QLabel(score);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(540, 30, 54, 12));
        pushButton_close = new QPushButton(score);
        pushButton_close->setObjectName(QString::fromUtf8("pushButton_close"));
        pushButton_close->setGeometry(QRect(400, 470, 71, 31));
        pushButton_reset = new QPushButton(score);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(150, 470, 71, 31));

        retranslateUi(score);
        QObject::connect(pushButton_close, SIGNAL(clicked()), score, SLOT(close()));

        QMetaObject::connectSlotsByName(score);
    } // setupUi

    void retranslateUi(QDialog *score)
    {
        score->setWindowTitle(QApplication::translate("score", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("score", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("score", "\345\255\246\345\217\267", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("score", "\345\210\206\346\225\260", 0, QApplication::UnicodeUTF8));
        pushButton_close->setText(QApplication::translate("score", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        pushButton_reset->setText(QApplication::translate("score", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class score: public Ui_score {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORE_H
