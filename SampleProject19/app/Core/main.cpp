 #include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QQmlComponent>
#include <QQuickView>

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

     QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

     QList<QObject *>  qlist=  engine.rootObjects();
    foreach(QObject* n, qlist)
    {
        qDebug() << n->objectName();
         qInfo() << "qlist" ;

        QObjectList objectList =  n->children();

        for (QObject *object : objectList)
        {
            qInfo() << "\t" << object;
            qInfo() << "\t id=" << object->property("id");
        }

    }

     //QML to C++
      SignalManager signalManager;
     QObject::connect(window, SIGNAL(qmlSignal(QString)), &signalManager,SLOT(cppSlot(QString)));

      //C++ to QML
     QObject::connect(&signalManager, SIGNAL(setTextFieldcpp(QVariant)),window, SLOT(setTextField(QVariant)));

    return app.exec();
} 


 
