#include "MainController.h"
#include <QDebug>
#include  <iostream>
using namespace std;

#include "SceneBase.h"
#include "screen01Handler.h"
#include "infostore.h"


MainController::MainController(InfoStore *pInfoStor )
{
    _pQuickView = new QQuickView;
    _pScreen = NULL;
    _pInfoStore = pInfoStor;
    isRuning = true;
    pTimer =  new QTimer(this);
    connect(pTimer, SIGNAL(timeout()), this, SLOT(update()));
    pTimer->start(100);
    screenIndex = 1;

}

MainController::~MainController(){



    isRuning = false;
}

void MainController::update()
{
    pTimer->start(20);
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
    if(_pScreen != NULL){
        delete  _pScreen;
        _pScreen = NULL;
    }

   static bool flag = true;
    if(flag == true){
        _pScreen = new screen01Handler( _pQuickView);
        _pScreen->createScene("./qrc/Scenes/screen01.qml");
        flag = false;
    }
    else{
        _pScreen = new screen01Handler( _pQuickView);
        _pScreen->createScene("./qrc/Scenes/screen02.qml");
         flag = true;
    }
}
