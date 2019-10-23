#include "DbIntegerIntervalOption.h"

DbIntegerIntervalOption::DbIntegerIntervalOption(){
    mIntervalCount = 0;
    mIntervalIndex = 0;
    mStartingValue = 0;
    mIntervalLength = 0;
    mName ="";
    mIconURL = "";
}

DbIntegerIntervalOption::DbIntegerIntervalOption(const std::string& name,  const std::string& iconUrl, int count,int index, int value, int length){
    mIntervalCount = count;
    mIntervalIndex = index;
    mStartingValue = value;
    mIntervalLength = length;
    mName = name;
    mIconURL = iconUrl;
}

void DbIntegerIntervalOption::setIntervalCount(int count){
    mIntervalCount = count;
}

int DbIntegerIntervalOption::DbIntegerIntervalOption::getIntervalCount() const{
    return  mIntervalCount;
}

void DbIntegerIntervalOption::setIntervalIndex(int index){
    mIntervalIndex = index;
}

int DbIntegerIntervalOption::getIntervalIndex()const {
    return mIntervalIndex;
}

void DbIntegerIntervalOption::setStartingValue(int value){
  mStartingValue = value;
}

int DbIntegerIntervalOption::getStartingValue()const {
   return  mStartingValue;
}

int DbIntegerIntervalOption::setIntervalLength(int length){
    mIntervalLength = length;
}

int DbIntegerIntervalOption::getIntervalLength() const {
    return  mIntervalLength;
}
