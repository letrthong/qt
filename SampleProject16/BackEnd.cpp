#include "BackEnd.h"
#include<QDebug>

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    
}

QString BackEnd::userName()
{
    return m_userName;
}

void BackEnd::setUserName(const QString &userName)
{
    if (userName == m_userName)
        return;

    m_userName = userName;
   

    if( userName == "Thong")
    {
        m_userName = "Hi !!!";
    }
     emit userNameChanged();
    qInfo() << "userNameChanged="<< m_userName ;
}

 