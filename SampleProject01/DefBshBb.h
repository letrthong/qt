#ifndef DEF_BSH_DB_H
#define DEF_BSH_DB_H
#include <string>
#include <vector>

#define PROGRAM_INSERT_ALL          "INSERT INTO Program(programId,programName, tileImageUrl, modeName,isFavorite,isOrder) VALUES( %d, '%s', '%s','%s', %d, %d );"
#define PROGRAM_INSERT_MODE_NAME    "INSERT INTO Program(programId,modeName) VALUES( %d, '%s' );"
#define PROGRAM_UPDATE_ALL          "UPDATE program SET programName='%s', tileImageUrl='%s', modeName ='%s', isFavorite= %d, isFavorite= %d  WHERE programId = %d;"
#define PROGRAM_UPDATE_MODE_NAME    "UPDATE program SET modeName ='%s' WHERE programId = %d;"
#define PROGRAM_DELETE_ID           "DELETE FROM Program WHERE programId = %d;"
#define PROGRAM_FIND_ID             "SELECT modeName FROM Program WHERE programId = %d;"
#define PROGRAM_SELECT_ALL          "SELECT * FROM Program "
#define PROGRAM_CREATE_TABLE        "CREATE TABLE  IF NOT EXISTS Program (programId INTEGER PRIMARY KEY,\
                                                                            programName TEXT,\
                                                                            tileImageUrl TEXT,\
                                                                            modeName TEXT,\
                                                                            isFavorite INTEGER,\
                                                                            isOrder INTEGER );"


#define INTEGER_INTERVAL_OPTION_INSERT_ALL      "INSERT INTO integerIntervalOption(programId,iconUrl,name,intervalCount ,intervalIndex,startingValue, intervalLength )\
                                                 VALUES( %d, '%s','%s', %d, %d, %d, %d );"

#define INTEGER_INTERVAL_OPTION_FIND_ID_NAME    "SELECT * FROM integerIntervalOption WHERE programId = %d AND  name='%s';"
#define INTEGER_INTERVAL_OPTION_FIND_ID         "SELECT * FROM integerIntervalOption WHERE programId = %d;"
#define INTEGER_INTERVAL_OPTION_UPDATE_ALL      "UPDATE integerIntervalOption SET iconUrl ='%s', intervalCount=%d, intervalIndex= %d,\
                                                    startingValue=%d,  intervalLength=%d WHERE programId = %d AND  name='%s';"
#define INTEGER_INTERVAL_OPTION_SELECT_ALL      "SELECT * FROM integerIntervalOption "
#define INTEGER_INTERVAL_OPTION_CREATE_TABLE    "CREATE TABLE  IF NOT EXISTS integerIntervalOption (id INTEGER PRIMARY KEY,\
                                                                                    programId INTEGER,\
                                                                                    iconUrl TEXT,\
                                                                                    name TEXT,\
                                                                                    intervalCount  INTEGER,\
                                                                                    intervalIndex INTEGER,\
                                                                                    startingValue INTEGER, \
                                                                                    intervalLength INTEGER );"



#define INTEGER_OPTION_INSERT_ALL      "INSERT INTO integerOption(programId,iconUrl,name,currentIdex ,arrayValues )\
                                                 VALUES( %d, '%s','%s', %d, '%s');"

#define INTEGER_OPTION_FIND_ID_NAME    "SELECT * FROM integerOption WHERE programId = %d AND  name='%s';"
#define INTEGER_OPTION_FIND_ID         "SELECT * FROM integerOption WHERE programId = %d;"
#define INTEGER_OPTION_UPDATE_ALL      "UPDATE integerOption SET iconUrl ='%s', currentIdex=%d, arrayValues='%s' WHERE programId = %d AND  name='%s';"
#define INTEGER_OPTION_SELECT_ALL      "SELECT * FROM integerOption "
#define INTEGER_OPTION_CREATE_TABLE    "CREATE TABLE  IF NOT EXISTS integerOption (id INTEGER PRIMARY KEY,\
                                                                                    programId INTEGER,\
                                                                                    iconUrl TEXT,\
                                                                                    name TEXT,\
                                                                                    currentIdex  INTEGER,\
                                                                                    arrayValues TEXT);"


#define STRING_OPTION_INSERT_ALL      "INSERT INTO stringOption(programId,iconUrl,name,currentIdex ,arrayValues )\
                                                 VALUES( %d, '%s','%s', %d, '%s');"

#define STRING_OPTION_FIND_ID_NAME    "SELECT * FROM stringOption WHERE programId = %d AND  name='%s';"
#define STRING_OPTION_FIND_ID         "SELECT * FROM stringOption WHERE programId = %d;"
#define STRING_OPTION_UPDATE_ALL      "UPDATE stringOption SET iconUrl ='%s', currentIdex=%d, arrayValues='%s' WHERE programId = %d AND  name='%s';"
#define STRING_OPTION_SELECT_ALL      "SELECT * FROM stringOption "
#define STRING_OPTION_CREATE_TABLE    "CREATE TABLE  IF NOT EXISTS stringOption (id INTEGER PRIMARY KEY,\
                                                                                    programId INTEGER,\
                                                                                    iconUrl TEXT,\
                                                                                    name TEXT,\
                                                                                    currentIdex  INTEGER,\
                                                                                    arrayValues TEXT);"



#define BOOLEAN_OPTION_INSERT_ALL      "INSERT INTO booleanOption(programId,iconUrl,name,currentIdex ,arrayValues )\
                                                 VALUES( %d, '%s','%s', %d, '%s');"

#define BOOLEAN_OPTION_FIND_ID_NAME    "SELECT * FROM booleanOption WHERE programId = %d AND  name='%s';"
#define BOOLEAN_OPTION_FIND_ID         "SELECT * FROM booleanOption WHERE programId = %d;"
#define BOOLEAN_OPTION_UPDATE_ALL      "UPDATE booleanOption SET iconUrl ='%s', currentIdex=%d, arrayValues='%s' WHERE programId = %d AND  name='%s';"
#define BOOLEAN_OPTION_SELECT_ALL      "SELECT * FROM booleanOption "
#define BOOLEAN_OPTION_CREATE_TABLE    "CREATE TABLE  IF NOT EXISTS booleanOption (id INTEGER PRIMARY KEY,\
                                                                                    programId INTEGER,\
                                                                                    iconUrl TEXT,\
                                                                                    name TEXT,\
                                                                                    currentIdex  INTEGER,\
                                                                                    arrayValues TEXT);"


typedef enum PROGRAM_IDS{
    PROGRAM_ID_JEANS = 0,
    PROGRAM_ID_COTTON ,
    PROGRAM_ID_EASY_CARE ,
    PROGRAM_ID_MY_TIME ,
    PROGRAM_ID_MIX ,
    PROGRAM_ID_UNKNOW
}programId;



struct Program{
   programId   mProgramId;
   std::string mTileImageUrl;
   std::string mProgramName;
   std::string mModeName;
   int mIsFavorite;
   int mOrder;
};



#endif // DEF_BSH_DB_H
