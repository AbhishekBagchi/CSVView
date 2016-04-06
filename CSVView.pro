#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T23:24:51
#
#-------------------------------------------------

VERSION = 0.0.1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csvview
TEMPLATE = app

CONFIG += C++11

SOURCES += sources/main.cpp\
	sources/mainwindow.cpp \
    sources/tablemodel.cpp

HEADERS  += headers/mainwindow.h \
    headers/tablemodel.h

FORMS    += sources/mainwindow.ui

release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
