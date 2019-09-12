#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include  "SceneBase.h"
#include  <QObject>
#include  <QThread>

#include  "infostore.h"
#include <QQuickView>
#include <QTimer>

class MainController  : public QObject
{
    Q_OBJECT
public:
    MainController(InfoStore *pInfoStore);
    ~MainController();
    void startThread();

public slots:
      void onControllerSlot(QVariant id);
     void eventClickCppSlot(int sendTo, const QString &msg) ;

      void update();
private:

     void loadScreen( );
private:
      SceneBase *_pScreen ;
      InfoStore *_pInfoStore;
      QQuickView * _pQuickView;
      bool isRuning;
      QTimer *pTimer;

      int  screenIndex;


};

#endif // MAIN_CONTROLLER_H
