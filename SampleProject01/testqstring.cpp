#include "testqstring.h"


void TestQString::toUpper01()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}




void TestQString::toUpper02()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "xyz");
}

