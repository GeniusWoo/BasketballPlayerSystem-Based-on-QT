QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    gametable.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    playerstable.cpp \
    readonlydelegate.cpp \
    selectdialog.cpp \
    selectitem.cpp \
    signupdialog.cpp

HEADERS += \
    game.h \
    gametable.h \
    mainwindow.h \
    player.h \
    playerstable.h \
    readonlydelegate.h \
    selectdialog.h \
    selectitem.h \
    signupdialog.h

FORMS += \
    mainwindow.ui \
    selectdialog.ui \
    selectitem.ui \
    signupdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    logo.qrc
