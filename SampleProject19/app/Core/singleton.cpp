#include "singleton.h"

Singleton *Singleton::m_singleton = NULL;


Singleton::Singleton()
{
    m_singleton = NULL;
}

Singleton *Singleton::getSingle()
{
    if (m_singleton == NULL)
    {
        m_singleton = new Singleton;
    }
    return m_singleton;
}

void Singleton::setPointerOfController(MainController *pMainController)
{
    _pMainController = pMainController;
}

MainController * Singleton::getPointerOfController()
{
   return _pMainController;
}
