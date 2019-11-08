#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include  "SceneBase.h"
#include  <QObject>
#include  <QThread>
#include <QQueue>
#include  "Infostore.h"
#include <QQuickView>
#include <QTimer>
#include <QDomElement>
#include <QMutex>

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
     QString  parseStateChart();
     QString nextSceenbutton( const QString &currentSceen,const QString &  buttonName);
     QString nextSceenItem( const QString &currentSceen, int ListId);
     QString nextSceenBack( const QString &currentSceen );
private:
      SceneBase *_pCurrentScreen ;
      InfoStore *_pInfoStore;
      QQuickView * _pQuickView;

      QTimer *_pTimer;

      int  screenIndex;
      QDomDocument xmlBOM;
      QDomElement _DomElement ;

      QMutex mutex;

      QString _initScreen;

      QString _prexScreen;
      QString _curxScreen;

      static QQueue<QString>  _qMessage;
};

#endif // MAIN_CONTROLLER_H
