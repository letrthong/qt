#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QObject>
#include <QGraphicsObject>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>

#include "MyClass.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
      

    QQuickView view ;
    view.setSource(QUrl::fromLocalFile("qrc/main.qml"));
   
  
    QObject *item = dynamic_cast<QObject*>(view.rootObject());
   
       MyClass myClass;
      QObject::connect(item, SIGNAL(qmlSignal(QString)), &myClass, SLOT(cppSlot(QString)));
					   
	 view.show();				   
    return app.exec();
}


 