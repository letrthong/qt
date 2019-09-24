#ifndef SCREEN_01_HANDLER_H_
#define SCREEN_01_HANDLER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickView>
#include "Infostore.h"
#include "SceneBase.h"

class screen01Handler :public SceneBase
{
  public:
     explicit screen01Handler(QQuickView * pQuickView, InfoStore *pInfoStore);

     /*
      * when Clicking on button from QML
      */
     void onToggleButtonClick(const std::string& from) override;


     /*
      * When middleware changed data
      */
     void onPropertyChange(int id) override;
  private:
      void initScene() override;
     void testApi();
      InfoStore *_pInfoStore;

};
#endif // SCREEN_01_HANDLER_H_
