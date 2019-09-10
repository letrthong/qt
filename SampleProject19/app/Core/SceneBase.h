#ifndef SCENE_BASE_MANAGER_H_
#define SCENE_BASE_MANAGER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QMainWindow>
#include <QQmlApplicationEngine>

#include "SignalManager.h"
#include "ISceneBase.h"

class SceneBase  : public QObject, public ISceneBase
{
      Q_OBJECT
   public:
    explicit SceneBase(QQmlApplicationEngine* pEngine);

      void  createScene(const QString & screenName);
      void  viewScene(const QString & screenName);
      void  hideScene(const QString & screenName);
      void  destroyScenen(const QString & screenName);


     void onClickListener(const std::string& from)  override;
     void onUpdateListener(int id)  override;
protected:
     virtual void  onClick(const std::string& from);

  private:
      QQmlApplicationEngine* _pEngine;
      SignalManager*  _pSignalManager;
};
#endif // SCENE_BASE_MANAGER_H_
