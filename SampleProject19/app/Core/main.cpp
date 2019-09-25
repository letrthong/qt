#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "MainController.h"
#include "SceneBase.h"
#include "Infostore.h"
#include "singleton.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);
    InfoStore* pInfoStore = new InfoStore();
    pInfoStore->startThread();

    MainController* pController = new MainController(pInfoStore);

    Singleton::getSingle()->setPointerOfController(pController);

    QObject::connect(pInfoStore, SIGNAL(sendControllerSignal(QVariant)),  pController,SLOT(onControllerSlot(QVariant)));

    return app.exec();
} 


 
