#include "SignalManager.h"
#include <QDebug>
#include "singleton.h"


SignalManager::SignalManager(ISceneBase* pSceneBase){
    _pSceneBase = pSceneBase;

    QObject::connect(this, SIGNAL(actionButton(int, QString)),   Singleton::getSingle()->getPointerOfController(),SLOT(eventClickCppSlot(int,QString)));
}

SignalManager::~SignalManager(){
    QObject::disconnect(this, SIGNAL(actionButton(int, QString)),   Singleton::getSingle()->getPointerOfController(),SLOT(eventClickCppSlot(int,QString)));

}
void SignalManager::onclickCppSlot(int sendTo, const QString &msg){
    static int count = 0;
    count++;
  qDebug() << "onclickCppSlot::Called the C++ slot with message:" << msg <<" count="<<  count;

  if(1 == sendTo){
       qDebug()<<"onclickCppSlot::sendTo Model";
       if(msg == "PushButton/button01") {
           emit setProperrtyCpp("PushButton/button02");
           qDebug() << "onclickCppSlot::emit setProperrtyCpp";
       }

       _pSceneBase->onClickListener(msg.toStdString());
  }
  else {
      qDebug()<<"onclickCppSlot::sendTo Controlller";
      emit actionButton(1, "state machine");
  }

  handleSubmitTextField("C++ to Qml");
}


void SignalManager::handleSubmitTextField(const QString &in){
    qDebug() << "handleSubmitTextField::" << in;
    emit setTextFieldCpp(in.toUpper());
}
