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

    _initScreen = parseStateChart();
}

MainController::~MainController(){
    _pInfoStore = nullptr;

    _pTimer->destroyed();
    delete _pTimer;
    _pTimer = nullptr;
}

void MainController::onTimeoutSlot(){

    mutex.lock();
    _pTimer->start(100);
    if( screenIndex> 0){
        screenIndex  = 0;
        loadScreen();
    }
     mutex.unlock();
}

void MainController::eventClickCppSlot(int sendTo, const QString &msg){
    mutex.lock();
    screenIndex = screenIndex+ 1;
    qInfo() << "MainController::eventClickCppSlot screenIndex="  <<  screenIndex++;
    qInfo() << "MainController::eventClickCppSlot screenIndex="  << sendTo;
    qInfo() << "MainController::eventClickCppSlot msg="  << msg;
    _qMessage.enqueue(msg);
     mutex.unlock();
}

void MainController::onControllerSlot(QVariant id){
    qInfo() << "\n MainController::onControllerSlot"  ;
    //loadScreen();
}

void MainController::loadScreen(){
    /*if(_pCurrentScreen != nullptr){
        delete  _pCurrentScreen;
        _pCurrentScreen = nullptr;
    }*/

    QString listViewId = "";
    QString listItem = "";
    QString  buttonName = "";
    QString  sceneName ="";
   QString  event ="";

   if(! _qMessage.isEmpty()){
        QString msg = _qMessage.dequeue();
         qInfo() << "MainController::onControllerSlot msg="  << msg;
         //http://erickveil.github.io/2016/04/06/How-To-Manipulate-JSON-With-C++-and-Qt.html
           QJsonDocument jsonResponse = QJsonDocument::fromJson(msg.toUtf8());

          QJsonObject json_obj=jsonResponse.object();
          QVariantMap json_map = json_obj.toVariantMap();
          sceneName =   json_map["sceneName"].toString();
           event =   json_map["event"].toString();
          qDebug()<<"loadScreen name="<< sceneName;
         qDebug()<<"loadScreen event=["<< event <<"]";
          listViewId  = json_map["listViewId"].toString();


           if( !listViewId.isEmpty() && (listViewId != "0") ){
                listItem =  json_map["ListItem"].toString();
                 qDebug()<<"loadScreen listItem="<< listItem;
                 qDebug()<<"loadScreen listViewId="<< listViewId;
           }else {
                buttonName =  json_map["buttonName"].toString();
                qDebug()<<"loadScreen buttonName="<< buttonName;
           }
    }



    QString scene = "";

    if(_prexScreen != _curxScreen &&  _curxScreen != sceneName){
        _prexScreen =  _curxScreen;
    }

    if( !sceneName.isEmpty()){
         _curxScreen = sceneName;
    }

    qDebug()<<"loadScreen _prexScreen = ["<< _prexScreen <<"]";
    qDebug()<<"loadScreen _curxScreen = ["<< _curxScreen <<"]";

    if( event.contains("onButton") ){
        scene = nextSceenbutton(sceneName, buttonName);
    }else if(  event.contains("onList") ){
        scene = nextSceenItem(sceneName, listItem.toInt());
    }else if(  event.contains("onBack") ){
        scene = nextSceenBack(sceneName);
    }



    qDebug()<<"loadScreen target = ["<< scene <<"]";

    if (scene.contains("screen01")){
       _pCurrentScreen = new screen01Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen01.qml");
    }else  if(scene.contains("screen02") ){
       _pCurrentScreen = new screen02Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen02.qml");
    }else if( scene.contains("screen03") ) {
       _pCurrentScreen = new screen03Handler(_pQuickView, _pInfoStore);
       _pCurrentScreen->createScene("./qrc/Scenes/screen03.qml");
    } else if( scene.contains("screen04")) {
          _pCurrentScreen = new SceneBase(_pQuickView);
          _pCurrentScreen->createScene("./qrc/Scenes/screen04.qml");
    } if( scene.contains("screen05")) {
       _pCurrentScreen = new SceneBase(_pQuickView);
       _pCurrentScreen->createScene("./qrc/Scenes/screen05.qml");
    }else
    {
        static bool flag = false;
        if(flag == false){
            flag = true;
            _pCurrentScreen = new screen01Handler(_pQuickView, _pInfoStore);
             _pCurrentScreen->createScene("./qrc/Scenes/screen01.qml");
        }

    }


}

QString MainController::parseStateChart(){
    //https://www.lucidar.me/en/dev-c-cpp/reading-xml-files-with-qt/
     qInfo() << "MainController::parseStateChart";

      //QDomDocument xmlBOM;
      QFile f("./SM/myState.scxml");
      if (!f.open(QIODevice::ReadOnly ))
      {
          // Error while loading file
          std::cerr << "Error while loading file" << std::endl;
          return "";
      }
      // Set data into the QDomDocument before processing
      xmlBOM.setContent(&f);
      f.close();

      _DomElement=xmlBOM.documentElement();
      // Get root names and attributes
      QString Type=_DomElement.tagName();
      QString name=_DomElement.attribute("name","unknow");
      QString initial=_DomElement.attribute("initial","unknow");

      // Display root data
      std::cout << "Type  = " << Type.toStdString().c_str() << std::endl;
      std::cout << "name = " << name.toStdString().c_str() << std::endl;
      std::cout <<"initial = " << initial.toStdString().c_str() << std::endl;
      std::cout << std::endl;

      QDomElement  domElement = _DomElement.firstChild().toElement();

      // Loop while there is a child
      while(!domElement.isNull()){
          // Check if the child tag name is COMPONENT
          if (domElement.tagName()=="state"){
              // Read and display the component ID
              QString ID=domElement.attribute("id","unknow id");

              // Get the first child of the component
              QDomElement Child=domElement.firstChild().toElement();
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


                  // Next child
                  Child = Child.nextSibling().toElement();
              }
          }

          // Next component
          domElement = domElement.nextSibling().toElement();
      }
      return  initial;
}

