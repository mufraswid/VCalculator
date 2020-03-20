#-------------------------------------------------
#
# Project created by QtCreator 2020-03-19T21:15:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalkulator
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
        kalkulator.cpp \
    Expression/addexpression.cpp \
    Expression/substractexpression.cpp \
    Expression/multiplyexpression.cpp \
    Expression/rootexpression.cpp \
    Expression/binaryexpression.cpp \
    Expression/unaryexpression.cpp \
    Expression/expression.cpp \
    Exception/baseexception.cpp \
    Expression/terminalexpression.cpp \
    Parser/parser.cpp \
    Expression/divisionexpression.cpp \
    Exception/nooperatorexception.cpp \
    Exception/invalidoperatoruseexception.cpp

HEADERS += \
        kalkulator.h \
    Expression/addexpression.h \
    Expression/substractexpression.h \
    Expression/multiplyexpression.h \
    Expression/rootexpression.h \
    Expression/binaryexpression.h \
    Expression/unaryexpression.h \
    Expression/expression.h \
    Exception/baseexception.h \
    Expression/terminalexpression.h \
    Parser/parser.h \
    Expression/divisionexpression.h \
    master.h \
    Exception/nooperatorexception.h \
    Exception/invalidoperatoruseexception.h

FORMS += \
        kalkulator.ui
