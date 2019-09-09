#ifndef SINGAL_MANAGER_H_
#define SINGAL_MANAGER_H_


#include <QObject>
 #include <QVariant> 
 #include   <QString>
 
  class SignalManager : public QObject
  {
      Q_OBJECT
  public slots:
      void onclickCppSlot(int sendTo, const QString &msg);

  signals:
    void setTextFieldCpp(QVariant text);
     void setProperrtyCpp(QVariant text);

  public :
         void  handleSubmitTextField(const QString &in);
  };

  #endif // SINGAL_MANAGER_H_
