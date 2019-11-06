#include "MainController.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDomDocument>
#include <QDebug>
#include  <iostream>
using namespace std;

#include "SceneBase.h"
#include "screen01Handler.h"
#include "screen02Handler.h"
#include "screen03Handler.h"
#include "Infostore.h"
#include <QDateTime>
#include <QQmlContext>

QQueue<QString>  MainController::_qMessage;

MainController::MainController(InfoStore *pInfoStor ){
    _pQuickView = new QQuickView;

    //https://doc.qt.io/qt-5/qtqml-cppintegration-contextproperties.html
    _pQuickView->rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());

    _pInfoStore = pInfoStor;

    _pCurrentScreen = nullptr;

    _pTimer =  new QTimer(this);
    connect(_pTimer, SIGNAL(timeout()), this, SLOT(onTimeoutSlot()));
    _pTimer->start(100);
    screenIndex = 1;

    parseStateChart();
}

MainController::~MainController(){
    _pInfoStore = nullptr;

    _pTimer->destroyed();
    delete _pTimer;
    _pTimer = nullptr;
}

void MainController::onTimeoutSlot(){
    _pTimer->start(100);
    if( screenIndex> 0){
        screenIndex  = 0;
        loadScreen();
    }
}

void MainController::eventClickCppSlot(int sendTo, const QString &msg){
    screenIndex = screenIndex+ 1;
    qInfo() << "MainController::eventClickCppSlot screenIndex="  <<  screenIndex++;
    qInfo() << "MainController::eventClickCppSlot screenIndex="  << sendTo;
    qInfo() << "MainController::eventClickCppSlot msg="  << msg;
    _qMessage.enqueue(msg);
}

void MainController::onControllerSlot(QVariant id){
    qInfo() << "\n MainController::onControllerSlot"  ;
    loadScreen();
}

void MainController::loadScreen(){
    if(_pCurrentScreen != nullptr){
        delete  _pCurrentScreen;
        _pCurrentScreen = nullptr;
    }

    if(! _qMessage.isEmpty()){
        QString msg = _qMessage.dequeue();
         qInfo() << "MainController::onControllerSlot msg="  << msg;
         //http://erickveil.github.io/2016/04/06/How-To-Manipulate-JSON-With-C++-and-Qt.html
           QJsonDocument jsonResponse = QJsonDocument::fromJson(msg.toUtf8());

          QJsonObject json_obj=jsonResponse.object();
          QVariantMap json_map = json_obj.toVariantMap();
         qDebug()<<"loadScreen name="<< json_map["name"].toString();

    }

   static int indexScreen = 0;

   if(0 == indexScreen){
       _pCurrentScreen = new screen01Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen01.qml");
   }else  if(1== indexScreen){
       _pCurrentScreen = new screen02Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen02.qml");
   }else if( 2== indexScreen) {
       _pCurrentScreen = new screen03Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen03.qml");
    }

   indexScreen++;
   if(indexScreen>  2){
       indexScreen = 0;
   }
}

int MainController::parseStateChart(){
    //https://www.lucidar.me/en/dev-c-cpp/reading-xml-files-with-qt/
     qInfo() << "MainController::parseStateChart";

      QDomDocument xmlBOM;
      QFile f("./SM/myState.scxml");
      if (!f.open(QIODevice::ReadOnly ))
      {
          // Error while loading file
          std::cerr << "Error while loading file" << std::endl;
          return 1;
      }
      // Set data into the QDomDocument before processing
      xmlBOM.setContent(&f);
      f.close();

      QDomElement root=xmlBOM.documentElement();
      // Get root names and attributes
      QString Type=root.tagName();
      QString name=root.attribute("name","unknow");
      QString initial=root.attribute("initial","unknow");
      //int Year=root.attribute("YEAR","1900").toInt();

      // Display root data
      std::cout << "Type  = " << Type.toStdString().c_str() << std::endl;
      std::cout << "name = " << name.toStdString().c_str() << std::endl;
      std::cout <<"initial = " << initial.toStdString().c_str() << std::endl;
      std::cout << std::endl;

      QDomElement Component=root.firstChild().toElement();

      // Loop while there is a child
      while(!Component.isNull()){
          // Check if the child tag name is COMPONENT
          if (Component.tagName()=="state"){
              // Read and display the component ID
              QString ID=Component.attribute("id","unknow id");

              // Get the first child of the component
              QDomElement Child=Component.firstChild().toElement();

              // Display component data
              std::cout << "Component " << ID.toStdString().c_str() << std::endl;
              QString event;
              QString target;
              QString cond;
              // Read each child of the component node
              while (!Child.isNull()) {
                  // Read Name and value
                  if (Child.tagName()=="transition") {
                      event=Child.attribute("event","unknow");
                      target=Child.attribute("target","unknow");
                       cond=Child.attribute("cond","unknow");

                       std::cout << "   event  = [" << event.toStdString().c_str() <<"]"<< std::endl;
                       std::cout << "   target = [" << target.toStdString().c_str() <<"]"<< std::endl;
                       std::cout << "   cond =[" << cond.toStdString().c_str() <<"]"<< std::endl;
                  }
                  if (Child.tagName()=="VALUE") {
                     // Value=Child.firstChild().toText().data().toDouble();
                  }

                  // Next child
                  Child = Child.nextSibling().toElement();
              }
          }

          // Next component
          Component = Component.nextSibling().toElement();
      }
      return 0;
}
