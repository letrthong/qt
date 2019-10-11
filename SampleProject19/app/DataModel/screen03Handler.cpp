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
     std::map<int, struct itemOfList> mapList = _pInfoStore->getItemOfList();

     if(mapList.empty()){
         qInfo() << "screen03Handler::getListDataProvider is empty";
     }else{
         qInfo() << "screen03Handler::getListDataProvider size=" << mapList.size();
         for (std::map<int, struct itemOfList>::iterator it=mapList.begin(); it!=mapList.end(); ++it){
            qInfo() << "screen03Handler::getListDataProvider " << it->second.value.c_str() <<" " << it->second.text.c_str();
            dataList.append(new ItemCheckBoxText(it->second.value.c_str(), it->second.text.c_str(),  it->second.type.c_str(),  it->second.icon.c_str()  ));
         }
     }

    QVariant variant = QVariant::fromValue(dataList);
    return variant;
 }

 void screen03Handler::onListItemClick(int index, std::string status){
     qInfo() << "screen03Handler::onListItemClick status="<< status.c_str();
     _pInfoStore->updateItemOfList(index, status);
 }
