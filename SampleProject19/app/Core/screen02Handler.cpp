#include "screen02Handler.h"
#include <QDebug>


screen02Handler::screen02Handler(QQuickView * pQuickView )
    :SceneBase (pQuickView){
}

void  screen02Handler::onClick(const std::string& from){
    qInfo() << "screen02Handler.cpp::onClick" << from.c_str();

    testApi();
}

void screen02Handler::onChanged(int id){
     qInfo() << "screen02Handler.cpp::onChanged id=" << id;
    testApi();
}


void screen02Handler::testApi(){
     qInfo() << "screen02Handler.cpp::testApi" ;
    static bool flag = true;
    if(flag== true){
       setVisibleButton("button02", true) ;
       flag = false;
    }else {
       setVisibleButton("button02", false);
       flag = true;
    }
}
