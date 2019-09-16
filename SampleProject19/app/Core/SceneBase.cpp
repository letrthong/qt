#include "SceneBase.h"
#include <QDebug>
#include "BackEnd.h"
#include "SignalManager.h"
#include <QQmlEngine>
#include <QQuickWindow>

#include <QtQml>

#include <QSurfaceFormat>
#include <QQmlComponent>
#include <QQuickView>
#include <QtGui>
#include <QtQuick>

SceneBase::SceneBase(QQuickView * pQuickView ){
     qInfo() << "SceneBase::constructor" ;
    _pSignalManager = new SignalManager(this);
    _pQuickView  = pQuickView;
    _pQQuickListView = NULL;
}

SceneBase::~SceneBase()
{
    if(_pSignalManager)
    {
        QObject::disconnect(_pMainScreen, SIGNAL(qmlSignalButton(int, QString)),  _pSignalManager,SLOT(onclickCppSlot(int,QString)));
        QObject::disconnect( _pSignalManager, SIGNAL(setTextFieldCpp(QVariant)),_pMainScreen, SLOT(setTextField(QVariant)));

        delete _pSignalManager;
        _pSignalManager = NULL;
    }
}


void  SceneBase::createScene(const QString & screenName){
       qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0,  "BackEnd");

    _pQuickView->setSource(QUrl(screenName));
    _pQuickView->show();

    //QML to C++
    _pMainScreen = _pQuickView->rootObject();


    QObject::connect(_pMainScreen, SIGNAL(qmlSignalButton(int, QString)),  _pSignalManager,SLOT(onclickCppSlot(int,QString)));
    //C++ to QML
    QObject::connect( _pSignalManager, SIGNAL(setTextFieldCpp(QVariant)),_pMainScreen, SLOT(setTextField(QVariant)));


    QQuickItem *item = _pQuickView->rootObject();
    foreach (QQuickItem *child, item->childItems()) {
         qInfo() <<"SceneBase::buttonName="<< child->property("buttonName");
         QString  QclassName = child->metaObject()->className();
          std::string className = QclassName.toStdString();

          qInfo() <<"SceneBase::className="<<QclassName;
          if(className.find("PushButton") != std::string::npos){
              qInfo() <<"SceneBase::PushButton" ;
                _vecButton.push_back(child);
          }
          else if(className.find("QQuickListView") != std::string::npos){
              _pQQuickListView = child;
          }
    }

    if(_pQQuickListView != NULL)
    {
           QVariant* pvalue = _pQQuickListView->property("delegate")  ;
           qInfo()<<pvalue->toString();

    }
}

void SceneBase::onClickListener(const std::string& from){
     qInfo() << "SceneBase::onClickListener" << from.c_str();
     this->onClick(from);
}

void SceneBase::onChangedListener(int id) {
    qInfo() << "SceneBase::onChangedListener" << id;
    this->onChanged(id);
}

void  SceneBase::onClick(const std::string& from){
}

void SceneBase::onChanged(int id){
}



void SceneBase::onInfoStoreSlot(QVariant id)
{
     qInfo() << "SceneBase::onInfoStoreSlot" << id;
     onChangedListener(1);
}

void SceneBase::setVisibleButton(const std::string& buttonName, bool visible){

    qInfo() << "SceneBase::setVisibleButton buttonName="<< buttonName.c_str();
    for (auto i = _vecButton.begin(); i != _vecButton.end(); ++i){
        std::string name =(*i)->property("buttonName").toString().toStdString();
          qInfo() << "SceneBase::setVisibleButton name=" << name.c_str();
        if(buttonName == name ) {
            (*i)->setProperty("visible", visible);
             qInfo() << "SceneBase::setVisibleButton done visiable="<< visible;
            break;
        }
    }

}
