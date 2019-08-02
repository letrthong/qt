#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

 int main(int argc, char *argv[]) 
 {
     QApplication app(argc, argv);
     MainWindow mainWindow;
     mainWindow.showMaximized();

     QDesktopWidget dw;
    int x=dw.width()*0.7;
    int y=dw.height()*0.9;
    mainWindow.setFixedSize(x,y);

     return app.exec();
 }