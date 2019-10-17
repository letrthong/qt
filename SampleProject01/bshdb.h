/*=======================================================
 * FileName: bshdb.h
 *
 * qmake
 *          QT += testlib
 *
 * Using cmd as below:
 *          select * from settingElement
 *          select * from program
 *
*=======================================================*/

#ifndef BSH_DB_H
#define BSH_DB_H
#include <string>
#include <QSqlDatabase>
#include "defbshdb.h"
#include <vector>


class BshDb
{
public:
    explicit BshDb(const std::string dbName);
    ~BshDb();

    int initDb();
    int createTables();

    int setProgramTable(programId id, const std::string& modeName);
    int setProgramTable(const struct Program&  program);
    bool getProgramTable(programId id, std::string& modeName);
    bool deleteProgramTable(programId id);
    int getSizeOfProgramTable() const ;

    int setSettingElementTable(programId id, const struct SettingElement& settingElemment);
    int getSettingElementTable(programId id, std::vector<struct SettingElement>& vSettingElement);
    int getSizeOfSettingElementTable() const ;

private:
    bool hasProgramTable(programId id);
    bool hasSettingElementTable(programId id, const std::string& name);

    QSqlDatabase _sqlDatabase;
    std::string _dbName;
};

#endif // BSH_DB_H
