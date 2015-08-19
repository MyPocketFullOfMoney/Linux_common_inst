/********************************************************************************
** Form generated from reading UI file 'addproblem.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROBLEM_H
#define UI_ADDPROBLEM_H

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

class Ui_AddProblem
{
public:
    QLineEdit *lineEdit_ProblemName;
    QTextEdit *textEdit_Problem;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit_SamInput;
    QLabel *label_4;
    QTextEdit *textEdit_SamOutput;
    QPushButton *pushButton_Reset;
    QPushButton *pushButton_Accept;
    QPushButton *pushButton_Cancle;
    QTextEdit *textEdit_StdOutput;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *AddProblem)
    {
        if (AddProblem->objectName().isEmpty())
            AddProblem->setObjectName(QString::fromUtf8("AddProblem"));
        AddProblem->resize(681, 668);
        lineEdit_ProblemName = new QLineEdit(AddProblem);
        lineEdit_ProblemName->setObjectName(QString::fromUtf8("lineEdit_ProblemName"));
        lineEdit_ProblemName->setGeometry(QRect(70, 50, 541, 41));
        textEdit_Problem = new QTextEdit(AddProblem);
        textEdit_Problem->setObjectName(QString::fromUtf8("textEdit_Problem"));
        textEdit_Problem->setGeometry(QRect(70, 140, 541, 81));
        label = new QLabel(AddProblem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 111, 31));
        label_2 = new QLabel(AddProblem);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 110, 54, 21));
        label_3 = new QLabel(AddProblem);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 230, 61, 21));
        textEdit_SamInput = new QTextEdit(AddProblem);
        textEdit_SamInput->setObjectName(QString::fromUtf8("textEdit_SamInput"));
        textEdit_SamInput->setGeometry(QRect(70, 260, 541, 81));
        label_4 = new QLabel(AddProblem);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 350, 54, 21));
        textEdit_SamOutput = new QTextEdit(AddProblem);
        textEdit_SamOutput->setObjectName(QString::fromUtf8("textEdit_SamOutput"));
        textEdit_SamOutput->setGeometry(QRect(70, 380, 541, 91));
        pushButton_Reset = new QPushButton(AddProblem);
        pushButton_Reset->setObjectName(QString::fromUtf8("pushButton_Reset"));
        pushButton_Reset->setGeometry(QRect(150, 610, 51, 51));
        pushButton_Accept = new QPushButton(AddProblem);
        pushButton_Accept->setObjectName(QString::fromUtf8("pushButton_Accept"));
        pushButton_Accept->setGeometry(QRect(310, 610, 51, 51));
        pushButton_Cancle = new QPushButton(AddProblem);
        pushButton_Cancle->setObjectName(QString::fromUtf8("pushButton_Cancle"));
        pushButton_Cancle->setGeometry(QRect(490, 610, 51, 51));
        textEdit_StdOutput = new QTextEdit(AddProblem);
        textEdit_StdOutput->setObjectName(QString::fromUtf8("textEdit_StdOutput"));
        textEdit_StdOutput->setGeometry(QRect(70, 510, 541, 91));
        label_5 = new QLabel(AddProblem);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 480, 71, 21));
        label_6 = new QLabel(AddProblem);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 480, 351, 20));
        label_7 = new QLabel(AddProblem);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 110, 351, 21));

        retranslateUi(AddProblem);

        QMetaObject::connectSlotsByName(AddProblem);
    } // setupUi

    void retranslateUi(QDialog *AddProblem)
    {
        AddProblem->setWindowTitle(QApplication::translate("AddProblem", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddProblem", "\351\242\230\347\233\256\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddProblem", "\351\242\230\347\233\256\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddProblem", "\346\240\267\344\276\213\350\276\223\345\205\245", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddProblem", "\346\240\267\344\276\213\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_Reset->setText(QApplication::translate("AddProblem", "\351\207\215\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_Accept->setText(QApplication::translate("AddProblem", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_Cancle->setText(QApplication::translate("AddProblem", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddProblem", "\346\240\207\345\207\206\350\276\223\345\207\272", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddProblem", "(\345\246\202\346\236\234\351\242\230\347\233\256\346\262\241\346\234\211\346\240\267\344\276\213\350\276\223\345\205\245\350\276\223\345\207\272\357\274\214\350\257\267\345\217\252\346\267\273\345\212\240 \346\240\207\345\207\206\350\276\223\345\207\272 \344\275\234\344\270\272\345\210\244\351\242\230\344\276\235\346\215\256\357\274\211", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("AddProblem", "(\351\242\230\347\233\256\346\217\217\350\277\260\344\270\255\345\272\224\345\275\223\346\214\207\345\207\272\350\276\223\345\207\272\346\240\274\345\274\217\347\273\206\350\212\202\357\274\214\345\214\205\346\213\254\347\251\272\346\240\274\344\273\245\345\217\212\346\215\242\350\241\214\347\232\204\344\275\277\347\224\250\347\255\211)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddProblem: public Ui_AddProblem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROBLEM_H
