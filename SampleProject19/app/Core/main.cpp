#include <QGuiApplication>
#include "SceneBase.h"
#include "screen01Handler.h"
#include <QQmlApplicationEngine>
#include "infostore.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    SceneBase *pScreen = new screen01Handler(&engine);

    InfoStore* pInfoStore = new InfoStore(pScreen);
    pInfoStore->startThread();
    pScreen->createScene("./qrc/Scenes/screen01.qml");


    return app.exec();
} 


 
