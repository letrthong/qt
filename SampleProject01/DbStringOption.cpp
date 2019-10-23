#include "DbStringOption.h"
#include <QString>
#include <QRegExp>
#include <QStringList>

DbStringOption::DbStringOption(){
    mCurrentIndex = 0;
    mData ="";
}

DbStringOption::DbStringOption(const std::string& name,  const std::string& iconUrl, int index, const std::vector<std::string>& arrValues){
 mName = name;
 mIconURL = iconUrl;
 mCurrentIndex = index;

 setArrValues(arrValues);
}

void DbStringOption::setCurrentIndex(int index){
   mCurrentIndex = index;
}

int DbStringOption::getCurrentIndex() const{
    return mCurrentIndex;
}

void DbStringOption::setArrValues( const std::vector<std::string>& arrValues){
    mArrValues = arrValues;

    mData.clear();
    for(std::string n : arrValues) {
         mData =  mData + n + "/" ;
    }
}

std::vector<std::string>  DbStringOption::getArrValues() const{
    return  mArrValues;
}

std::string DbStringOption::getArrValuesToString() const{
    return  mData;
}

void DbStringOption::setArrayValue(const std::string& data){
    mData = data;
    QStringList list =  QString::fromStdString(mData).split('/');
    mArrValues.clear();
    for (int i = 0; i < list.size(); ++i){
        if(!list.at(i).toStdString().empty()){
             mArrValues.push_back( list.at(i).toStdString());
        }
    }

}
