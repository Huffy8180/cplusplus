#-------------------------------------------------
#
# Project created by QtCreator 2015-01-01T16:36:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CafeRegister
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    imageitem.cpp \
    informationwindow.cpp \
    menuview.cpp \
    menuitem.cpp \
    review.cpp \
    receipt.cpp

HEADERS  += mainwindow.h \
    view.h \
    imageitem.h \
    informationwindow.h \
    menuview.h \
    menuitem.h \
    review.h \
    receipt.h

FORMS    += mainwindow.ui \
    review.ui
