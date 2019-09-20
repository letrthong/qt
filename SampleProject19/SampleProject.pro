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
    app/Core/MainController.cpp \
    app/Core/main.cpp \
    app/Core/screen02Handler.cpp \
    app/Core/singleton.cpp \
    qmlbase/QmlBackButton.cpp \
    app/Core/SignalManager.cpp \
    app/DataModel/BackEnd.cpp \
    SM/ScreenController.cpp \
    app/Core/SceneBase.cpp \
    app/Core/screen01Handler.cpp \
    app/Core/infostore.cpp


HEADERS +=  qmlbase/QmlBackButton.h \
    app/Core/MainController.h \
    app/Core/SignalManager.h \
    app/Core/screen02Handler.h \
    app/Core/singleton.h \
    app/DataModel/BackEnd.h \
    SM/ScreenController.h \
    app/Core/SceneBase.h \
    app/Core/screen01Handler.h \
    app/Core/ISceneBase.h \
    app/Core/infostore.h


      

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
    qrc/Scenes/Enumeration.qml \
    qrc/Scenes/ScrollBar.qml \
    qrc/Scenes/ToggleButton_160_80.qml \
    qrc/Scenes/screen01.qml \
    build.sh \
    ReadMe.txt \
    qrc/Scenes/BtnListElement.qml \
    qrc/Scenes/List_T_3_2.qml \
    qrc/Scenes/screen02.qml \
    qrc/Scenes/screen03.qml \
    qrc/images/backButton.png \
    qrc/Scenes/BackButton_160_80.qml \
    qrc/Scenes/PushButton_250_50 .qml \ 
    qrc/Scenes/PushButton_250_50.qml \
    qrc/Scenes/ListView_250_250.qml \
    qrc/Scenes/ListEleement_250_250.qml
 
 

SUBDIRS += \
    SampleProject.pro
