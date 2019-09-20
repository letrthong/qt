#ifndef SCREEN_02_HANDLER_H_
#define SCREEN_02_HANDLER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickView>


#include "SceneBase.h"

class screen02Handler : public SceneBase
{
  public:
     explicit screen02Handler(QQuickView * pQuickView);

     void onClick(const std::string& from) override;
     void onChanged(int id) override;
  private:
     void testApi();
};
#endif // SCREEN_02_HANDLER_H_