QString MainController::nextSceenbutton( const QString &currentSceen, const QString &  buttonName){
    QString target ="";
    std::cout << "nextSceenbutton currentSceen=" << currentSceen.toStdString().c_str() << std::endl;
    std::cout << "nextSceenbutton buttonName=" << buttonName.toStdString().c_str() << std::endl;
    QDomElement  domElement = _DomElement.firstChild().toElement();
     while(!domElement.isNull()){

         if (domElement.tagName()=="state"){
             QString ID=domElement.attribute("id","unknow id");

              std::cout << "nextSceenbutton id =" << ID.toStdString().c_str() << std::endl;
                std::cout << "nextSceenbutton currentSceen =" << currentSceen.toStdString().c_str() << std::endl;
             if(currentSceen.toStdString() == ID.toStdString() ){
                 QDomElement Child=domElement.firstChild().toElement();
                 QString event;
                 QString cond;
                 // Read each child of the component node
                 while (!Child.isNull()) {

                     if (Child.tagName()=="transition") {

                         event=Child.attribute("event","unknow");
                         target=Child.attribute("target","unknow");
                          cond=Child.attribute("cond","unknow");

                          if(event == "onClickButton"){
                              std::cout << "   event  = [" << event.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   target = [" << target.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   cond =[" << cond.toStdString().c_str() <<"]"<< std::endl;
                              if(cond.toStdString().find(buttonName.toStdString()) != string::npos){
                                  return target;
                              }
                          }
                     }
                     Child = Child.nextSibling().toElement();

                 }
                 break;
             }
         }
         domElement = domElement.nextSibling().toElement();
    }
    return "";
}

QString MainController::nextSceenItem( const QString &currentSceen,  int item){
    QString target ="";
    std::cout << "nextSceenItem currentSceen=" << currentSceen.toStdString().c_str() << std::endl;
    std::cout << "nextSceenItem Listitem=[" << item <<"]"<< std::endl;
    QDomElement  domElement = _DomElement.firstChild().toElement();
     while(!domElement.isNull()){

         if (domElement.tagName()=="state"){
             QString ID=domElement.attribute("id","unknow id");

              std::cout << "nextSceenbutton id =" << ID.toStdString().c_str() << std::endl;
                std::cout << "nextSceenbutton currentSceen =" << currentSceen.toStdString().c_str() << std::endl;
             if(currentSceen.toStdString() == ID.toStdString() ){
                 QDomElement Child=domElement.firstChild().toElement();
                 // Display component data
                 std::cout << "Component " << ID.toStdString().c_str() << std::endl;
                 QString event;

                 QString cond;
                 // Read each child of the component node
                 while (!Child.isNull()) {

                     if (Child.tagName()=="transition") {

                         event=Child.attribute("event","unknow");
                         target=Child.attribute("target","unknow");
                          cond=Child.attribute("cond","unknow");

                          if(event == "onClickIterm"){
                              std::cout << "   event  = [" << event.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   target = [" << target.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   cond =[" << cond.toStdString().c_str() <<"]"<< std::endl;
                                   QString stringValue2   =  QString::number(item) ;
                               if(cond.contains( stringValue2  )) {
                                       return target;
                             }
                          }
                      }

                     Child = Child.nextSibling().toElement();
                 }
                 break;
             }
         }
         domElement = domElement.nextSibling().toElement();
    }
    return "";
}


QString MainController::nextSceenBack( const QString &currentSceen ){
    QString target ="";
    std::cout << "nextSceenBack currentSceen=" << currentSceen.toStdString().c_str() << std::endl;

    std::string temp  = _prexScreen.toStdString();

    std::string txt = "";

    for (int i = 0; i < temp.length(); i++){
        if(isalpha(temp[i]) || isdigit(temp[i]) ){
            txt = txt + temp[i] ;
        }
    }

    QDomElement  domElement = _DomElement.firstChild().toElement();
     while(!domElement.isNull()){

         if (domElement.tagName()=="state"){
             QString ID=domElement.attribute("id","unknow id");

              std::cout << "nextSceenBack id =" << ID.toStdString().c_str() << std::endl;
              std::cout << "nextSceenBack currentSceen =" << currentSceen.toStdString().c_str() << std::endl;
             if(currentSceen.toStdString() == ID.toStdString() ){
                 QDomElement Child=domElement.firstChild().toElement();

                 QString event;

                 QString cond;
                 // Read each child of the component node
                 while (!Child.isNull()) {

                     if (Child.tagName()=="transition") {

                         event=Child.attribute("event","unknow");
                         target=Child.attribute("target","unknow");
                          cond=Child.attribute("cond","unknow");

                          if(event == "goBack"){
                              std::cout << "   event  = [" << event.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   target = [" << target.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   cond =[" << cond.toStdString().c_str() <<"]"<< std::endl;
                              std::cout << "   txt  = [" <<  txt  <<"]"<< std::endl;
                              if(cond == "unknow"){
                                  return  target;
                              }else{
                                  if(cond.contains( QString::fromStdString(txt) )){
                                      return  target;
                                  }
                              }
                          }
                      }

                     // Next child
                     Child = Child.nextSibling().toElement();
                 }
                 break;
             }
         }
         domElement = domElement.nextSibling().toElement();
    }
    return "";
}
