#ifndef SCENE_BASE_H_
#define SCENE_BASE_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QMainWindow>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQuickView>

#include <vector>

#include "SignalManager.h"
#include "ISceneBase.h"

class SceneBase :public QObject, public ISceneBase
{
    Q_OBJECT
  public:
        explicit SceneBase( QQuickView * pQuickView);
        virtual ~SceneBase();

        void  createScene(const QString & screenName);

        void onClickListener(unsigned int type,  const std::string& from)  override;
        void onChangedListener(int id)  override;
  protected:
        virtual void onPushButtonClick(const std::string& from);
        virtual void onToggleButtonClick(const std::string& from);
        virtual void onPropertyChange(int id);
        virtual void getListDataProvider();
        virtual void initScene();

        void setPushButtonVisible(const std::string& pushButtonName, bool visible);

        void setTextViewText(const std::string& TextVievName, const std::string& text);

        void initToggleButtonValue(const std::string& toggleButtonName, bool isOn);
        void disableToggleButton(const std::string& toggleButtonName, bool isEnable);

public slots:
        void onInfoStoreSlot(QVariant id);

  private:
        SignalManager*  _pSignalManager;

        QQuickView * _pQuickView;
        QQmlContext* _pQmlContext;
        QObject*  _pMainScreen;

        std::vector<QQuickItem*> _vecPushButton;
        std::vector<QQuickItem*> _vecToggleButton;

        std::vector<QQuickItem*> _vecTextView;
        std::vector<QQuickItem*> _vecEditText;
        QQuickItem* _pQQuickListView;
};
#endif // SCENE_BASE_H_
