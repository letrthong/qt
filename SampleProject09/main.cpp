#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QObject>
 
int main(int argc, char *argv[])
{
       QGuiApplication app(argc, argv);
      
      
    QQuickView *view = new QQuickView;
    view->setSource(QUrl::fromLocalFile("qrc/main.qml"));
    view->show();



    
      return app.exec();
}