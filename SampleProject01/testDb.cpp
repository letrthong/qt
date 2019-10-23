#include "testDb.h"
#include "BshBb.h"
#include <QtGlobal>

void TestDb::testProgramTable01(){
    BshDb* pDb = new BshDb("./testProgramTable01.db");
    pDb->initDb();
    std::string inText = "dfadfasdf452525";
    pDb->setProgramTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, inText);

    std::string outText ;
    pDb->getProgramTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, outText);

    QVERIFY( inText  ==  outText );
    delete pDb;
}


void TestDb::testProgramTable02(){
    BshDb* pDb = new BshDb("./testProgramTable02.db");

    pDb->initDb();
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_EASY_CARE, "abc","/path", "fdsfadfd", 123, 567 });
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_EASY_CARE, "abc12", "/path", "zyz", 456356, 567 });

    delete pDb;
}

void TestDb::testProgramTable03(){
    BshDb* pDb = new BshDb("./testProgramTable03.db");

    pDb->initDb();
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_UNKNOW, "dffadfad","/path", "675ggw5", 123, 567 });
    pDb->deleteProgramTable(PROGRAM_IDS::PROGRAM_ID_UNKNOW);

    delete pDb;
}

void TestDb::testProgramTable04(){
    BshDb* pDb = new BshDb("./testProgramTable04.db");
    pDb->initDb();
    int iSize = pDb->getSizeOfProgramTable();
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_UNKNOW, "dffadfad","/path", "675ggw5", 123, 567 });
    pDb->deleteProgramTable(PROGRAM_IDS::PROGRAM_ID_UNKNOW);

    int oSize = pDb->getSizeOfProgramTable();

    QVERIFY( iSize  ==  oSize );

    delete pDb;
}

void TestDb::testProgramTable05(){
    BshDb* pDb = new BshDb("./testProgramTable05.db");
    pDb->initDb();

    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_EASY_CARE, "abc", "/path", "fdsfadfd", 123, 567 });
    pDb->setProgramTable({ PROGRAM_IDS::PROGRAM_ID_EASY_CARE, "abc12", "/path", "zyz", 456356, 567 });


    std::vector<struct Program>  vProgram;

     pDb->getProgramTable( vProgram);


    int oSize = vProgram.size();

    QCOMPARE(5, oSize);

    delete pDb;
}

void TestDb::testProgramTable06(){
    BshDb* pDb = new BshDb("./testProgramTable06.db");
    pDb->initDb();
     std::vector<struct Program>  vProgram;
    pDb->getProgramTable(vProgram );
     int oSize = vProgram.size();
    QCOMPARE( 5,oSize);
     delete pDb;
}

void TestDb::testProgramTable07(){
    BshDb* pDb = new BshDb("./testProgramTable07.db");
    pDb->initDb();
     std::vector<struct Program>  vProgram;
    pDb->getProgramTable(vProgram );

      int oSize = vProgram.size();
    QCOMPARE(5,oSize );


    std::vector<DbIntegerIntervalOption> vIntegerIntervalOption;
     pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, vIntegerIntervalOption);

     oSize =  vIntegerIntervalOption.size();
    QCOMPARE(2, oSize);

     delete pDb;
}

void TestDb::testProgramTable08(){
    BshDb* pDb = new BshDb("./testProgramTable08.db");
    pDb->initDb();
     std::vector<struct Program>  vProgram;
    pDb->getProgramTable(vProgram );

    int oSize = vProgram.size();
    QCOMPARE(5,oSize );

     std::vector<DbBooleanOption>  vSettingElement;
     pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, vSettingElement);

     for( DbBooleanOption n : vSettingElement) {
         std::vector<bool> v=  n.getArrValues();
         oSize = v.size();
         QCOMPARE(3,oSize );
     }

     delete pDb;
}

void TestDb::testProgramTable09(){
    BshDb* pDb = new BshDb("./testProgramTable09.db");
    pDb->initDb();
     std::vector<struct Program>  vProgram;
    pDb->getProgramTable(vProgram );

    int oSize = vProgram.size();
    QCOMPARE(5,oSize );

     std::vector<DbIntegerOption>  vSettingElement;
     pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, vSettingElement);

     for( DbIntegerOption n : vSettingElement) {
         std::vector<int> v=  n.getArrValues();
         oSize = v.size();
         QCOMPARE(5,oSize );
     }

     delete pDb;
}

void TestDb::testProgramTable10(){
    BshDb* pDb = new BshDb("./testProgramTable10.db");
    pDb->initDb();
     std::vector<struct Program>  vProgram;
    pDb->getProgramTable(vProgram );

    int oSize = vProgram.size();
    QCOMPARE(5,oSize );

     std::vector<DbStringOption>  vSettingElement;
     pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_MIX, vSettingElement);

     for( DbStringOption n : vSettingElement) {
         std::vector<std::string> v=  n.getArrValues();
         oSize = v.size();
         QCOMPARE(2,oSize );
     }

     delete pDb;
}
void TestDb::testSettingElementTable01(){
    BshDb* pDb = new BshDb("./testSettingElementTable01.db");
    pDb->initDb();
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE,  {"name01", "iconUrl01" , 1 ,4 ,5, 30});
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, {"name01", "iconUrl01" , 1 ,4 ,5, 30});

    delete pDb;
}


void TestDb::testSettingElementTable02(){
    BshDb* pDb = new BshDb("./testSettingElementTable02.db");
    pDb->initDb();
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE,  {"name01", "iconUrl01" , 1 ,4 ,5, 30});
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE,  {"name01", "iconUrl01" , 1 ,4 ,5, 30});

    std::vector<DbIntegerIntervalOption>  vSettingElement;
    pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, vSettingElement);


    int sizeOfProGram =  vSettingElement.size();
    QCOMPARE(3, sizeOfProGram);
    delete pDb;
}


void TestDb::testSettingElementTable03(){
    BshDb* pDb = new BshDb("./testSettingElementTable03.db");
    pDb->initDb();
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE,   {"name01", "iconUrl01" , 1 ,4 ,5, 30});
    pDb->setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE,  {"name01", "iconUrl01" , 1 ,4 ,5, 30});

    std::vector<DbIntegerIntervalOption>  vSettingElement;
    pDb->getSettingElementTable(PROGRAM_IDS::PROGRAM_ID_EASY_CARE, vSettingElement);


    int sizeOfProGram =  pDb->getSizeOfSettingElementTable();
    QCOMPARE(11, sizeOfProGram);
    delete pDb;
}

