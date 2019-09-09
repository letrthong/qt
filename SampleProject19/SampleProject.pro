#-------------------------------------------------
#
# Project created by QtCreator 2019-08-08T10:02:33
#
#-------------------------------------------------

#CONFIG += qt plugin 
QT       += core gui qml  quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt.out
TEMPLATE = app

INCLUDEPATH += .
INCLUDEPATH += ./app/Core
INCLUDEPATH += ./app/DataModel
INCLUDEPATH += ./SM

DEPENDPATH += ./

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    app/Core/main.cpp \
    qmlbase/QmlBackButton.cpp \
    app/Core/SignalManager.cpp \
    app/DataModel/BackEnd.cpp \
    SM/ScreenController.cpp \


HEADERS +=  qmlbase/QmlBackButton.h \
    app/Core/SignalManager.h \
    app/DataModel/BackEnd.h \
    SM/ScreenController.h \


      

qml.files = *.qml  
qml.path = ./qrc 
 

#QML_IMPORT_PATH += $$PWD/qmlbase/Templates
#QML_DESIGNER_IMPORT_PATH += qmlbase/Templates


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
    SM/myState.scxml

DISTFILES += \
    qrc/Scenes/screen01.qml \
    build.sh \
    ReadMe.txt \
    qrc/Scenes/BtnListElement.qml \
    qrc/Scenes/List_T_3_2.qml \
    qrc/images/backButton.png \
    qrc/Scenes/BackButton.qml \
	qrc/Scenes/PushButton.qml \
    qrc/Scenes/PushButton .qml \
    qrc/Scenes/PushButton .qml
 

SUBDIRS += \
    SampleProject.pro
