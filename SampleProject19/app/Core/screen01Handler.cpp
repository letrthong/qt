#include "screen01Handler.h"
#include <QDebug>


screen01Handler::screen01Handler(QQmlApplicationEngine* pEngine)
    : SceneBase (pEngine){

}


void  screen01Handler::onClick(const std::string& from){
    qInfo() << "screen01Handler::onClick" << from.c_str();
}
