

#include "testqstring.h"
#include "testDb.h"
#include <QDebug>


int main(int argc, char** argv){

    int failedTests = 0;
    TestQString testClassA;
    TestDb testClassB;
    failedTests += QTest::qExec(&testClassA, argc, argv);
    failedTests += QTest::qExec(&testClassB, argc, argv);

    qDebug() << ""  ;

    qDebug() << "-----------------Report Results ----------------"  ;
    if(failedTests > 0){
        qDebug() << "total number of failed tests: " << failedTests;
    }else{
        qDebug() << "all tests passed :)";
    }
    return failedTests;
}
