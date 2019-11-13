#ifndef SCREEN_03_HANDLER_H_
#define SCREEN_03_HANDLER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickView>
#include "Infostore.h"
#include "SceneBase.h"


class screen03Handler :public SceneBase
{
  public:
    explicit screen03Handler(QQuickView * pQuickView, InfoStore *pInfoStore);

    /*
    * when Clicking on button from QML to set new value for parameter
    */
    void onToggleButtonClick(const std::string& from) override;

    /*
    * when middleware changed data
    */
    void onPropertyChange(int id) override;
  private:

     unsigned int getListId() override;
     QVariant  getListDataProvider() override;
     void onListItemClick(int index, std::string status) override;

     void testApi();
      InfoStore *_pInfoStore;
};
#endif // SCREEN_03_HANDLER_H_
