#ifndef TESTDB_H
#define TESTDB_H

#include <QObject>
#include <QtTest/QtTest>


class TestDb: public QObject
{
    Q_OBJECT
private slots:
    void testProgramTable01();
    void testProgramTable02();
    void testProgramTable03();
    void testProgramTable04();
    void testProgramTable05();
    void testProgramTable06();
    void testProgramTable07();
    void testProgramTable08();
    void testProgramTable09();
    void testProgramTable10();

    void testSettingElementTable01();
    void testSettingElementTable02();
    void testSettingElementTable03();


};




#endif // TESTDB_H
