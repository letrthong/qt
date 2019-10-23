#include "DbBooleanOption.h"
#include <QString>
#include <QRegExp>
#include <QStringList>

DbBooleanOption::DbBooleanOption(){
    mCurrentIndex = 0;
    mData ="";
}

DbBooleanOption::DbBooleanOption(const std::string& name,  const std::string& iconUrl, int index, const std::vector<bool>& arrValues){
    mName = name;
    mIconURL = iconUrl;
    mCurrentIndex = index;
    setArrValues(arrValues);
}

void DbBooleanOption::setCurrentIndex(int index){
   mCurrentIndex = index;
}

int DbBooleanOption::getCurrentIndex() const{
    return mCurrentIndex;
}

void DbBooleanOption::setArrValues( const std::vector<bool>& arrValues){
    mArrValues = arrValues;
    mData.clear();
    for( bool n : arrValues) {
        if(true == n){
            mData =  mData  +"true/" ;
        }else{
            mData =  mData  +"false/" ;
        }
    }
}

std::vector<bool>  DbBooleanOption::getArrValues() const{
    return  mArrValues;
}

std::string DbBooleanOption::getArrValuesToString() const{
    return  mData;
}

void DbBooleanOption::setArrayValue(const std::string& data){
    mData = data;
    QStringList list =  QString::fromStdString(mData).split('/');
    mArrValues.clear();
    for (int i = 0; i < list.size(); ++i){
        std::string value = list.at(i).toStdString();
        if(value == "true"){
            mArrValues.push_back(true);
        }else if( value == "false"){
            mArrValues.push_back(false);
        }
    }
}
