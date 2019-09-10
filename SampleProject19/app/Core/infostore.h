#ifndef INFOSTORE_H
#define INFOSTORE_H

#include  "ISceneBase.h"


class InfoStore
{
public:
    InfoStore(ISceneBase* pSceneBase);

    void setText(const std::string& text);
    std::string getText();

    void sendUpdated(int id);

   static void* run();
   void startThread();
private:
        std::string _text;
        ISceneBase* _pSceneBase;
};

#endif // INFOSTORE_H
