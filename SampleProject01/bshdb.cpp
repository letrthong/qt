#include "bshdb.h"
#include <QDebug>


#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include <QSqlError>
#include <string>
#include <QFileInfo>
#include <QSqlRecord>

BshDb::BshDb(const std::string dbName):_dbName(dbName){
}

int BshDb::initDb(){
    int ret = 0;
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)){
        _sqlDatabase = QSqlDatabase::addDatabase(DRIVER);
        _sqlDatabase.setDatabaseName( _dbName.c_str());
        if(!_sqlDatabase.open()){
             qWarning() << "initDb:: - ERROR: " << _sqlDatabase.lastError().text();
             ret  = 1;
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


int BshDb::setProgramTable(enum PROGRAM_IDS programId, const std::string& modeName){
    QSqlQuery query;
    int ret = 0;
    bool hasId = hasProgramTable(programId);
    char commandLine[256] ;
    if(false == hasId){
         sprintf(commandLine, PROGRAM_INSERT_MODE_NAME,programId,modeName.c_str() );
    }else {
         sprintf(commandLine, PROGRAM_UPDATE_MODE_NAME,modeName.c_str(),programId );
    }

    qInfo()<< "setProgramTable::commandLine=[" <<commandLine <<"]";
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



    qInfo()<< "setProgramTable::commandLine=[" << commandLine<<"]";;
    if(!query.exec(commandLine)){
        qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
        ret=  1;
    }

    return ret;
}

bool BshDb::getProgramTable(enum PROGRAM_IDS  programId, std::string& modeName){
    QSqlQuery query;
    bool ret = false;
    std::string commandLine = "SELECT modeName FROM Program WHERE programId = " + QString::number(programId).toStdString();
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

bool BshDb::DeleteProgramTable(enum PROGRAM_IDS programId){
    QSqlQuery query;
    bool ret = false;
    char commandLine[256] ;
    sprintf(commandLine, PROGRAM_DELETE_ID,programId);
    qInfo()<< "DeleteProgramTable::commandLine=[" << commandLine<<"]";;
    query.prepare(commandLine);
    if(!query.exec()){
      qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
    }else{
        ret = true;
    }
    return ret;
}

bool BshDb::hasProgramTable(enum PROGRAM_IDS programId){
    bool ret = false;
    QSqlQuery query;
    char commandLine[256] ;
    sprintf(commandLine, PROGRAM_FIND_ID,programId);
    qInfo()<< "hasProgramTable::commandLine=[" << commandLine<<"]";;

    query.prepare(commandLine);
    if(!query.exec()){
        qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
    }else{
        int idModeNamee = query.record().indexOf("modeName");
        if(query.first()){
          qWarning() <<"hasProgramTable modeName="<< query.value(idModeNamee).toString();
          ret = true;
        }
    }
    return ret;
}

int BshDb::selectProgramTable(){
    QSqlQuery query;
    //query.prepare("SELECT name FROM Program WHERE id = 1");
    query.prepare("SELECT * FROM Program");
    if(!query.exec()){
        qWarning() << "MainWindow::OnSearchClicked - ERROR: " << query.lastError().text();
    }else{
        /*if(query.first()){
            qWarning()<<query.value(0).toString();
        }*/
        int idName = query.record().indexOf("modeName");
        int i = 0;
        while (query.next())
        {
           QString name = query.value(idName).toString();
           qDebug() <<"selectTable="<< name <<" i="<< i++;
        }
    }
     return 0;
}




 int BshDb::setSettingElementTable(enum PROGRAM_IDS programId, const struct SettingElement&  settingElemment){
     QSqlQuery query;
     int ret = 0;
     bool hasId =  hasSettingElementTable(programId);
     char commandLine[256] ;
     if(false == hasId){
          sprintf(commandLine, SETTING_ELEMENT_INSERT_ALL,programId, \
                                             settingElemment.iconUrl.c_str(), \
                                             settingElemment.name.c_str(),\
                                             settingElemment.value,\
                                             settingElemment.valueType.c_str());
     }else{
         /* sprintf(commandLine, PROGRAM_UPDATE_ALL,program.mModeName.c_str(),\
                                                         program.mProgramName.c_str(),\
                                                         program.mIsFavorite,\
                                                         program.mOrder,\
                                                         program.mProgramId );*/
     }


     qInfo()<< "setSettingElementTable::commandLine=[" << commandLine<<"]";;
     if(!query.exec(commandLine)){
         qWarning() << "setProgramTable::struct Program  error->" << query.lastError().text();
         ret=  1;
     }

     return ret;
 }

 bool BshDb::hasSettingElementTable(enum PROGRAM_IDS programId){
     bool ret = false;
     QSqlQuery query;
     char commandLine[256] ;
     sprintf(commandLine, SETTING_ELEMENT_FIND_ID, programId);
     qInfo()<< "hasSettingElementTable::commandLine=[" << commandLine<<"]";;

     query.prepare(commandLine);
     if(!query.exec()){
         qWarning() << "hasProgramTable- ERROR: " << query.lastError().text();
     }else{
         int idModeNamee = query.record().indexOf("name");
         if(query.first()){
           qWarning() <<"hasSettingElementTable name="<< query.value(idModeNamee).toString();
           ret = true;
         }
     }
     return ret;
 }
