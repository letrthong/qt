#ifndef SINGLETON_H
#define SINGLETON_H

#include "MainController.h"

class Singleton
{

public :

    Singleton();

    static  Singleton *getSingle();




    void setPointerOfController(MainController *pMainController);

    MainController * getPointerOfController();
private :

    static Singleton *m_singleton ;
    MainController *_pMainController;
};

#endif // SINGLETON_H
