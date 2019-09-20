#ifndef SCENE_BASE_H_
#define SCENE_BASE_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QMainWindow>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "SignalManager.h"
#include "ISceneBase.h"
#include <vector>
#include <QQuickView>
#include <QQuickItem>

class SceneBase  : public QObject, public ISceneBase
{
    Q_OBJECT
  public:
    explicit SceneBase( QQuickView * pQuickView);
    virtual ~SceneBase();

    void  createScene(const QString & screenName);


    void onClickListener(const std::string& from)  override;
    void onChangedListener(int id)  override;

  protected:
     virtual void onClick(const std::string& from);
     virtual void onChanged(int id);
    virtual  void  getListDataProvider();

     void setVisibleButton(const std::string& buttonName, bool visible);

public slots:
      void onInfoStoreSlot(QVariant id);

  private:
      SignalManager*  _pSignalManager;

      QQuickView * _pQuickView;
      QQmlContext* _pQmlContext;
      QObject*  _pMainScreen;

      std::vector<QQuickItem*> _vecButton;

      QQuickItem* _pQQuickListView;
};
#endif // SCENE_BASE_H_
