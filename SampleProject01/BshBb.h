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
#include "DefBshBb.h"
#include <vector>

#include "DbIntegerIntervalOption.h"

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

private:
    bool hasProgramTable(programId id);
    bool hasSettingElementTable(programId id, const std::string& name);

    QSqlDatabase _sqlDatabase;
    std::string _dbName;
};

#endif // BSH_DB_H
