#ifndef TESTQSTRING_H
#define TESTQSTRING_H

#include <QObject>
#include <QtTest/QtTest>

class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void toUpper01();
    void toUpper02();
};
#endif // TESTQSTRING_H
