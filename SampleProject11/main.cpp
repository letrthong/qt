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
  
    QObject *object = dynamic_cast<QObject*>(view.rootObject());
    object->setProperty("width", 500);
	
	QObject *rect = object->findChild<QObject*>("rect");
	if (rect)
	{
		 rect->setProperty("color", "red");
	}
     
    return app.exec();
}


 