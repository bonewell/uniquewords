TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp counter.cpp core/statistics.cpp

HEADERS += counter.h core/statistics.h

RESOURCES += qml.qrc

QMAKE_CXXFLAGS += -std=c++11

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=
