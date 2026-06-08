#include "Severity_QtUT.h"

#include <QtTest>

class Severity_QtUT : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void testCtors();
    void cleanupTestCase();

private:
};

void Severity_QtUT::initTestCase()
{
    qDebug() << "🔍 Test suite started";
}

void Severity_QtUT::cleanupTestCase()
{
    qDebug() << "✅ Test suite finished";
}

void Severity_QtUT::testCtors()
{
    QVERIFY(false);
}


QTEST_MAIN(Severity_QtUT)
#include "/home/code/temp/temp/Desktop_Qt_6_11_0-Debug/libs/irBase/Severity_QtUT.moc"
