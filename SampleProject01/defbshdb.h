#ifndef DEFBSHDB_H
#define DEFBSHDB_H
#include <string>


#define PROGRAM_INSERT_ALL          "INSERT INTO Program(programId,modeName,programName,isFavorite,isOrder) VALUES( %d, '%s','%s', %d, %d );"
#define PROGRAM_INSERT_MODE_NAME    "INSERT INTO Program(programId,modeName) VALUES( %d, '%s' );"
#define PROGRAM_UPDATE_ALL          "UPDATE program SET modeName ='%s', programName='%s', isFavorite= %d, isFavorite= %d  WHERE programId = %d;"
#define PROGRAM_UPDATE_MODE_NAME    "UPDATE program SET modeName ='%s' WHERE programId = %d;"
#define PROGRAM_DELETE_ID           "DELETE FROM Program WHERE programId = %d;"
#define PROGRAM_FIND_ID             "SELECT modeName FROM Program WHERE programId = %d;"
#define PROGRAM_SELECT_ALL          "SELECT * FROM Program "

#define SETTING_ELEMENT_INSERT_ALL      "INSERT INTO settingElement(programId,iconUrl,name,value,valueType) VALUES( %d, '%s','%s', %d, '%s' );"
#define SETTING_ELEMENT_FIND_ID_NAME    "SELECT * FROM settingElement WHERE programId = %d AND  name='%s';"
#define SETTING_ELEMENT_FIND_ID         "SELECT * FROM settingElement WHERE programId = %d;"
#define SETTING_ELEMENT_UPDATE_ALL      "UPDATE settingElement SET iconUrl ='%s', value='%d', valueType= %s WHERE programId = %d AND  name='%s';"
#define SETTING_ELEMENT_SELECT_ALL      "SELECT * FROM settingElement "


typedef  enum PROGRAM_IDS{
    PROGRAM_ID_SETTING = 2,
    PROGRAM_ID_01 ,
    PROGRAM_ID_02 ,
    PROGRAM_ID_UNKNOW
}programId;


struct Program{
   programId   mProgramId;
   std::string mModeName;
   std::string mProgramName;
   int mIsFavorite;
   int mOrder;
};

struct SettingElement{
    std::string iconUrl;
    std::string name;
    int value;
    std::string valueType;
};

#endif // DEFBSHDB_H
