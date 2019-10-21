#include "BshBb.h"
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

   intDefaulValues();
    return  ret;
}

int BshDb::intDefaulValues(){

    int size = getSizeOfProgramTable();
    if(size <1 ){
        setProgramTable({ PROGRAM_IDS::PROGRAM_ID_01, "abc", "/path01", "fdsfadfd", 1, 1 });

        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_01, {"name01", "iconUrl01" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_01, {"name02", "iconUrl02" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_01, {"name03", "iconUrl03" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_01, {"name04", "iconUrl04" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_01, {"name05", "iconUrl05" , 1 ,4 ,5, 30} );
    }
}

int BshDb::createTables(){

    //Program
    QSqlQuery queryProgram( PROGRAM_CREATE_TABLE );

    if(!queryProgram.isActive()){
         qWarning() << "createTables - ERROR: " << queryProgram.lastError().text();
    }


    //SettingElement
    QSqlQuery querySettingElement( INTEGER_INTERVAL_OPTION_CREATE_TABLE );
    if(!querySettingElement.isActive()){
         qWarning() << "createTables - ERROR: " << querySettingElement.lastError().text();
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
                                            program.mTileImageUrl.c_str(), \
                                            program.mProgramName.c_str(),\
                                            program.mIsFavorite,\
                                            program.mOrder);
    }else{
         sprintf(commandLine, PROGRAM_UPDATE_ALL,program.mProgramName.c_str(),\
                                                program.mTileImageUrl.c_str(),\
                                                program.mModeName.c_str(),\
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

//programName='%s', tileImageUrl='%s', modeName ='%s', isFavorite

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
    query.prepare( INTEGER_INTERVAL_OPTION_SELECT_ALL);

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

int BshDb::setSettingElementTable(programId id, const DbIntegerIntervalOption&  settingElemment){
     QSqlQuery query;
     int ret = 0;


     bool hasId =  hasSettingElementTable(id,  settingElemment.getName());
     char commandLine[256] = {0};
     if(false == hasId){
           qInfo()<< "BshDb::setSettingElementTable::Insert"  ;
          sprintf(commandLine, INTEGER_INTERVAL_OPTION_INSERT_ALL,\
                                id, \
                                settingElemment.getIconUrl().c_str(), \
                                settingElemment.getName().c_str(),\
                                settingElemment.getIntervalCount(),\
                                settingElemment.getIntervalIndex(),\
                                settingElemment.getStartingValue(),\
                                settingElemment.getIntervalLength());
     }else{
          qInfo()<< "BshDb::setSettingElementTable::update"  ;
          sprintf(commandLine, INTEGER_INTERVAL_OPTION_UPDATE_ALL, \
                                settingElemment.getIconUrl().c_str(), \
                                settingElemment.getIntervalCount(),\
                                settingElemment.getIntervalIndex(),\
                                settingElemment.getStartingValue(),\
                                settingElemment.getIntervalLength(),\
                                id,\
                                settingElemment.getName().c_str() );
           qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
     }

     if(!query.exec(commandLine)){
         qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
         qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
         ret=  1;
     }



     return ret;
 }

int BshDb::getSettingElementTable(programId id, std::vector<DbIntegerIntervalOption>& vSettingElement){
    int ret = 0;
    vSettingElement.clear();
    char commandLine[256] ;
    sprintf(commandLine, INTEGER_INTERVAL_OPTION_FIND_ID, id );
    QSqlQuery query;

     query.prepare(commandLine);

     if(!query.exec()){
         qWarning() << "getSettingElementTable- ERROR: " << query.lastError().text();
         qInfo()<< "getSettingElementTable::commandLine=[" << commandLine<<"]";;
     }else{

         int idName = query.record().indexOf("name");
         int idIconUrl = query.record().indexOf("iconUrl");
        // int idValue = query.record().indexOf("value");
        // int idvalueType = query.record().indexOf("valueType");

         while (query.next()){
             DbIntegerIntervalOption  item;
             item.setName( query.value(idName).toString().toStdString());
             item.setIconUrl(query.value(idIconUrl).toString().toStdString());
            // item.valueType = query.value(idvalueType).toString().toStdString();
            // item.value = query.value(idValue).toInt();

             vSettingElement.push_back(item);
         }
     }
    return ret;
 }


 bool BshDb::hasSettingElementTable(programId id, const std::string& name){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, INTEGER_INTERVAL_OPTION_FIND_ID_NAME, id, name.c_str());

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
