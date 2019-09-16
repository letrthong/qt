#include "MainController.h"
#include <QDebug>
#include  <iostream>
using namespace std;

#include "SceneBase.h"
#include "screen01Handler.h"
#include "infostore.h"
#include <QDateTime>
#include <QQmlContext>

MainController::MainController(InfoStore *pInfoStor )
{
    _pQuickView = new QQuickView;

    _pQuickView->rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());

    _pInfoStore = pInfoStor;

    _pCurrentScreen = NULL;

    _pTimer =  new QTimer(this);
    connect(_pTimer, SIGNAL(timeout()), this, SLOT(onTimeoutSlot()));
    _pTimer->start(100);
    screenIndex = 1;
}

MainController::~MainController(){
    _pInfoStore = NULL;

    _pTimer->destroyed();
    delete _pTimer;
    _pTimer = NULL;
}

void MainController::onTimeoutSlot()
{
    _pTimer->start(100);
    if( screenIndex> 0)
    {
        screenIndex = 0;
        loadScreen();
    }
}

void MainController::eventClickCppSlot(int sendTo, const QString &msg)
{
    screenIndex = screenIndex+ 1;
     qInfo() << "\n MainController::eventClickCppSlot"  <<  screenIndex++;

}

void MainController::onControllerSlot(QVariant id){

    qInfo() << "\n MainController::onControllerSlot"  ;
    loadScreen();
}

void MainController::loadScreen( )
{
    if(_pCurrentScreen != NULL){
        delete  _pCurrentScreen;
        _pCurrentScreen = NULL;
    }

   static bool flag = true;
    if(flag == true){
        _pCurrentScreen = new screen01Handler( _pQuickView);
        _pCurrentScreen->createScene("./qrc/Scenes/screen01.qml");
        flag = false;
    }
    else{
        _pCurrentScreen = new screen01Handler( _pQuickView);
        _pCurrentScreen->createScene("./qrc/Scenes/screen02.qml");
         flag = true;
    }
}
