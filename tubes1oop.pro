#-------------------------------------------------
#
# Project created by QtCreator 2020-02-28T16:33:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tubes1oop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
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
    button.cpp \
    expression.cpp \
    terminalexpression.cpp \
    unaryexpression.cpp \
    binaryexpression.cpp \
    addexpression.cpp \
    substractexpression.cpp \
    multiplyexpression.cpp \
    negativeexpression.cpp \
    numberbutton.cpp \
    divisionexpression.cpp

HEADERS += \
        mainwindow.h \ 
    button.h \
    expression.h \
    terminalexpression.h \
    unaryexpression.h \
    binaryexpression.h \
    addexpression.h \
    substractexpression.h \
    multiplyexpression.h \
    negativeexpression.h \
    numberbutton.h \
    divisionexpression.h

FORMS += \
        mainwindow.ui
