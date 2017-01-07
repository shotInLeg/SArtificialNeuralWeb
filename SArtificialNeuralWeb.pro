#-------------------------------------------------
#
# Project created by QtCreator 2017-01-07T18:00:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SArtificialNeuralWeb
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        sartificialneuralweb.cpp \
    SArtificialNeuralWebKernel/sartificialneuralwebkernel.cpp

HEADERS  += sartificialneuralweb.h \
    SArtificialNeuralWebKernel/sartificialneuralwebkernel.h

FORMS    += sartificialneuralweb.ui
