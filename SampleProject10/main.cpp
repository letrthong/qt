#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QObject>
#include <QGraphicsObject>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickView>


 

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
      

    QQuickView view ;
    view.setSource(QUrl::fromLocalFile("qrc/main.qml"));
    view.show();
  
    QObject *rect = dynamic_cast<QObject*>(view.rootObject());
    rect->setProperty("width", 500);
 
      return app.exec();
}


 