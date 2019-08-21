#include "MyClass.h"
#include <QDebug>

void MyClass::cppSlot(const QString &msg)
{
  qDebug() << "Called the C++ slot with message:" << msg;
}


