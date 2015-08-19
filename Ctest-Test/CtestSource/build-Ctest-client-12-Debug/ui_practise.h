/********************************************************************************
** Form generated from reading UI file 'practise.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTISE_H
#define UI_PRACTISE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_practise
{
public:
    QTextEdit *textEdit_problmeText;
    QTextEdit *textEdit_SamInput;
    QTextEdit *textEdit_SamOutput;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_Practise;
    QPushButton *pushButton_Exit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_ProblemList;
    QLabel *label_5;
    QLineEdit *lineEdit_Score;

    void setupUi(QDialog *practise)
    {
        if (practise->objectName().isEmpty())
            practise->setObjectName(QString::fromUtf8("practise"));
        practise->resize(849, 600);
        textEdit_problmeText = new QTextEdit(practise);
        textEdit_problmeText->setObjectName(QString::fromUtf8("textEdit_problmeText"));
        textEdit_problmeText->setEnabled(true);
        textEdit_problmeText->setGeometry(QRect(310, 70, 431, 211));
        textEdit_problmeText->setReadOnly(true);
        textEdit_SamInput = new QTextEdit(practise);
        textEdit_SamInput->setObjectName(QString::fromUtf8("textEdit_SamInput"));
        textEdit_SamInput->setEnabled(true);
        textEdit_SamInput->setGeometry(QRect(310, 330, 431, 101));
        textEdit_SamInput->setReadOnly(true);
        textEdit_SamOutput = new QTextEdit(practise);
        textEdit_SamOutput->setObjectName(QString::fromUtf8("textEdit_SamOutput"));
        textEdit_SamOutput->setEnabled(true);
        textEdit_SamOutput->setGeometry(QRect(310, 480, 431, 101));
        textEdit_SamOutput->setTabChangesFocus(false);
        textEdit_SamOutput->setReadOnly(true);
        label_2 = new QLabel(practise);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 20, 72, 15));
        label_3 = new QLabel(practise);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 300, 72, 15));
        label_4 = new QLabel(practise);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 450, 72, 15));
        label = new QLabel(practise);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 21));
        pushButton_Practise = new QPushButton(practise);
        pushButton_Practise->setObjectName(QString::fromUtf8("pushButton_Practise"));
        pushButton_Practise->setGeometry(QRect(770, 160, 61, 61));
        pushButton_Exit = new QPushButton(practise);
        pushButton_Exit->setObjectName(QString::fromUtf8("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(770, 430, 61, 61));
        horizontalLayoutWidget = new QWidget(practise);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(29, 69, 241, 471));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_ProblemList = new QListWidget(horizontalLayoutWidget);
        listWidget_ProblemList->setObjectName(QString::fromUtf8("listWidget_ProblemList"));

        horizontalLayout->addWidget(listWidget_ProblemList);

        label_5 = new QLabel(practise);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(630, 20, 61, 21));
        lineEdit_Score = new QLineEdit(practise);
        lineEdit_Score->setObjectName(QString::fromUtf8("lineEdit_Score"));
        lineEdit_Score->setEnabled(false);
        lineEdit_Score->setGeometry(QRect(690, 20, 91, 31));

        retranslateUi(practise);

        QMetaObject::connectSlotsByName(practise);
    } // setupUi

    void retranslateUi(QDialog *practise)
    {
        practise->setWindowTitle(QApplication::translate("practise", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("practise", "\351\242\230\347\233\256\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("practise", "\346\240\267\344\276\213\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("practise", "\346\240\267\344\276\213\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("practise", "\351\242\230\347\233\256\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        pushButton_Practise->setText(QApplication::translate("practise", "\346\265\213\350\257\225\344\273\243\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton_Exit->setText(QApplication::translate("practise", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("practise", "Score\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class practise: public Ui_practise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTISE_H
