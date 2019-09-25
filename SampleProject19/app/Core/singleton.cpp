#include "singleton.h"

Singleton *Singleton::m_singleton = nullptr;


Singleton::Singleton(){
    m_singleton = nullptr;
}

Singleton *Singleton::getSingle(){
    if (m_singleton == nullptr) {
        m_singleton = new Singleton;
    }
    return m_singleton;
}

void Singleton::setPointerOfController(MainController *pMainController){
    _pMainController = pMainController;
}

MainController * Singleton::getPointerOfController(){
   return _pMainController;
}

void Singleton::setPointerOfSignalManager(SignalManager* pSignalManager){
    _pSignalManager = pSignalManager;
}

SignalManager* Singleton::getPointerOfSignalManager(){
    return _pSignalManager;
}
