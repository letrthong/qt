#ifndef INFOSTORE_H
#define INFOSTORE_H

#include  "SceneBase.h"
#include  <QThread>


class InfoStore   :public  QThread
{
    Q_OBJECT
public:
    InfoStore(SceneBase* pSceneBase);
    ~InfoStore();

    void setText(const std::string& text);
    std::string getText();

    void sendUpdated(int id);


   void startThread();
private:
    void run() override;

private:
        std::string _text;
        SceneBase* _pSceneBase;
        bool _isRunning;


signals:
      void sendInfoStoreSignal(QVariant id);
};

#endif // INFOSTORE_H
