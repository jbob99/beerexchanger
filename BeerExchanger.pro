#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T08:16:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeerExchanger
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    participant.cpp \
    adddialog.cpp \
    participants.cpp \

HEADERS  += mainwindow.hpp \
    participant.hpp \
    adddialog.hpp \
    participants.hpp \

FORMS    += mainwindow.ui \
    adddialog.ui

RESOURCES += \
    up-arrow.qrc \
    down-arrow.qrc

DISTFILES += \
    ../../../Desktop/arrow.png \
    images/down-arrow.png \
    images/up-arrow.png
