#include "SignalManager.h"
#include <QDebug>

void SignalManager::cppSlot(const QString &msg)
{
    static int count = 0;
    count++;
  qDebug() << "Called the C++ slot with message:" << msg <<" count="<<  count;
}

