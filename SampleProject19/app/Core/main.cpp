 #include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QQmlComponent>
#include <QQuickView>

#include "BackEnd.h"
#include "SignalManager.h"

#include <string>

#include <thread>
		
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
 
    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0,  "BackEnd");

    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile("./qrc/Scenes/screen01.qml"));

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

        }

    }

     //QML to C++
      SignalManager signalManager;
     QObject::connect(window, SIGNAL(qmlSignalButton(int, QString)), &signalManager,SLOT(onclickCppSlot(int,QString)));

      //C++ to QML
     QObject::connect(&signalManager, SIGNAL(setTextFieldCpp(QVariant)),window, SLOT(setTextField(QVariant)));

     foreach(QObject* n, qlist)
     {

         QObjectList objectList =  n->children();

         for (QObject *object : objectList)
         {
             QString  QclassName = object->metaObject()->className();
              std::string className = QclassName.toStdString();

              qInfo() << QclassName;
            if(className.find("PushButton") != std::string::npos)
            {

                QObject::connect(&signalManager, SIGNAL(setProperrtyCpp(QVariant)),object, SLOT(setVisible(QVariant)));
            }
         }

     }




    return app.exec();
} 


 
