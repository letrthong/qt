#include "Infostore.h"
#include <QDebug>
#include  <iostream>
using namespace std;


InfoStore::InfoStore(SceneBase* pSceneBase){
    _pSceneBase = pSceneBase;
    _isRunning = false;
    _isEnable = false;

    _mapList.insert({0, {"", "text00", "text", "" } });
    _mapList.insert({1, {"false", "text01", "checkbox", "" } });
    _mapList.insert({2, {"false", "text02", "checkbox", "../images/icon01.jpg" } });
    _mapList.insert({3, {"false", "text03", "switch" , "" } });
    _mapList.insert({4, {"1", "text04", "comboBox" , "" } });
      _mapList.insert({5, {"1", "text05", "spinBox" , "" } });

     qInfo() << "InfoStore::constructure";
}

 InfoStore::InfoStore( )
 {
     _mapList.insert({0, {"", "text00", "text", "" } });
     _mapList.insert({1, {"false", "text01", "checkbox", "" } });
     _mapList.insert({2, {"false", "text02", "checkbox", "../images/icon01.jpg" } });
     _mapList.insert({3, {"false", "text03", "switch" , "" } });
      _mapList.insert({4, {"1", "text04", "comboBox" , "" } });
     _mapList.insert({5, {"1", "text05", "spinBox" , "" } });
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

void InfoStore::setBool(bool flag){
    _isEnable = flag;
}

bool InfoStore::getBool(){
    return _isEnable;
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

void InfoStore::updateItemOfList(int index,  std::string status){
     std::map<int, struct itemOfList>::iterator it = _mapList.find(index);

     if (it != _mapList.end()){
        it->second.value = status;
     }
}
std::map<int, struct itemOfList>  InfoStore::getItemOfList(){
    return _mapList;
}
