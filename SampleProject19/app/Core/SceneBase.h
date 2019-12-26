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
#include <string>

#include "SignalManager.h"
#include "ISceneBase.h"

class SceneBase :public QObject, public ISceneBase
{
    Q_OBJECT
  public:
        explicit SceneBase( QQuickView * pQuickView);
        virtual ~SceneBase();

        void  createScene(const QString & screenName);
        void   destroyScreen();

        void onClickListener(unsigned int type,  const std::string& from)  override;
        void onChangedListener(int id)  override;
        void onClickItemOfList(int index, std::string status) override;
  protected:
        virtual void onPushButtonClick(const std::string& from);
        virtual void onToggleButtonClick(const std::string& from);
        virtual void onPropertyChange(int id);
        virtual void onListItemClick();
        virtual void onListItemClick(int index, std::string status);


        virtual void initScene();

        virtual unsigned int getListId();
        virtual QVariant   getListDataProvider();

        void setPushButtonVisible(const std::string& pushButtonName, bool visible);

        void setTextViewText(const std::string& TextVievName, const std::string& text);

        void initToggleButtonValue(const std::string& toggleButtonName, bool isOn);
        void disableToggleButton(const std::string& toggleButtonName, bool isEnable);

public slots:
        void onInfoStoreSlot(QVariant id);
		void  closePopup();

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


		QObject* _pPopup;
};
#endif // SCENE_BASE_H_
