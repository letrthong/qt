#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include  "SceneBase.h"
#include  <QObject>
#include  <QThread>
#include <QQueue>
#include  "Infostore.h"
#include <QQuickView>
#include <QTimer>

class MainController  :public QObject
{
    Q_OBJECT
public:
    MainController(InfoStore *pInfoStore);
    ~MainController();
    void startThread();

public slots:
      void onControllerSlot(QVariant id);
     void eventClickCppSlot(int sendTo, const QString &msg) ;

      void onTimeoutSlot();
private:

     void loadScreen();
     int parseStateChart();
private:
      SceneBase *_pCurrentScreen ;
      InfoStore *_pInfoStore;
      QQuickView * _pQuickView;

      QTimer *_pTimer;

      int  screenIndex;

      static QQueue<QString>  _qMessage;
};

#endif // MAIN_CONTROLLER_H
