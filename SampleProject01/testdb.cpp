#include "testdb.h"
#include <bshdb.h>
#include <QtGlobal>

void TestDb::testProgramTable01(){
    BshDb* pDb = new BshDb("./abt.db");
    pDb->initDb();
    std::string inText = "dfadfasdf452525";
    pDb->setProgramTable(PROGRAM_IDS::PROGRAM_ID_SETTING, inText);

    std::string outText ;
    pDb->getProgramTable(PROGRAM_IDS::PROGRAM_ID_SETTING, outText);

    QVERIFY( inText  ==  outText );
    delete pDb;
}

void TestDb::testProgramTable02(){
    BshDb* pDb = new BshDb("./abt.db");

    pDb->initDb();
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_01, "abc", "fdsfadfd", 123, 567 });
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_02, "abc12", "zyz", 456356, 567 });

    delete pDb;
}

void TestDb::testProgramTable03(){
    BshDb* pDb = new BshDb("./abt.db");

    pDb->initDb();
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_UNKNOW, "dffadfad", "675ggw5", 123, 567 });
    pDb->deleteProgramTable(PROGRAM_IDS::PROGRAM_ID_UNKNOW);

    delete pDb;
}

void TestDb::testProgramTable04(){
    BshDb* pDb = new BshDb("./abt.db");
    pDb->initDb();
    int iSize = pDb->getSizeOfProgramTable();
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_UNKNOW, "dffadfad", "675ggw5", 123, 567 });
    pDb->deleteProgramTable(PROGRAM_IDS::PROGRAM_ID_UNKNOW);

    int oSize = pDb->getSizeOfProgramTable();

    QVERIFY( iSize  ==  oSize );

    delete pDb;
}

void TestDb::testSettingElementTable01(){
    BshDb* pDb = new BshDb("./abt.db");
    pDb->initDb();
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/abc", "dsfasdf", 5645654, "567" });
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/1234", "abc", 123, "567" });

    delete pDb;
}

void TestDb::testSettingElementTable02(){
    BshDb* pDb = new BshDb("./testSettingElementTable02.db");
    pDb->initDb();
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/abc", "abd7567657fda", 5645654, "567" });
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/1234", "abc", 123, "567" });

    std::vector<struct SettingElement>  vSettingElement;
    pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02, vSettingElement);


    int sizeOfProGram =  vSettingElement.size();
    QCOMPARE(2, sizeOfProGram);
    delete pDb;
}


void TestDb::testSettingElementTable03(){
    BshDb* pDb = new BshDb("./testSettingElementTable02.db");
    pDb->initDb();
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/abc", "abd7567657fda", 5645654, "567" });
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/1234", "abc", 123, "567" });

    std::vector<struct SettingElement>  vSettingElement;
    pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02, vSettingElement);


    int sizeOfProGram =  pDb->getSizeOfSettingElementTable();
    QCOMPARE(2, sizeOfProGram);
    delete pDb;
}
