######################################################################
# Automatically generated by qmake (3.0) Wed Jul 17 11:14:22 2019
######################################################################

TEMPLATE = app
TARGET = qt.out
INCLUDEPATH += .
#QT +=   widgets
QT += core testlib
QT += sql


CONFIG   += console
#CONFIG   -= app_bundle
CONFIG   += testcase


# Input
SOURCES += main.cpp \
    BshBb.cpp \
    DbIntegerIntervalOption.cpp \
    DbOptionBase.cpp \
    testDb.cpp \
    testqstring.cpp

HEADERS += \
    BshBb.h \
    DbIntegerIntervalOption.h \
    DbOptionBase.h \
    DefBshBb.h \
    testDb.h \
    testqstring.h
