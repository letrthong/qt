#include "screen01Handler.h"
#include <QDebug>


screen01Handler::screen01Handler(QQmlApplicationEngine* pEngine)
    : SceneBase (pEngine){
}

void  screen01Handler::onClick(const std::string& from){
    qInfo() << "screen01Handler.cpp::onClick" << from.c_str();

    static bool flag = true;
    if(flag== true){
       setVisibleButton("button02", true) ;
       flag = false;
    }else {
       setVisibleButton("button02", false);
       flag = true;
    }
}

void screen01Handler::onChanged(int id){
     qInfo() << "screen01Handler.cpp::onChanged id=" << id;
}
