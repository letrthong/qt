#include <QObject>
 #include <QVariant> 
 #include   <QString>
 
  class SignalManager : public QObject
  {
      Q_OBJECT
  public slots:
      void cppSlot(const QString &msg);
        
  };