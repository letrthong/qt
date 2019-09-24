#ifndef SCREEN_02_HANDLER_H_
#define SCREEN_02_HANDLER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickView>
#include "Infostore.h"
#include "SceneBase.h"


class screen02Handler :public SceneBase
{
  public:
     explicit screen02Handler(QQuickView * pQuickView, InfoStore *pInfoStore);

    /*
     * when Clicking on button from QML
     */
     void onToggleButtonClick(const std::string& from) override;

     /*
      * when middleware changed data
      */
     void onPropertyChange(int id) override;
  private:
     void initScene() override;

     void testApi();
      InfoStore *_pInfoStore;
};
#endif // SCREEN_02_HANDLER_H_
