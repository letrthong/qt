#ifndef SINGAL_MANAGER_H_
#define SINGAL_MANAGER_H_

#include <QObject>
#include <QVariant>
#include <QString>

#include "ISceneBase.h"

class SignalManager :public QObject
{
  Q_OBJECT
  public slots:
        void onclickCppSlot(int sendTo, const QString &msg);
        void onItemClickcppSlot(int index, bool state);

  signals:
        void setTextFieldCpp(QVariant text);
        void setProperrtyCpp(QVariant text);

        void  actionButton(int sendTo, const QString &msg);

  public :
        SignalManager(ISceneBase* pSceneBase);
        ~SignalManager();
        void  handleSubmitTextField(const QString &in);

  private:
        ISceneBase* _pSceneBase;
};
#endif // SINGAL_MANAGER_H_
