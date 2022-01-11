/********************************************************************************
** Form generated from reading UI file 'Signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SignupDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QDateEdit *dateEdit;
    QTextEdit *textEdit_3;
    QLabel *label_6;
    QTextEdit *textEdit_4;
    QLabel *label_7;

    void setupUi(QDialog *SignupDialog)
    {
        if (SignupDialog->objectName().isEmpty())
            SignupDialog->setObjectName(QString::fromUtf8("SignupDialog"));
        SignupDialog->resize(282, 254);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        SignupDialog->setFont(font);
        buttonBox = new QDialogButtonBox(SignupDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 210, 156, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SignupDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 41, 31));
        label_2 = new QLabel(SignupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 41, 31));
        label_3 = new QLabel(SignupDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 130, 41, 31));
        label_4 = new QLabel(SignupDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 170, 41, 31));
        label_5 = new QLabel(SignupDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 10, 41, 31));
        textEdit = new QTextEdit(SignupDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 10, 161, 31));
        textEdit_2 = new QTextEdit(SignupDialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(90, 50, 161, 31));
        dateEdit = new QDateEdit(SignupDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(90, 90, 161, 31));
        textEdit_3 = new QTextEdit(SignupDialog);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(90, 130, 104, 31));
        label_6 = new QLabel(SignupDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 130, 41, 31));
        textEdit_4 = new QTextEdit(SignupDialog);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(90, 170, 104, 31));
        label_7 = new QLabel(SignupDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(210, 170, 41, 31));

        retranslateUi(SignupDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SignupDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SignupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SignupDialog);
    } // setupUi

    void retranslateUi(QDialog *SignupDialog)
    {
        SignupDialog->setWindowTitle(QApplication::translate("SignupDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("SignupDialog", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QApplication::translate("SignupDialog", "\347\224\237\346\227\245", nullptr));
        label_3->setText(QApplication::translate("SignupDialog", "\350\272\253\351\253\230", nullptr));
        label_4->setText(QApplication::translate("SignupDialog", "\344\275\223\351\207\215", nullptr));
        label_5->setText(QApplication::translate("SignupDialog", "\345\217\267\347\240\201", nullptr));
        label_6->setText(QApplication::translate("SignupDialog", "\345\216\230\347\261\263", nullptr));
        label_7->setText(QApplication::translate("SignupDialog", "\345\205\254\346\226\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupDialog: public Ui_SignupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
