#ifndef SINGLETON_H
#define SINGLETON_H

#include "MainController.h"
#include "SignalManager.h"

class ItemCheckBoxText;

class Singleton
{
public :
    Singleton();
    static  Singleton *getSingle();

    void setPointerOfController(MainController *pMainController);
    MainController* getPointerOfController();


    void setPointerOfSignalManager(SignalManager* pSignalManager);
    SignalManager* getPointerOfSignalManager();

private :
    static Singleton* m_singleton ;
    MainController* _pMainController;
    SignalManager* _pSignalManager;
};

#endif // SINGLETON_H
