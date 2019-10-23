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
    int ret  = 0;
    int size = getSizeOfProgramTable();
    if(size <1 ){
        setProgramTable({ PROGRAM_IDS::PROGRAM_ID_JEANS, "Jeans", "../res/Image/Washprograms/programTileMyJeansFavoriteBGTile.png", "n.a", 1, 1 });
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_JEANS, {"Tempurature", "../res/icons/temperature.png" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_JEANS, {"Spin Speed", "../res/icons/heat.png" , 1 ,4 ,5, 30} );

        setProgramTable({ PROGRAM_IDS::PROGRAM_ID_COTTON, "Cotton", "../res/Image/Washprograms/programTileCottonBGTile.png", "n.a", 1, 1 });
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_COTTON, {"Tempurature", "../res/icons/temperature.png" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_COTTON, {"Spin Speed", "../res/icons/heat.png" , 1 ,4 ,5, 30} );

        setProgramTable({ PROGRAM_IDS::PROGRAM_ID_EASY_CARE, "Easy Care", "../res/Image/Washprograms/programTileEasyCareBGTile.png", "n.a", 1, 1 });
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, {"Tempurature", "../res/icons/temperature.png" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, {"Spin Speed", "../res/icons/heat.png" , 1 ,4 ,5, 30} );


        setProgramTable({ PROGRAM_IDS::PROGRAM_ID_MY_TIME, "My Time", "../res/Image/Washprograms/programTileDelicatesBGTile.png", "n.a", 1, 1 });
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MY_TIME, {"Tempurature", "../res/icons/temperature.png" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MY_TIME, {"Spin Speed", "../res/icons/heat.png" , 1 ,4 ,5, 30} );

        setProgramTable({ PROGRAM_IDS::PROGRAM_ID_MIX, "Mix", "../res/Image/Washprograms/programTileMixBGTile.png", "n.a", 1, 1 });
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, {"Tempurature", "../res/icons/temperature.png" , 1 ,4 ,5, 30} );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, {"Spin Speed", "../res/icons/heat.png" , 1 ,4 ,5, 30} );

        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, {"integer", "../res/icons/heat.png" , 1 ,  std::vector<int> {1,2,3,4,5} } );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, {"integer", "../res/icons/heat.png" , 1 ,  std::vector<bool> {true, true, false} } );
        setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, {"integer", "../res/icons/heat.png" , 1 ,  std::vector<std::string> {"op1", "op2"} } );
    }

    return ret;
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

    QSqlQuery queryIntergerOptions( INTEGER_OPTION_CREATE_TABLE );
    if(!queryIntergerOptions.isActive()){
         qWarning() << "createTables - ERROR: " << queryIntergerOptions.lastError().text();
    }


    QSqlQuery queryStringOptions( STRING_OPTION_CREATE_TABLE );
    if(!queryStringOptions.isActive()){
         qWarning() << "createTables - ERROR: " << queryIntergerOptions.lastError().text();
    }


    QSqlQuery queryBoolOptions( BOOLEAN_OPTION_CREATE_TABLE );
    if(!queryBoolOptions.isActive()){
         qWarning() << "createTables - ERROR: " << queryIntergerOptions.lastError().text();
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
     bool hasId =  hasIntegerIntervalOption(id,  settingElemment.getName());
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
     }

     //  qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
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
         int idCount = query.record().indexOf("intervalCount");
         int idIndex = query.record().indexOf("intervalIndex");
         int idValue = query.record().indexOf("startingValue");
         int idLength = query.record().indexOf("intervalLength");

         while (query.next()){
             DbIntegerIntervalOption  item;
             item.setName( query.value(idName).toString().toStdString());
             item.setIconUrl(query.value(idIconUrl).toString().toStdString());
             item.setIntervalCount(query.value(idCount).toInt());
             item.setIntervalIndex(query.value(idIndex).toInt());
             item.setStartingValue(query.value(idValue).toInt());
             item.setIntervalLength(query.value(idLength).toInt());
             vSettingElement.push_back(item);
         }
     }
    return ret;
 }


 bool BshDb::hasIntegerIntervalOption(programId id, const std::string& name){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, INTEGER_INTERVAL_OPTION_FIND_ID_NAME, id, name.c_str());

     query.prepare(commandLine);
     if(!query.exec()){
         qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
         qInfo()<< "hasIntegerIntervalOption::commandLine=[" << commandLine<<"]";
     }else{
         if(query.first()){
           ret = true;
         }
     }
     return ret;
 }

 bool BshDb::hasIntegerOption(programId id, const std::string& name){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, INTEGER_OPTION_FIND_ID_NAME, id, name.c_str());

     query.prepare(commandLine);
     if(!query.exec()){
         qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
         qInfo()<< "hasIntegerIntervalOption::commandLine=[" << commandLine<<"]";
     }else{
         if(query.first()){
           ret = true;
         }
     }
     return ret;
 }

 bool BshDb::hasStringOption(programId id, const std::string& name){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, STRING_OPTION_FIND_ID_NAME, id, name.c_str());

     query.prepare(commandLine);
     if(!query.exec()){
         qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
         qInfo()<< "hasIntegerIntervalOption::commandLine=[" << commandLine<<"]";
     }else{
         if(query.first()){
           ret = true;
         }
     }
     return ret;
 }


 bool BshDb::hasBoolOption(programId id, const std::string& name){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, BOOLEAN_OPTION_FIND_ID_NAME, id, name.c_str());

     query.prepare(commandLine);
     if(!query.exec()){
         qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
         qInfo()<< "hasIntegerIntervalOption::commandLine=[" << commandLine<<"]";
     }else{
         if(query.first()){
           ret = true;
         }
     }
     return ret;
 }



 int BshDb::setSettingElementTable(programId id, const DbIntegerOption& settingElemment){
    int ret = 0;
    QSqlQuery query;
    bool hasId =  hasIntegerOption(id,  settingElemment.getName());
    char commandLine[256] = {0};
    if(false == hasId){
         qInfo()<< "BshDb::setSettingElementTable::Insert"  ;
         sprintf(commandLine, INTEGER_OPTION_INSERT_ALL,\
                               id, \
                               settingElemment.getIconUrl().c_str(), \
                               settingElemment.getName().c_str(),\
                               settingElemment.getCurrentIndex(),\
                               settingElemment.getArrValuesToString().c_str());
    }else{
         qInfo()<< "BshDb::setSettingElementTable::update"  ;
         sprintf(commandLine, INTEGER_OPTION_UPDATE_ALL, \
                               settingElemment.getIconUrl().c_str(), \
                                settingElemment.getCurrentIndex(),\
                                settingElemment.getArrValuesToString().c_str(),\
                                id,\
                                settingElemment.getName().c_str() );
        qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
    }

     qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
    if(!query.exec(commandLine)){
        qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
        qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
        ret=  1;
    }

    return ret;
 }

 int BshDb::getSettingElementTable(programId id, std::vector<DbIntegerOption>& vSettingElement){
     int ret = 0;
     vSettingElement.clear();
     char commandLine[256] ;
     sprintf(commandLine, INTEGER_OPTION_FIND_ID, id );
     QSqlQuery query;

      query.prepare(commandLine);

      if(!query.exec()){
          qWarning() << "getSettingElementTable- ERROR: " << query.lastError().text();
          qInfo()<< "getSettingElementTable::commandLine=[" << commandLine<<"]";;
      }else{

          int idName = query.record().indexOf("name");
          int idIconUrl = query.record().indexOf("iconUrl");
          int idIndex = query.record().indexOf("currentIdex");
          int idArayValues= query.record().indexOf("arrayValues");
          while (query.next()){
              DbIntegerOption  item;
              item.setName( query.value(idName).toString().toStdString());
              item.setIconUrl(query.value(idIconUrl).toString().toStdString());
              item.setCurrentIndex(query.value(idIndex).toInt());
              item.setArrayValue(query.value(idArayValues).toString().toStdString());
              vSettingElement.push_back(item);
          }
      }
     return ret;
 }


 int BshDb::setSettingElementTable(programId id, const DbStringOption& settingElemment){
    int ret = 0;
    QSqlQuery query;
    bool hasId =  hasStringOption(id,  settingElemment.getName());
    char commandLine[256] = {0};
    if(false == hasId){
         qInfo()<< "BshDb::setSettingElementTable::Insert"  ;
         sprintf(commandLine, STRING_OPTION_INSERT_ALL,\
                               id, \
                               settingElemment.getIconUrl().c_str(), \
                               settingElemment.getName().c_str(),\
                               settingElemment.getCurrentIndex(),\
                               settingElemment.getArrValuesToString().c_str());
    }else{
         qInfo()<< "BshDb::setSettingElementTable::update"  ;
         sprintf(commandLine, STRING_OPTION_UPDATE_ALL, \
                               settingElemment.getIconUrl().c_str(), \
                                settingElemment.getCurrentIndex(),\
                                settingElemment.getArrValuesToString().c_str(),\
                                id,\
                                settingElemment.getName().c_str() );
        qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
    }

     qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
    if(!query.exec(commandLine)){
        qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
        qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
        ret=  1;
    }

    return ret;
 }

 int BshDb::getSettingElementTable(programId id, std::vector<DbStringOption>& vSettingElement){
     int ret = 0;
     vSettingElement.clear();
     char commandLine[256] ;
     sprintf(commandLine, STRING_OPTION_FIND_ID, id );
     QSqlQuery query;

      query.prepare(commandLine);

      if(!query.exec()){
          qWarning() << "getSettingElementTable- ERROR: " << query.lastError().text();
          qInfo()<< "getSettingElementTable::commandLine=[" << commandLine<<"]";;
      }else{

          int idName = query.record().indexOf("name");
          int idIconUrl = query.record().indexOf("iconUrl");
          int idIndex = query.record().indexOf("currentIdex");
          int idArayValues= query.record().indexOf("arrayValues");
          while (query.next()){
              DbStringOption  item;
              item.setName( query.value(idName).toString().toStdString());
              item.setIconUrl(query.value(idIconUrl).toString().toStdString());
              item.setCurrentIndex(query.value(idIndex).toInt());
              item.setArrayValue(query.value(idArayValues).toString().toStdString());
              vSettingElement.push_back(item);
          }
      }
     return ret;
 }


 int BshDb::setSettingElementTable(programId id, const DbBooleanOption& settingElemment){
     int ret = 0;
     QSqlQuery query;
     bool hasId =  hasBoolOption(id,  settingElemment.getName());
     char commandLine[256] = {0};
     if(false == hasId){
          qInfo()<< "BshDb::setSettingElementTable::Insert"  ;
          sprintf(commandLine, BOOLEAN_OPTION_INSERT_ALL,\
                                id, \
                                settingElemment.getIconUrl().c_str(), \
                                settingElemment.getName().c_str(),\
                                settingElemment.getCurrentIndex(),\
                                settingElemment.getArrValuesToString().c_str());
     }else{
          qInfo()<< "BshDb::setSettingElementTable::update"  ;
          sprintf(commandLine, STRING_OPTION_UPDATE_ALL, \
                                settingElemment.getIconUrl().c_str(), \
                                 settingElemment.getCurrentIndex(),\
                                 settingElemment.getArrValuesToString().c_str(),\
                                 id,\
                                 settingElemment.getName().c_str() );
         qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
     }

      qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
     if(!query.exec(commandLine)){
         qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
         qInfo()<< "BshDb::setSettingElementTable::commandLine=[" << commandLine<<"]";
         ret=  1;
     }

     return ret;
 }
 int BshDb::getSettingElementTable(programId id, std::vector<DbBooleanOption>& vSettingElement){
     int ret = 0;
     vSettingElement.clear();
     char commandLine[256] ;
     sprintf(commandLine, BOOLEAN_OPTION_FIND_ID, id );
     QSqlQuery query;

      query.prepare(commandLine);

      if(!query.exec()){
          qWarning() << "getSettingElementTable- ERROR: " << query.lastError().text();
          qInfo()<< "getSettingElementTable::commandLine=[" << commandLine<<"]";;
      }else{

          int idName = query.record().indexOf("name");
          int idIconUrl = query.record().indexOf("iconUrl");
          int idIndex = query.record().indexOf("currentIdex");
          int idArayValues= query.record().indexOf("arrayValues");
          while (query.next()){
              DbBooleanOption  item;
              item.setName( query.value(idName).toString().toStdString());
              item.setIconUrl(query.value(idIconUrl).toString().toStdString());
              item.setCurrentIndex(query.value(idIndex).toInt());
              item.setArrayValue(query.value(idArayValues).toString().toStdString());
              vSettingElement.push_back(item);
          }
      }
     return ret;
 }
