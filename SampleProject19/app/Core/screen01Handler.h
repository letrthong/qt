#ifndef SCREEN_01_HANDLER_H_
#define SCREEN_01_HANDLER_H_

#include <QObject>
#include <QVariant>
#include <QString>
#include <QQuickView>


#include "SceneBase.h"

class screen01Handler : public SceneBase
{
  public:
     explicit screen01Handler(QQuickView * pQuickView);

     void onClick(const std::string& from) override;
     void onChanged(int id) override;
  private:
     void testApi();
};
#endif // SCREEN_01_HANDLER_H_
