#-------------------------------------------------
#
# Project created by QtCreator 2018-08-24T17:58:19
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = coretest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += coretest.cpp \
    statistics.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    statistics.h
