#include "screen01Handler.h"
#include <QDebug>


screen01Handler::screen01Handler(QQuickView * pQuickView,InfoStore *pInfoStore )
    :SceneBase (pQuickView  ){

     _pInfoStore =pInfoStore;
}

void  screen01Handler::onToggleButtonClick(const std::string& from){
    qInfo() << "screen01Handler.cpp::onToggleButtonClick=" << from.c_str();
    if(from.find("button01") != std::string::npos){
        bool preState =   _pInfoStore->getBool();
        _pInfoStore->setBool(preState^true);
    }

    testApi();
}

void screen01Handler::onPropertyChange (int id){
     qInfo() << "screen01Handler.cpp::onPropertyChange id=" << id;
    testApi();
}


void screen01Handler::testApi(){
     qInfo() << "screen01Handler.cpp::testApi" ;
    static bool flag = true;
    if(flag== true){
       setPushButtonVisible("button02", true) ;
       flag = false;
    }else {
       setPushButtonVisible("button02", false);
       flag = true;
    }
}


void screen01Handler::initScene(){
   initToggleButtonValue("button01", _pInfoStore->getBool() );
}
