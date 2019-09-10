#include "BackEnd.h"
#include<QDebug>

BackEnd::BackEnd(QObject *parent) :
    QObject(parent){
    
}

QString BackEnd::getUserName(){
     qInfo() << "getUserName user name="<<  m_userName ; ;
    return m_userName;
}

void BackEnd::setUserName(const QString &userName){
    if (userName == m_userName){
        return;
    }

    m_userName = userName;
   

    if( userName == "Thong"){
        m_userName = "Hi !!!";
    }
    
    emit userNameChanged();
    qInfo() << "setUserName user name="<< m_userName ;
}

 
