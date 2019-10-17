

#include "testqstring.h"
QTEST_MAIN(TestQString)


//#include "testqstring.moc"

/*
int main(int argc, char *argv[ ])
{
    BshDb db("./abt.db");
    db.initDb();
    db.setProgramTable(PROGRAM_IDS::PROGRAM_ID_SETTING, "ThongLT");
    db.setProgramTable(PROGRAM_IDS::PROGRAM_ID_UNKNOW, "xyz");
    db.selectProgramTable();

    db.setProgramTable({ PROGRAM_IDS::PROGRAM_ID_01, "abc", "zyz", 123, 567 });
    db.setProgramTable({ PROGRAM_IDS::PROGRAM_ID_02, "abc12", "zyz", 123, 567 });

    db.selectProgramTable();

    db.setProgramTable({ PROGRAM_IDS::PROGRAM_ID_02, "abc12", "555555555555555", 123, 567 });

    std::string text ;
    db.getProgramTable(PROGRAM_IDS::PROGRAM_ID_SETTING, text);
    qWarning() <<"text="<<text.c_str();

    db.DeleteProgramTable(PROGRAM_IDS::PROGRAM_ID_UNKNOW);


    db.setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/abc", "abc", 123, "567" });
    db.setSettingElementTable(PROGRAM_IDS::PROGRAM_ID_02,  {"/1234", "abc", 123, "567" });
    return 0;
}*/
// select * from settingElement
// select * from program
