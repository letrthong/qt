#include "MainController.h"
#include <QDebug>
#include  <iostream>
using namespace std;

#include "SceneBase.h"
#include "screen01Handler.h"
#include "screen02Handler.h"
#include "screen03Handler.h"
#include "Infostore.h"
#include <QDateTime>
#include <QQmlContext>

MainController::MainController(InfoStore *pInfoStor ){
    _pQuickView = new QQuickView;

    //https://doc.qt.io/qt-5/qtqml-cppintegration-contextproperties.html
    _pQuickView->rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());

    _pInfoStore = pInfoStor;

    _pCurrentScreen = nullptr;

    _pTimer =  new QTimer(this);
    connect(_pTimer, SIGNAL(timeout()), this, SLOT(onTimeoutSlot()));
    _pTimer->start(100);
    screenIndex = 1;
}

MainController::~MainController(){
    _pInfoStore = nullptr;

    _pTimer->destroyed();
    delete _pTimer;
    _pTimer = nullptr;
}

void MainController::onTimeoutSlot(){
    _pTimer->start(100);
    if( screenIndex> 0){
        screenIndex = 0;
        loadScreen();
    }
}

void MainController::eventClickCppSlot(int sendTo, const QString &msg){
    screenIndex = screenIndex+ 1;
    qInfo() << "\n MainController::eventClickCppSlot"  <<  screenIndex++;
}

void MainController::onControllerSlot(QVariant id){
    qInfo() << "\n MainController::onControllerSlot"  ;
    loadScreen();
}

void MainController::loadScreen(){
    if(_pCurrentScreen != nullptr){
        delete  _pCurrentScreen;
        _pCurrentScreen = nullptr;
    }

   static int indexScreen = 0;

   if(0 == indexScreen){
       _pCurrentScreen = new screen01Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen01.qml");
   }else  if(1== indexScreen){
       _pCurrentScreen = new screen02Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen02.qml");
   }else if( 2== indexScreen) {
       _pCurrentScreen = new screen03Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen03.qml");
    }

   indexScreen++;
   if(indexScreen>  2){
       indexScreen = 0;
   }
}


