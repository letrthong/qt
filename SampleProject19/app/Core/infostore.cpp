#include "infostore.h"
#include <QDebug>
#include  <iostream>
using namespace std;


InfoStore::InfoStore(ISceneBase* pSceneBase){
    _pSceneBase = pSceneBase;
    _isRunning = false;
}

InfoStore::~InfoStore()
{
    if(true ==_isRunning){
        _isRunning = false;
    }

    if(_pSceneBase){
        _pSceneBase = NULL;
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
        this->sendUpdated(index);
    }
}

void InfoStore::startThread(){
    _isRunning = true;
    QThread::start();
}
