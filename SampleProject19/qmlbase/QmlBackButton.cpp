#include "QmlBackButton.h"
#include<QDebug>

QmlBackButton::QmlBackButton(QObject *parent) :
    QObject(parent)
{
    
}

QString QmlBackButton::userName()
{
     qInfo() << "userName="<<  m_userName ; ;
    return m_userName;
}

void QmlBackButton::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
   

    if( userName == "Thong"){
        m_userName = "Hi !!!";
    }
    
    emit userNameChanged();
    qInfo() << "setUserName="<< m_userName ;
}

 
