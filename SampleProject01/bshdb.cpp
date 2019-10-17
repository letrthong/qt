#include "bshdb.h"
#include <QDebug>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <string>
#include <QFileInfo>
#include <QSqlRecord>


BshDb::BshDb(const std::string dbName):_dbName(dbName){
}

BshDb::~BshDb(){
    _sqlDatabase.close();
}

int BshDb::initDb(){
    int ret = 0;
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        _sqlDatabase = QSqlDatabase::addDatabase(DRIVER);
        _sqlDatabase.setDatabaseName( _dbName.c_str());

        if( !_sqlDatabase.isOpen()){
            if(!_sqlDatabase.open()){
                 qWarning() << "initDb:: - ERROR: " << _sqlDatabase.lastError().text();
                 ret  = 1;
            }
        }
    }
    else{
      qWarning() << "initDb:: - ERROR: no driver " << DRIVER << " available";
      ret = 1;
    }

    //Create tables
   createTables();

    return  ret;
}

int BshDb::createTables(){

    //Program
    QSqlQuery queryProgram("CREATE TABLE  IF NOT EXISTS Program (programId INTEGER PRIMARY KEY,\
                                                                         modeName TEXT,\
                                                                         programName TEXT,\
                                                                         isFavorite INTEGER,\
                                                                         isOrder INTEGER );" );

    if(!queryProgram.isActive()){
         qWarning() << "createTables - ERROR: " << queryProgram.lastError().text();
    }


    //SettingElement
    QSqlQuery querySettingElement("CREATE TABLE  IF NOT EXISTS settingElement (id INTEGER PRIMARY KEY,\
                                                                        programId INTEGER,\
                                                                        iconUrl TEXT,\
                                                                        name TEXT,\
                                                                        value INTEGER,\
                                                                        valueType TEXT);" );
    if(!querySettingElement.isActive()){
         qWarning() << "createTables - ERROR: " << querySettingElement.lastError().text();
    }


    //SettingOptionElement
    QSqlQuery querySettingOptionElement("CREATE TABLE  IF NOT EXISTS SettingOptionElement (id INTEGER PRIMARY KEY,\
                                                                        programId INTEGER,\
                                                                        iconUrl TEXT,\
                                                                        name TEXT,\
                                                                        value INTEGER,\
                                                                        template INTEGER,\
                                                                        valueType TEXT);" );
    if(!querySettingOptionElement.isActive()){
         qWarning() << "createTables- ERROR: " << querySettingOptionElement.lastError().text();
    }


    //SettingStainElement
    QSqlQuery querySettingStainElement("CREATE TABLE  IF NOT EXISTS SettingStainElement (id INTEGER PRIMARY KEY,\
                                                                        programId INTEGER,\
                                                                        iconUrl TEXT,\
                                                                        name TEXT,\
                                                                        value INTEGER,\
                                                                        valueType TEXT);" );
    if(!querySettingStainElement.isActive()){
         qWarning() << "createTables - ERROR: " << querySettingStainElement.lastError().text();
    }

    return 0;
}


int BshDb::setProgramTable(programId id, const std::string& modeName){
    QSqlQuery query;
    int ret = 0;
    bool hasId = hasProgramTable(id);
    char commandLine[256] ;
    if(false == hasId){
         sprintf(commandLine, PROGRAM_INSERT_MODE_NAME,id,modeName.c_str() );
    }else {
         sprintf(commandLine, PROGRAM_UPDATE_MODE_NAME,modeName.c_str(),id );
    }

    if(!query.exec(commandLine)){
        qWarning() << "setProgramTable - ERROR01: " << query.lastError().text();
        ret=  1;
    }

    return  ret;
}

int BshDb::setProgramTable(const struct Program&  program){
    QSqlQuery query;
    int ret = 0;
    bool hasId = hasProgramTable(program.mProgramId);
    char commandLine[256] ;
    if(false == hasId){
         sprintf(commandLine, PROGRAM_INSERT_ALL,program.mProgramId, \
                                            program.mModeName.c_str(), \
                                            program.mProgramName.c_str(),\
                                            program.mIsFavorite,\
                                            program.mOrder);
    }else{
         sprintf(commandLine, PROGRAM_UPDATE_ALL,program.mModeName.c_str(),\
                                                        program.mProgramName.c_str(),\
                                                        program.mIsFavorite,\
                                                        program.mOrder,\
                                                        program.mProgramId );
    }

    if(!query.exec(commandLine)){
        qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
        ret=  1;
    }

    return ret;
}

bool BshDb::getProgramTable(programId id, std::string& modeName){
    QSqlQuery query;
    bool ret = false;
    std::string commandLine = "SELECT modeName FROM Program WHERE programId = " + QString::number(id).toStdString();
    query.prepare(commandLine.c_str());
    if(!query.exec()){
        qWarning()<< commandLine.c_str();
        qWarning() << "getProgramTable- ERROR: " << query.lastError().text();
    }else{
        int idModeNamee = query.record().indexOf("modeName");
        if(query.first()){
            QString name = query.value(idModeNamee).toString();
            modeName =  name.toStdString();
            ret = true;
        }
    }
    return ret;
}

