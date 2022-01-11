/********************************************************************************
** Form generated from reading UI file 'selectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDIALOG_H
#define UI_SELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectDialog
{
public:
    QComboBox *comboSpecialItem;
    QLabel *label;
    QPushButton *btnCancel;
    QPushButton *btnOK;

    void setupUi(QDialog *SelectDialog)
    {
        if (SelectDialog->objectName().isEmpty())
            SelectDialog->setObjectName(QString::fromUtf8("SelectDialog"));
        SelectDialog->resize(326, 261);
        comboSpecialItem = new QComboBox(SelectDialog);
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->addItem(QString());
        comboSpecialItem->setObjectName(QString::fromUtf8("comboSpecialItem"));
        comboSpecialItem->setGeometry(QRect(90, 90, 201, 31));
        label = new QLabel(SelectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 54, 21));
        btnCancel = new QPushButton(SelectDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(180, 220, 75, 23));
        btnOK = new QPushButton(SelectDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(70, 220, 75, 23));

        retranslateUi(SelectDialog);
        QObject::connect(btnOK, SIGNAL(clicked()), SelectDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SelectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectDialog)
    {
        SelectDialog->setWindowTitle(QApplication::translate("SelectDialog", "\351\200\211\346\213\251\347\220\203\351\230\237", nullptr));
        comboSpecialItem->setItemText(0, QString());
        comboSpecialItem->setItemText(1, QApplication::translate("SelectDialog", "\351\207\221", nullptr));
        comboSpecialItem->setItemText(2, QApplication::translate("SelectDialog", "\346\234\250", nullptr));
        comboSpecialItem->setItemText(3, QApplication::translate("SelectDialog", "\346\260\264", nullptr));
        comboSpecialItem->setItemText(4, QApplication::translate("SelectDialog", "\347\201\253", nullptr));
        comboSpecialItem->setItemText(5, QApplication::translate("SelectDialog", "\345\234\237", nullptr));

        label->setText(QApplication::translate("SelectDialog", "<html><head/><body><p><span style=\" font-size:11pt;\">\347\220\203\351\230\237\357\274\232</span></p></body></html>", nullptr));
        btnCancel->setText(QApplication::translate("SelectDialog", "Cancel", nullptr));
        btnOK->setText(QApplication::translate("SelectDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectDialog: public Ui_SelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDIALOG_H
