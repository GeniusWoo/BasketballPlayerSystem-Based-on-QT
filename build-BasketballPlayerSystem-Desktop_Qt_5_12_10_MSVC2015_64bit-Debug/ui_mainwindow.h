/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionbaoming;
    QAction *actionhengji;
    QAction *actionxianshibaom;
    QAction *actionlingjiangmingdan;
    QAction *actionmingdanshaixuan;
    QWidget *centralwidget;
    QTableView *ShowInfotableView;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1025, 545);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionbaoming = new QAction(MainWindow);
        actionbaoming->setObjectName(QString::fromUtf8("actionbaoming"));
        actionhengji = new QAction(MainWindow);
        actionhengji->setObjectName(QString::fromUtf8("actionhengji"));
        actionxianshibaom = new QAction(MainWindow);
        actionxianshibaom->setObjectName(QString::fromUtf8("actionxianshibaom"));
        actionlingjiangmingdan = new QAction(MainWindow);
        actionlingjiangmingdan->setObjectName(QString::fromUtf8("actionlingjiangmingdan"));
        actionmingdanshaixuan = new QAction(MainWindow);
        actionmingdanshaixuan->setObjectName(QString::fromUtf8("actionmingdanshaixuan"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ShowInfotableView = new QTableView(centralwidget);
        ShowInfotableView->setObjectName(QString::fromUtf8("ShowInfotableView"));
        ShowInfotableView->setGeometry(QRect(0, 0, 1031, 471));
        ShowInfotableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ShowInfotableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ShowInfotableView->setTextElideMode(Qt::ElideRight);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1025, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actionOpen);
        menu->addSeparator();
        menu->addAction(actionSave);
        menu_2->addAction(actionbaoming);
        menu_2->addSeparator();
        menu_3->addAction(actionhengji);
        menu_3->addAction(actionxianshibaom);
        menu_3->addAction(actionlingjiangmingdan);
        menu_3->addSeparator();
        menu_3->addAction(actionmingdanshaixuan);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionbaoming);
        toolBar->addSeparator();
        toolBar->addAction(actionxianshibaom);
        toolBar->addAction(actionhengji);
        toolBar->addAction(actionlingjiangmingdan);
        toolBar->addSeparator();
        toolBar->addAction(actionmingdanshaixuan);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\257\256\347\220\203\350\201\224\350\265\233\344\270\252\344\272\272\346\225\260\346\215\256\345\244\204\347\220\206\347\263\273\347\273\237", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266...", nullptr));
        actionbaoming->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        actionhengji->setText(QApplication::translate("MainWindow", "\347\220\203\345\221\230\344\270\252\344\272\272\346\225\260\346\215\256\346\261\207\346\200\273\350\241\250", nullptr));
        actionxianshibaom->setText(QApplication::translate("MainWindow", "\346\257\224\350\265\233\346\225\260\346\215\256", nullptr));
        actionlingjiangmingdan->setText(QApplication::translate("MainWindow", "\346\212\200\346\234\257\351\241\271\347\233\256\346\216\222\345\220\215", nullptr));
        actionmingdanshaixuan->setText(QApplication::translate("MainWindow", "\347\220\203\351\230\237\344\274\230\347\247\200\347\220\203\345\221\230", nullptr));
#ifndef QT_NO_TOOLTIP
        actionmingdanshaixuan->setToolTip(QApplication::translate("MainWindow", "\347\240\224\347\251\266\347\224\250\350\241\250", nullptr));
#endif // QT_NO_TOOLTIP
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\344\277\241\346\201\257\350\276\223\345\205\245", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\344\277\241\346\201\257\350\276\223\345\207\272", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
