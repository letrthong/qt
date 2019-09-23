#include "screen02Handler.h"
#include <QDebug>


screen02Handler::screen02Handler(QQuickView * pQuickView,InfoStore *pInfoStore )
    :SceneBase (pQuickView){
    _pInfoStore =pInfoStore;
}

void  screen02Handler::onToggleButtonClick(const std::string& from){
    qInfo() << "screen02Handler.cpp::onButtonClick" << from.c_str();

    testApi();
}

void screen02Handler::onPropertyChange(int id){
     qInfo() << "screen02Handler.cpp::onPropertyChange id=" << id;
    testApi();
}


void screen02Handler::testApi(){
     qInfo() << "screen02Handler.cpp::testApi" ;
    static bool flag = true;
    if(flag== true){
       setPushButtonVisible("button02", true) ;
       flag = false;
    }else {
       setPushButtonVisible("button02", false);
       flag = true;
    }
}

 void screen02Handler::initScene(){
    setTextViewText("TextView", "Hello ThongLT !!!");
 }
