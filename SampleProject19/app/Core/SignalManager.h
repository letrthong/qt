#ifndef SINGAL_MANAGER_H_
#define SINGAL_MANAGER_H_

#include <QObject>
#include <QVariant>
#include <QString>

#include "ISceneBase.h"

class SignalManager : public QObject
{
      Q_OBJECT
  public slots:
        void onclickCppSlot(int sendTo, const QString &msg);

  signals:
        void setTextFieldCpp(QVariant text);
        void setProperrtyCpp(QVariant text);

  public :
        SignalManager(ISceneBase* pSceneBase);
        void  handleSubmitTextField(const QString &in);

  private:
        ISceneBase* _pSceneBase;
};
#endif // SINGAL_MANAGER_H_