int BshDb::getProgramTable( std::vector<struct Program>& vProgram ){
    int ret = 0;
    QSqlQuery query;

    vProgram.clear();
    query.prepare( PROGRAM_SELECT_ALL);


    if(!query.exec()){
        qWarning() << "getSizeOfProgramTable- ERROR: " << query.lastError().text();
    }else{
        int idProgramId = query.record().indexOf("programId");
        int idModeName = query.record().indexOf("modeName");
        int idProgramName = query.record().indexOf("programName");
        int idIsFavorite = query.record().indexOf("isFavorite");
        int idIsOrder = query.record().indexOf("isOrder");
        while (query.next()){
            struct Program  item;
            item.mProgramId =(programId) query.value(idProgramId).toInt();
            item.mModeName = query.value(idModeName).toString().toStdString();
            item.mProgramName = query.value(idProgramName).toString().toStdString();
            item.mIsFavorite = query.value(idIsFavorite).toInt();
            item.mOrder = query.value(idIsOrder).toInt();

            vProgram.push_back(item);
        }
    }

     return ret;
}

bool BshDb::deleteProgramTable(programId id){
    QSqlQuery query;
    bool ret = false;
    char commandLine[256] ;
    sprintf(commandLine, PROGRAM_DELETE_ID,id);

    query.prepare(commandLine);
    if(!query.exec()){
      qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
    }else{
        ret = true;
    }
    return ret;
}

bool BshDb::hasProgramTable(programId id){
    bool ret = false;
    QSqlQuery query;
    char commandLine[256] ;
    sprintf(commandLine, PROGRAM_FIND_ID,id);

    query.prepare(commandLine);
    if(!query.exec()){
        qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
    }else{
        if(query.first()){
          ret = true;
        }
    }
    return ret;
}

int BshDb::getSizeOfProgramTable() const{
    QSqlQuery query;
    query.prepare( PROGRAM_SELECT_ALL);

    int size= 0;
    if(!query.exec()){
        qWarning() << "getSizeOfProgramTable- ERROR: " << query.lastError().text();
    }else{
        while (query.next()){
            size ++;
        }
    }
     return size;
}

int BshDb::getSizeOfSettingElementTable() const{
    QSqlQuery query;
    query.prepare( SETTING_ELEMENT_SELECT_ALL);

    int size= 0;
    if(!query.exec()){
        qWarning() << "getSizeOfProgramTable- ERROR: " << query.lastError().text();
    }else{
        while (query.next()){
            size ++;
        }
    }
     return size;
}

int BshDb::setSettingElementTable(programId id, const struct SettingElement&  settingElemment){
     QSqlQuery query;
     int ret = 0;
     bool hasId =  hasSettingElementTable(id, settingElemment.name);
     char commandLine[256] = {0};
     if(false == hasId){
          sprintf(commandLine, SETTING_ELEMENT_INSERT_ALL,\
                                id, \
                                settingElemment.iconUrl.c_str(), \
                                settingElemment.name.c_str(),\
                                settingElemment.value,\
                                settingElemment.valueType.c_str());
     }else{
          sprintf(commandLine, SETTING_ELEMENT_UPDATE_ALL, \
                                settingElemment.iconUrl.c_str(), \
                                settingElemment.value,\
                                settingElemment.valueType.c_str(),\
                                id,\
                                settingElemment.name.c_str() );
     }

     if(!query.exec(commandLine)){
         qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
         qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
         ret=  1;
     }

     return ret;
 }

int BshDb::getSettingElementTable(programId id, std::vector<struct SettingElement>& vSettingElement){
    int ret = 0;
    vSettingElement.clear();
    char commandLine[256] ;
    sprintf(commandLine, SETTING_ELEMENT_FIND_ID, id );
    QSqlQuery query;

     query.prepare(commandLine);

     if(!query.exec()){
         qWarning() << "getSettingElementTable- ERROR: " << query.lastError().text();
         qInfo()<< "getSettingElementTable::commandLine=[" << commandLine<<"]";;
     }else{

         int idName = query.record().indexOf("name");
         int idIconUrl = query.record().indexOf("iconUrl");
         int idValue = query.record().indexOf("value");
         int idvalueType = query.record().indexOf("valueType");

         while (query.next()){

             struct SettingElement  item;
             item.name = query.value(idName).toString().toStdString();
             item.iconUrl = query.value(idIconUrl).toString().toStdString();
             item.valueType = query.value(idvalueType).toString().toStdString();
             item.value = query.value(idValue).toInt();

             vSettingElement.push_back(item);
         }
     }
    return ret;
 }


 bool BshDb::hasSettingElementTable(programId id, const std::string& name){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, SETTING_ELEMENT_FIND_ID_NAME, id, name.c_str());

     query.prepare(commandLine);
     if(!query.exec()){
         qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
         qInfo()<< "hasSettingElementTable::commandLine=[" << commandLine<<"]";
     }else{
         if(query.first()){
           ret = true;
         }
     }
     return ret;
 }
