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
#include <vector>
#include <QSqlDatabase>

#include "DbIntegerIntervalOption.h"
#include "DbIntegerOption.h"
#include "DbStringOption.h"
#include "DbBooleanOption.h"
#include "DefBshBb.h"

class BshDb
{
public:
    explicit BshDb(const std::string dbName);
    ~BshDb();

    int initDb();
    int intDefaulValues();
    int createTables();

    int setProgramTable(programId id, const std::string& modeName);
    bool getProgramTable(programId id, std::string& modeName);
    int setProgramTable(const struct Program&  program);
    int getProgramTable( std::vector<struct Program>& vProgram );
    bool deleteProgramTable(programId id);
    int getSizeOfProgramTable() const ;

    int setSettingElementTable(programId id, const DbIntegerIntervalOption& settingElemment);
    int getSettingElementTable(programId id, std::vector<DbIntegerIntervalOption>& vSettingElement);
    int getSizeOfSettingElementTable() const ;

    int setSettingElementTable(programId id, const DbIntegerOption& settingElemment);
    int getSettingElementTable(programId id, std::vector<DbIntegerOption>& vSettingElement);

    int setSettingElementTable(programId id, const DbStringOption& settingElemment);
    int getSettingElementTable(programId id, std::vector<DbStringOption>& vSettingElement);

    int setSettingElementTable(programId id, const DbBooleanOption& settingElemment);
    int getSettingElementTable(programId id, std::vector<DbBooleanOption>& vSettingElement);
private:
    bool hasProgramTable(programId id);
    bool hasIntegerIntervalOption(programId id, const std::string& name);
    bool hasIntegerOption(programId id, const std::string& name);
    bool hasStringOption(programId id, const std::string& name);
    bool hasBoolOption(programId id, const std::string& name);

    QSqlDatabase _sqlDatabase;
    std::string _dbName;
};

#endif // BSH_DB_H
