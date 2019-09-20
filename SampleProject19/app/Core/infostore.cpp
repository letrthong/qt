#include "infostore.h"
#include <QDebug>
#include  <iostream>
using namespace std;


InfoStore::InfoStore(SceneBase* pSceneBase){
    _pSceneBase = pSceneBase;
    _isRunning = false;
}

 InfoStore::InfoStore( )
 {
     _pSceneBase = nullptr;
 }

InfoStore::~InfoStore()
{
    if(true ==_isRunning){
        _isRunning = false;
    }

    if(_pSceneBase){
        _pSceneBase = nullptr;
    }
}
void InfoStore::setText(const std::string& text){
    _text = text;
}

std::string InfoStore::getText(){
    return  this->_text;
}

void InfoStore::sendUpdated(int id){
    if(_pSceneBase){
         _pSceneBase->onChangedListener(id);
    }
}

void  InfoStore::run(){
    qInfo() << "star thread" ;
    int index = 0;
    while (true == _isRunning) {
        cout<<"\npress index=?";
        cin>> index;
        //this->sendUpdated(index);

        if(_pSceneBase != nullptr) {
             emit sendInfoStoreSignal(index);
        }
        else {
            emit sendControllerSignal(index);
        }
    }
}

void InfoStore::startThread(){

    _isRunning = true;
    if(_pSceneBase != nullptr) {
          QObject::connect(this, SIGNAL(sendInfoStoreSignal(QVariant)),  _pSceneBase,SLOT(onInfoStoreSlot(QVariant)));
    }
    QThread::start();
}
