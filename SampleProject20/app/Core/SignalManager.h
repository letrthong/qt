#ifndef SINGAL_MANAGER_H_
#define SINGAL_MANAGER_H_


#include <QObject>
 #include <QVariant> 
 #include   <QString>
 
  class SignalManager : public QObject
  {
      Q_OBJECT
  public slots:
      void cppSlot(const QString &msg);
        
  };

  #endif // SINGAL_MANAGER_H_