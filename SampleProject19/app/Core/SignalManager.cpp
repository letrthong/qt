#include "SignalManager.h"
#include <QDebug>
#include "singleton.h"
#include "DefComposite.h"

SignalManager::SignalManager(ISceneBase* pSceneBase){
    _pSceneBase = pSceneBase;
    QObject::connect(this, SIGNAL(actionButton(int, QString)),  Singleton::getSingle()->getPointerOfController(),SLOT(eventClickCppSlot(int,QString)));
}

SignalManager::~SignalManager(){
    QObject::disconnect(this, SIGNAL(actionButton(int, QString)), Singleton::getSingle()->getPointerOfController(),SLOT(eventClickCppSlot(int,QString)));
}

void SignalManager::onclickCppSlot(int sendTo, const QString &msg){
    static int count = 0;
    count++;
    qDebug() << "onclickCppSlot::Called the C++ slot with message:" << msg <<" count="<<  count;

  if(1 == sendTo){
      unsigned int type = TYPE_UNKNOW;
      std::string  name = msg.toStdString();
       qDebug()<<"onclickCppSlot::sendTo Model";

       if( name.find("PushButton") != std::string::npos) {
           emit setProperrtyCpp( msg);
           qDebug() << "onclickCppSlot::emit setProperrtyCpp";
           type = TYPE_PUSH_BUTTON;
       } else if( name.find("ToggleButton") != std::string::npos){
            type = TYPE_TOGGLE_BUTTON;
             handleSubmitTextField("C++ to Qml");
       }

       _pSceneBase->onClickListener(type , msg.toStdString());
  }
  else {
      qDebug()<<"onclickCppSlot::sendTo Controlller";
      emit actionButton(1, "state machine");
  }
}

void SignalManager::onItemClickcppSlot(int index, bool state){
    qDebug() << "SignalManager::onItemClickcppSlot: index="<< index <<" state="<<  state;
}

void SignalManager::handleSubmitTextField(const QString &in){
    qDebug() << "handleSubmitTextField::" << in;
    emit setTextFieldCpp(in.toUpper());
}
