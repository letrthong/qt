#ifndef SCENE_BASE_MANAGER_H_
#define SCENE_BASE_MANAGER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QMainWindow>
#include <QQmlApplicationEngine>

#include "SignalManager.h"
#include "ISceneBase.h"
#include <vector>


class SceneBase  : public QObject, public ISceneBase
{
      Q_OBJECT
  public:
    explicit SceneBase(QQmlApplicationEngine* pEngine);

      void  createScene(const QString & screenName);
      void  viewScene(const QString & screenName);
      void  hideScene(const QString & screenName);
      void  destroyScene(const QString & screenName);

     void onClickListener(const std::string& from)  override;
     void onChangedListener(int id)  override;

  protected:
     virtual void onClick(const std::string& from);
     virtual void onChanged(int id);

     void setVisibleButton(const std::string& buttonName, bool visible);

public slots:
      void onInfoStoreSlot(QVariant id);

  private:
      QQmlApplicationEngine* _pEngine;
      SignalManager*  _pSignalManager;

      std::vector<QObject*> _vecButton;
};
#endif // SCENE_BASE_MANAGER_H_
