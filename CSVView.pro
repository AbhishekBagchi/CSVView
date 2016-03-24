#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T23:24:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSVView
TEMPLATE = app

CONFIG += C++11

SOURCES += sources/main.cpp\
	sources/mainwindow.cpp \
    sources/tablemodel.cpp

HEADERS  += headers/mainwindow.h \
    headers/tablemodel.h

FORMS    += mainwindow.ui
