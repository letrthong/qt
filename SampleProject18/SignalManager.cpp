#include "SignalManager.h"
#include <QDebug>

void SignalManager::cppSlot(const QString &msg)
{
  qDebug() << "Called the C++ slot with message:" << msg;
}


