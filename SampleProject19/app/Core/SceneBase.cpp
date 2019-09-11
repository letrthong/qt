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


SceneBase::SceneBase(QQmlApplicationEngine* pEngine){
    _pEngine = pEngine;
    _pSignalManager = new SignalManager(this);
}

void  SceneBase::createScene(const QString & screenName){
    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0,  "BackEnd");
    _pEngine->load(QUrl::fromLocalFile( screenName));

    QObject *topLevel = _pEngine->rootObjects().at(0);

    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    QList<QObject *>  qlist=  _pEngine->rootObjects();
    foreach(QObject* n, qlist) {
        qDebug() << n->objectName();
        qInfo() << "qlist" ;

        QObjectList objectList =  n->children();
        for (QObject *object : objectList){
            qInfo() << "\t" << object;
        }
    }

     //QML to C++
     // SignalManager signalManager;
     QObject::connect(window, SIGNAL(qmlSignalButton(int, QString)),  _pSignalManager,SLOT(onclickCppSlot(int,QString)));


      //C++ to QML
     QObject::connect( _pSignalManager, SIGNAL(setTextFieldCpp(QVariant)),window, SLOT(setTextField(QVariant)));

     foreach(QObject* n, qlist) {
         QObjectList objectList =  n->children();
         for (QObject *object : objectList){
            QString  QclassName = object->metaObject()->className();
            std::string className = QclassName.toStdString();

            qInfo() << QclassName;
            if(className.find("PushButton") != std::string::npos){
                qInfo() << object->property("buttonName");
                //QObject::connect(_pSignalManager, SIGNAL(setProperrtyCpp(QVariant)),object, SLOT(setVisible(QVariant)));
                  _vecButton.push_back(object);
            }
         }
     }
}

void SceneBase::onClickListener(const std::string& from){
     qInfo() << "onClickListener" << from.c_str();
     this->onClick(from);
}

void SceneBase::onChangedListener(int id) {
    qInfo() << "onChangedListener" << id;
    this->onChanged(id);
}

void  SceneBase::onClick(const std::string& from){
}

void SceneBase::onChanged(int id){
}

void  SceneBase::viewScene(const QString & screenName){
}

void  SceneBase::hideScene(const QString & screenName){
}

void  SceneBase::destroyScene(const QString & screenName){
}

void SceneBase::onInfoStoreSlot(QVariant id)
{
     qInfo() << "onInfoStoreSlot" << id;
     onChangedListener(1);
}

void SceneBase::setVisibleButton(const std::string& buttonName, bool visible){
    for (auto i = _vecButton.begin(); i != _vecButton.end(); ++i){
        std::string name =(*i)->property("buttonName").toString().toStdString();
          qInfo() << "setVisibleButton name=" << name.c_str();
        if(buttonName == name ) {
            (*i)->setProperty("visible", visible);
             qInfo() << "setVisibleButton done visiable="<< visible;
            break;
        }
    }

}
