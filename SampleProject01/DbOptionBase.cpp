#include "DbOptionBase.h"

DbOptionBase::DbOptionBase(){
    mIsEnabled = true;
    mIsDeactivated = false;
}


DbOptionBase::DbOptionBase(const std::string& name,  const std::string& iconUrl){
    mName= name;
    mIconURL =iconUrl;
    mIsEnabled = true;
    mIsDeactivated = false;
}
DbOptionBase::~DbOptionBase(){
}


void DbOptionBase::setName(const std::string& name){
    mName = name;
}
std::string DbOptionBase::getName() const{
    return  mName;
}

void DbOptionBase::setIconUrl(const std::string& iconUrl){
    mIconURL = iconUrl;
}

std::string DbOptionBase::getIconUrl() const{
    return mIconURL;
}
