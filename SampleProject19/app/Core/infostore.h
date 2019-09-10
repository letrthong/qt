#ifndef INFOSTORE_H
#define INFOSTORE_H

#include  "ISceneBase.h"
#include  <QThread>


class InfoStore :public  QThread

{
public:
    InfoStore(ISceneBase* pSceneBase);
    ~InfoStore();

    void setText(const std::string& text);
    std::string getText();

    void sendUpdated(int id);


   void startThread();
private:
    void run() override;

private:
        std::string _text;
        ISceneBase* _pSceneBase;
        bool _isRunning;
};

#endif // INFOSTORE_H
