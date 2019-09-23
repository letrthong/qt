#include "EditTextBase.h"
#include<QDebug>

EditTextBase::EditTextBase(QObject *parent) :
    QObject(parent){
    
}

QString EditTextBase::getEditText(){
     qInfo() << "getEditText user name="<<  m_userName ; ;
    return m_userName;
}

void EditTextBase::setEditText(const QString& text){
    if (text == m_userName){
        return;
    }

    m_userName = text;
   

    if( text == "Thong"){
        m_userName = "Hi !!!";
    }
    
    emit TextEditChanged();
    qInfo() << "setEditText user name="<< m_userName ;
}

 
