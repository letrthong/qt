#include "infostore.h"
#include <thread>

InfoStore::InfoStore(ISceneBase* pSceneBase)
{
    _pSceneBase = pSceneBase;

   //  std::thread threadObj(runThread);
}

void InfoStore::setText(const std::string& text)
{
    _text = text;
}

std::string InfoStore::getText()
{
    return  this->_text;
}


void InfoStore::sendUpdated(int id){
     _pSceneBase->onUpdateListener(id);
}


void* InfoStore::runThread()
{
    return NULL;
}


void InfoStore::startThread()
{

}
