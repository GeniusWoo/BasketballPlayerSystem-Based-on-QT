/********************************************************************************
** Form generated from reading UI file 'selectitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTITEM_H
#define UI_SELECTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SelectItem
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboSelectItem;
    QLabel *label;

    void setupUi(QDialog *SelectItem)
    {
        if (SelectItem->objectName().isEmpty())
            SelectItem->setObjectName(QString::fromUtf8("SelectItem"));
        SelectItem->resize(353, 261);
        buttonBox = new QDialogButtonBox(SelectItem);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-30, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboSelectItem = new QComboBox(SelectItem);
        comboSelectItem->addItem(QString());
        comboSelectItem->addItem(QString());
        comboSelectItem->addItem(QString());
        comboSelectItem->addItem(QString());
        comboSelectItem->addItem(QString());
        comboSelectItem->setObjectName(QString::fromUtf8("comboSelectItem"));
        comboSelectItem->setGeometry(QRect(150, 90, 101, 31));
        comboSelectItem->setMouseTracking(false);
        comboSelectItem->setLayoutDirection(Qt::LeftToRight);
        comboSelectItem->setAutoFillBackground(false);
        label = new QLabel(SelectItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 91, 31));

        retranslateUi(SelectItem);
        QObject::connect(buttonBox, SIGNAL(accepted()), SelectItem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SelectItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectItem);
    } // setupUi

    void retranslateUi(QDialog *SelectItem)
    {
        SelectItem->setWindowTitle(QApplication::translate("SelectItem", "\351\200\211\346\213\251\346\212\200\346\234\257\351\241\271\347\233\256", nullptr));
        comboSelectItem->setItemText(0, QApplication::translate("SelectItem", "\345\234\272\345\235\207\344\270\211\345\210\206", nullptr));
        comboSelectItem->setItemText(1, QApplication::translate("SelectItem", "\345\234\272\345\235\207\347\257\256\346\235\277", nullptr));
        comboSelectItem->setItemText(2, QApplication::translate("SelectItem", "\345\234\272\345\235\207\346\211\243\347\257\256", nullptr));
        comboSelectItem->setItemText(3, QApplication::translate("SelectItem", "\345\234\272\345\235\207\346\212\242\346\226\255", nullptr));
        comboSelectItem->setItemText(4, QApplication::translate("SelectItem", "\345\234\272\345\235\207\345\276\227\345\210\206", nullptr));

        label->setText(QApplication::translate("SelectItem", "\346\212\200\346\234\257\351\241\271\347\233\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectItem: public Ui_SelectItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTITEM_H
