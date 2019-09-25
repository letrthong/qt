#include "screen03Handler.h"
#include <QDebug>
#include "ItemCheckBoxText.h"

screen03Handler::screen03Handler(QQuickView * pQuickView,InfoStore *pInfoStore )
    :SceneBase (pQuickView){
    _pInfoStore =pInfoStore;
}

void  screen03Handler::onToggleButtonClick(const std::string& from){
    qInfo() << "screen02Handler.cpp::onButtonClick" << from.c_str();

    testApi();
}

void screen03Handler::onPropertyChange(int id){
     qInfo() << "screen02Handler.cpp::onPropertyChange id=" << id;
    testApi();
}

void screen03Handler::testApi(){
     qInfo() << "screen02Handler.cpp::testApi" ;
    static bool flag = true;
    if(flag == true){
       setPushButtonVisible("button02", true) ;
       flag = false;
    }else {
       setPushButtonVisible("button02", false);
       flag = true;
    }
}


unsigned int screen03Handler::getListId(){
 return  2;
}


 QVariant screen03Handler::getListDataProvider(){
    QList<QObject*> dataList;
    dataList.append(new ItemCheckBoxText(true, "red"));
    dataList.append(new ItemCheckBoxText( false, "green"));
    dataList.append(new ItemCheckBoxText( false, "green"));
    dataList.append(new ItemCheckBoxText( false, "green"));
    dataList.append(new ItemCheckBoxText( false, "3"));
    dataList.append(new ItemCheckBoxText( true, "5"));
    dataList.append(new ItemCheckBoxText( false, "7"));
    dataList.append(new ItemCheckBoxText( false, "9"));

    QVariant variant = QVariant::fromValue(dataList);
    return variant;
 }
