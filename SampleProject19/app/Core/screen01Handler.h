#ifndef SCREEN_01_HANDLER_H_
#define SCREEN_01_HANDLER_H_

#include <QObject>
#include <QVariant>
#include <QString>

#include "SceneBase.h"

class screen01Handler : public SceneBase
{
  public:
     explicit screen01Handler(QQmlApplicationEngine* pEngine);

     void  onClick(const std::string& from) override;
  private:
};
#endif // SCREEN_01_HANDLER_H_
