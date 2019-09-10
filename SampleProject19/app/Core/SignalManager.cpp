#include "SignalManager.h"
#include <QDebug>
SignalManager::SignalManager(ISceneBase* pSceneBase)
 {
    _pSceneBase = pSceneBase;
 }


void SignalManager::onclickCppSlot(int sendTo, const QString &msg)
{
    static int count = 0;
    count++;
  qDebug() << "onclickCppSlot::Called the C++ slot with message:" << msg <<" count="<<  count;

  if(1 == sendTo){
       qDebug()<<"onclickCppSlot::sendTo Model";
       if(msg == "pushButton/button01") {
           emit setProperrtyCpp("pushButton/button02");
           qDebug() << "onclickCppSlot::emit setProperrtyCpp";
       }

       _pSceneBase->onClickListener(msg.toStdString());
  }
  else {
      qDebug()<<"onclickCppSlot::sendTo Controlller";
  }


  handleSubmitTextField("C++ to Qml");
}


void SignalManager::handleSubmitTextField(const QString &in)
{
    qDebug() << "handleSubmitTextField::" << in;
    emit setTextFieldCpp(in.toUpper());
}
