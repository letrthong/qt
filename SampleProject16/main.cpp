#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include <QQmlComponent>


#include "BackEnd.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
 
    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0,  "BackEnd");

    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile("qrc/main.qml"));

    
    return app.exec();
}