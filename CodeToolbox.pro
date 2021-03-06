#-------------------------------------------------
#
# Project created by QtCreator 2022-03-15T13:36:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CodeToolbox
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    menu.cpp \
    input.cpp \
    dataprocess.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    input.h \
    dataprocess.h

FORMS += \
        mainwindow.ui \
    menu.ui \
    input.ui

STATECHARTS +=


# Icon <a href="https://www.flaticon.com/free-icons/toolbox" title="toolbox icons">Toolbox icons created by Freepik - Flaticon</a>

DISTFILES += \
    快捷鍵 \
    CodeToolbox.rc \
    README.md \
    icon.ico

#RC_FILE += CodeToolbox.rc
RC_ICONS = icon.ico

RESOURCES += \
    res.qrc
