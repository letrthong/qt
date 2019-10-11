#ifndef INFO_STORE_H
#define INFO_STORE_H

#include  "SceneBase.h"
#include  <QThread>
#include <map>
#include <string>

struct itemOfList{
    std::string value;
    std::string text;
    std::string type;
    std::string icon;
};

class InfoStore  :public  QThread
{
   Q_OBJECT
public:
    InfoStore(SceneBase* pSceneBase);
    InfoStore( );
    ~InfoStore();

    void setText(const std::string& text);
    std::string getText();


    void updateItemOfList(int index,  std::string status);
    std::map<int, struct itemOfList>  getItemOfList();

    void setBool(bool flag);
    bool getBool();

    void sendUpdated(int id);
   void startThread();
private:
    void run() override;

private:
        std::string _text;
        bool _isEnable;
        SceneBase* _pSceneBase;
        bool _isRunning;
        std::map<int, struct itemOfList> _mapList;

  signals:
      void sendInfoStoreSignal(QVariant id);
      void sendControllerSignal(QVariant id);

};

#endif // INFO_STORE_H
