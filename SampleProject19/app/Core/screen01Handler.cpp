#include "screen01Handler.h"
#include <QDebug>


screen01Handler::screen01Handler(QQuickView * pQuickView )
    :SceneBase (pQuickView){
}

void  screen01Handler::onClick(const std::string& from){
    qInfo() << "screen01Handler.cpp::onClick" << from.c_str();

    testApi();
}

void screen01Handler::onChanged(int id){
     qInfo() << "screen01Handler.cpp::onChanged id=" << id;
    testApi();
}


void screen01Handler::testApi(){
     qInfo() << "screen01Handler.cpp::testApi" ;
    static bool flag = true;
    if(flag== true){
       setVisibleButton("button02", true) ;
       flag = false;
    }else {
       setVisibleButton("button02", false);
       flag = true;
    }
}