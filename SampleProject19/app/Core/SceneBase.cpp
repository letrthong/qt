#include "SceneBase.h"
#include <QDebug>
#include "EditTextBase.h"
#include "SignalManager.h"
#include <QQmlEngine>
#include <QQuickWindow>

#include <QtQml>

#include <QSurfaceFormat>
#include <QQmlComponent>
#include <QQuickView>
#include <QtGui>
#include <QtQuick>

#include "DefComposite.h"

SceneBase::SceneBase(QQuickView * pQuickView  ){
     qInfo() << "SceneBase::constructor" ;
    _pSignalManager = new SignalManager(this);
    _pQuickView  = pQuickView;

    _pQQuickListView = nullptr;
    _pQmlContext = nullptr;
}

SceneBase::~SceneBase()
{
    if(_pSignalManager){
        QObject::disconnect(_pMainScreen, SIGNAL(qmlSignalButton(int, QString)),  _pSignalManager,SLOT(onclickCppSlot(int,QString)));
        QObject::disconnect( _pSignalManager, SIGNAL(setTextFieldCpp(QVariant)),_pMainScreen, SLOT(setTextField(QVariant)));

        if(_pSignalManager != nullptr){
            delete _pSignalManager;
            _pSignalManager = nullptr;
        }

        if(_pQmlContext != nullptr){
            _pQmlContext = nullptr;
        }
    }
}


void  SceneBase::createScene(const QString & screenName){
       qmlRegisterType<EditTextBase>("io.qt.examples.backend", 1, 0,  "EditTextBackEnd");

       if(0 != getListId()) {
            _pQmlContext =_pQuickView->rootContext();
            _pQmlContext->setContextProperty("myModel", getListDataProvider());
       }

    _pQuickView->setSource(QUrl(screenName));
     qInfo() <<"SceneBase::createScene setSource="<< screenName;

    //QML to C++
    _pMainScreen = _pQuickView->rootObject();


    QObject::connect(_pMainScreen, SIGNAL(qmlSignalButton(int, QString)),  _pSignalManager,SLOT(onclickCppSlot(int,QString)));
    //C++ to QML
    QObject::connect( _pSignalManager, SIGNAL(setTextFieldCpp(QVariant)),_pMainScreen, SLOT(setTextField(QVariant)));


    QQuickItem *item = _pQuickView->rootObject();
    foreach (QQuickItem *child, item->childItems()) {
         qInfo() <<"SceneBase::childItems="<< child->property("pushButtonName");
         QString  QclassName = child->metaObject()->className();
         std::string className = QclassName.toStdString();

          qInfo() <<"SceneBase::className="<<QclassName;
          if(className.find("PushButton") != std::string::npos){
            _vecPushButton.push_back(child);
          }else if(className.find("ToggleButton") != std::string::npos){
            _vecToggleButton.push_back(child);
          }else if(className.find("ListView") != std::string::npos){
            _pQQuickListView = child;
          }else if(className.find("TextView") != std::string::npos){
             _vecTextView.push_back(child);
          }
    }

      if(_pQQuickListView != nullptr){
          qInfo() <<"SceneBase::ListViewModel="<< _pQQuickListView->property("listModelType");
          qInfo() <<"SceneBase::ListViewModel="<< _pQQuickListView->property("listId");
      }
     _pQuickView->show();

     initScene();
}

void SceneBase::onClickListener(unsigned int type, const std::string& from){

     qInfo() << "SceneBase::onClickListener" << from.c_str();
     switch (type) {
          case TYPE_TOGGLE_BUTTON:{
             this->onToggleButtonClick(from);
             break;
          }
          case TYPE_PUSH_BUTTON:{
             this->onPushButtonClick(from);
             break;
           }
          default:{
             break;
          }
     }

}

void SceneBase::onChangedListener(int id) {
    qInfo() << "SceneBase::onChangedListener" << id;
    this->onPropertyChange(id);
}

void SceneBase::onPushButtonClick(const std::string& from){
}

void SceneBase::onToggleButtonClick(const std::string& from){
}

unsigned int SceneBase::getListId(){
    return  0;
}


void SceneBase::onPropertyChange(int id){
}

QVariant   SceneBase::getListDataProvider(){
   QVariant variant;
   return variant;
}

void SceneBase::initScene(){
}

void SceneBase::onInfoStoreSlot(QVariant id){
     qInfo() << "SceneBase::onInfoStoreSlot" << id;
     onChangedListener(1);
}

void SceneBase::setPushButtonVisible(const std::string& buttonName, bool visible){
    for (auto i = _vecPushButton.begin(); i != _vecPushButton.end(); ++i){
        std::string name =(*i)->property("pushButtonName").toString().toStdString();
        if(buttonName == name ) {
            (*i)->setProperty("visible", visible);
            break;
        }
    }
}

void SceneBase::setTextViewText(const std::string& TextVievName, const std::string& text){
    for (auto i = _vecTextView.begin(); i != _vecTextView.end(); ++i){
        std::string name =(*i)->property("textVievName").toString().toStdString();
        if(TextVievName == name ) {
            (*i)->setProperty("textViewText", text.c_str());
            break;
        }
    }
}

void SceneBase::initToggleButtonValue(const std::string& toggleButtonName, bool isOn){
    for (auto i = _vecToggleButton.begin(); i != _vecToggleButton.end(); ++i){
        std::string name =(*i)->property("toggleButtonName").toString().toStdString();
         qInfo() << "SceneBase::initToggleButtonValue name=" << name.c_str() <<" "<<toggleButtonName.c_str();

        if(toggleButtonName == name ) {
            (*i)->setProperty("isChecked", isOn);
            break;
        }
    }
}

void SceneBase::disableToggleButton(const std::string& toggleButtonName, bool isEnable){

}
