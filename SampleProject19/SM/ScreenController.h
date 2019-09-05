#ifndef SCREEN_CONTROLLER_H_
#define SCREEN_CONTROLLER_H_

#include <QObject>
 #include <QVariant> 
 #include   <QString>
 
  class ScreenController 
  {
    public:
    void  createScreen(const QString & screenName);
    void  destroyScreen(const QString & screenName);
    private: 
  };
#endif  // SCREEN_CONTROLLER_H_
