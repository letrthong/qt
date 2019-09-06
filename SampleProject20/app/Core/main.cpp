 #include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QQmlComponent>
#include <QQuickView>
#include <QObjectList>


#include "BackEnd.h"
#include "SignalManager.h"


#include <thread>
		
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
 
    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0,  "BackEnd");

    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile("qrc/Scenes/screen01.qml"));

     QObject *topLevel = engine.rootObjects().at(0);

     QList<QObject *>  qlist=  engine.rootObjects();
    foreach(QObject* n, qlist)
    {
        qDebug() << n->objectName();
         qInfo() << "qlist" ;

        QObjectList objectList =  n->children();

        for (QObject *object : objectList)
        {
            qInfo() << "\t" << object;
        }

    }

    QObject *qmlObject = NULL;
    if ( engine.rootObjects().first()->objectName() == "backButton") {
        qmlObject = engine.rootObjects().first();
         qInfo() << "objectName" ;
    } else {
        qmlObject = engine.rootObjects().first()->findChild<QObject*>("backButton");
         qInfo() << "findChild" ;
    }

    if(qmlObject)
    {
        qInfo() << "ThongLT0" ;
    }
    else
    {
         qInfo() << "ThongLT1" ;
    }   


     QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    SignalManager signalManager;

     QObject::connect(window,
                        SIGNAL(qmlSignal(QString)),
                        &signalManager,
                        SLOT(cppSlot(QString))
                        );
    return app.exec();
} 


 
