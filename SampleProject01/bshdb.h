#ifndef BSHDB_H
#define BSHDB_H
#include <string>
#include <QSqlDatabase>
#include  "defbshdb.h"



class BshDb
{
public:
    BshDb(const std::string dbName);

    int initDb();
    int createTables();
    int setProgramTable(enum PROGRAM_IDS programId, const std::string& modeName);
    int setProgramTable(const struct Program&  program);
    bool getProgramTable(enum PROGRAM_IDS  programId, std::string& modeName);
    bool DeleteProgramTable(enum PROGRAM_IDS programId);
    bool hasProgramTable(enum PROGRAM_IDS programId);
    int selectProgramTable();
    int setSettingElementTable(enum PROGRAM_IDS programId, const struct SettingElement&  settingElemment);
    bool hasSettingElementTable(enum PROGRAM_IDS programId);
private:
    QSqlDatabase _sqlDatabase;
    std::string _dbName;
};

#endif // BSHDB_H
