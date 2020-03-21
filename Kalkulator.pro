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
    Parser/parser.cpp \
    Exception/NoOperatorException/nooperatorexception.cpp \
    Exception/InvalidOperatorUseException/invalidoperatoruseexception.cpp \
    Exception/DotOverloadException/dotoverloadexception.cpp \
    Exception/RootNegativeException/rootnegativeexception.cpp \
    Exception/ZeroDivisionException/zerodivisionexception.cpp \
    Exception/ZeroModException/zeromodexception.cpp \
    Exception/DecimalModException/decimalmodexception.cpp

HEADERS += \
        kalkulator.h \
    Expression/AddExpression/addexpression.h \
    Expression/SubstractExpression/substractexpression.h \
    Expression/MultiplyExpression/multiplyexpression.h \
    Expression/RootExpression/rootexpression.h \
    Expression/BinaryExpression/binaryexpression.h \
    Expression/UnaryExpression/unaryexpression.h \
    Expression/expression.h \
    Exception/BaseException/baseexception.h \
    Expression/TerminalExpression/terminalexpression.h \
    Parser/parser.h \
    Expression/DivisionExpression/divisionexpression.h \
    Exception/NoOperatorException/nooperatorexception.h \
    Exception/InvalidOperatorUseException/invalidoperatoruseexception.h \
    Exception/DotOverloadException/dotoverloadexception.h \
    Exception/RootNegativeException/rootnegativeexception.h \
    Expression/PowerExpression/powerexpression.h \
    Expression/ModExpression/modexpression.h \
    Expression/SinExpression/sinexpression.h \
    Expression/CosExpression/cosexpression.h \
    Expression/TanExpression/tanexpression.h \
    Exception/ZeroDivisionException/zerodivisionexception.h \
    Exception/ZeroModException/zeromodexception.h \
    Exception/DecimalModException/decimalmodexception.h

FORMS += \
        kalkulator.ui
