#include "DbIntegerOption.h"
#include <QString>
#include <QRegExp>
#include <QStringList>

DbIntegerOption::DbIntegerOption(){
    mCurrentIndex = 0;
    mData ="";
    mArrValues.clear();
}


DbIntegerOption::DbIntegerOption(const std::string& name,  const std::string& iconUrl, int index, const std::vector<int>& arrValues){
 mName = name;
 mIconURL = iconUrl;
 mCurrentIndex = index;

 setArrValues(arrValues);
}

void DbIntegerOption::setCurrentIndex(int index){
   mCurrentIndex = index;
}

int DbIntegerOption::getCurrentIndex() const{
    return mCurrentIndex;
}

void DbIntegerOption::setArrValues( const std::vector<int>& arrValues){
    mArrValues = arrValues;

    mData.clear();
    for(int n : arrValues) {
         mData =  mData + QString::number(n).toStdString() + "/" ;
    }
}

std::vector<int>  DbIntegerOption::getArrValues() const{
    return  mArrValues;
}

std::string DbIntegerOption::getArrValuesToString() const{
    return  mData;
}

void DbIntegerOption::setArrayValue(const std::string& data){
    mData = data;
    QStringList list =  QString::fromStdString(mData).split('/');
    mArrValues.clear();
    for (int i = 0; i < list.size(); ++i){
        if(!list.at(i).toStdString().empty()){
             mArrValues.push_back( list.at(i).toInt());
        }
    }
}
