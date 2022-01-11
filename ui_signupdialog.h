/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QLabel *label_5;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QTextEdit *textEditThree;
    QTextEdit *textEditName;
    QTextEdit *textEditRebound;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEditSteal;
    QTextEdit *textEditDunk;
    QTextEdit *textEditScore;
    QComboBox *comboTeamname;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName(QString::fromUtf8("SignupDialog"));
        SignupDialog->resize(323, 373);
        label_5 = new QLabel(SignupDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 10, 41, 31));
        dateEdit = new QDateEdit(SignupDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(110, 90, 161, 31));
        label_3 = new QLabel(SignupDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 81, 31));
        label = new QLabel(SignupDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 41, 31));
        label_2 = new QLabel(SignupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 61, 31));
        label_4 = new QLabel(SignupDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 170, 41, 31));
        textEditThree = new QTextEdit(SignupDialog);
        textEditThree->setObjectName(QString::fromUtf8("textEditThree"));
        textEditThree->setGeometry(QRect(110, 130, 104, 31));
        textEditThree->setAcceptRichText(false);
        textEditName = new QTextEdit(SignupDialog);
        textEditName->setObjectName(QString::fromUtf8("textEditName"));
        textEditName->setGeometry(QRect(110, 10, 161, 31));
        textEditName->setAcceptRichText(false);
        textEditRebound = new QTextEdit(SignupDialog);
        textEditRebound->setObjectName(QString::fromUtf8("textEditRebound"));
        textEditRebound->setGeometry(QRect(110, 170, 104, 31));
        textEditRebound->setAcceptRichText(false);
        btnOK = new QPushButton(SignupDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(70, 340, 75, 23));
        btnCancel = new QPushButton(SignupDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(180, 340, 75, 23));
        label_6 = new QLabel(SignupDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 210, 41, 31));
        label_7 = new QLabel(SignupDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 290, 41, 31));
        label_8 = new QLabel(SignupDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 250, 41, 31));
        textEditSteal = new QTextEdit(SignupDialog);
        textEditSteal->setObjectName(QString::fromUtf8("textEditSteal"));
        textEditSteal->setGeometry(QRect(110, 250, 104, 31));
        textEditSteal->setAcceptRichText(false);
        textEditDunk = new QTextEdit(SignupDialog);
        textEditDunk->setObjectName(QString::fromUtf8("textEditDunk"));
        textEditDunk->setGeometry(QRect(110, 210, 104, 31));
        textEditDunk->setAcceptRichText(false);
        textEditScore = new QTextEdit(SignupDialog);
        textEditScore->setObjectName(QString::fromUtf8("textEditScore"));
        textEditScore->setGeometry(QRect(110, 290, 104, 31));
        textEditScore->setAcceptRichText(false);
        comboTeamname = new QComboBox(SignupDialog);
        comboTeamname->addItem(QString());
        comboTeamname->addItem(QString());
        comboTeamname->addItem(QString());
        comboTeamname->addItem(QString());
        comboTeamname->addItem(QString());
        comboTeamname->addItem(QString());
        comboTeamname->setObjectName(QString::fromUtf8("comboTeamname"));
        comboTeamname->setGeometry(QRect(110, 50, 161, 31));
        comboTeamname->setAcceptDrops(true);

        retranslateUi(SignupDialog);
        QObject::connect(btnOK, SIGNAL(clicked()), SignupDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SignupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QApplication::translate("SignupDialog", "\346\226\260\345\242\236", nullptr));
        label_5->setText(QApplication::translate("SignupDialog", "\347\220\203\345\221\230", nullptr));
        label_3->setText(QApplication::translate("SignupDialog", "\344\270\211\345\210\206\347\220\203\344\270\252\346\225\260", nullptr));
        label->setText(QApplication::translate("SignupDialog", "\347\220\203\351\230\237", nullptr));
        label_2->setText(QApplication::translate("SignupDialog", "\346\257\224\350\265\233\346\227\245\346\234\237", nullptr));
        label_4->setText(QApplication::translate("SignupDialog", "\347\257\256\346\235\277", nullptr));
        btnOK->setText(QApplication::translate("SignupDialog", "OK", nullptr));
        btnCancel->setText(QApplication::translate("SignupDialog", "Cancel", nullptr));
        label_6->setText(QApplication::translate("SignupDialog", "\346\211\243\347\257\256", nullptr));
        label_7->setText(QApplication::translate("SignupDialog", "\345\276\227\345\210\206", nullptr));
        label_8->setText(QApplication::translate("SignupDialog", "\346\212\242\346\226\255", nullptr));
        comboTeamname->setItemText(0, QString());
        comboTeamname->setItemText(1, QApplication::translate("SignupDialog", "\351\207\221", nullptr));
        comboTeamname->setItemText(2, QApplication::translate("SignupDialog", "\346\234\250", nullptr));
        comboTeamname->setItemText(3, QApplication::translate("SignupDialog", "\346\260\264", nullptr));
        comboTeamname->setItemText(4, QApplication::translate("SignupDialog", "\347\201\253", nullptr));
        comboTeamname->setItemText(5, QApplication::translate("SignupDialog", "\345\234\237", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
