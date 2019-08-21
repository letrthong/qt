#include <QObject>
 #include <QVariant> 
 #include   <QString>
 
  class MyClass : public QObject
  {
      Q_OBJECT
  public slots:
      void cppSlot(const QString &msg);
        
  };