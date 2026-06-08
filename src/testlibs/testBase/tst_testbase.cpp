#include <QTest>

// add necessary includes here
#include <irBase/TriBool.h>

class testBase : public QObject
{
    Q_OBJECT

public:
    testBase();
    ~testBase();

private slots:
    void testTriBool();
};

testBase::testBase() {}

testBase::~testBase() {}

void testBase::testTriBool()
{
    QVERIFY(true);

    TriBool nullTB;
    QVERIFY( ! nullTB.value());
    QVERIFY(nullTB.cheap());
    QVERIFY( ! nullTB.valid());
    QVERIFY(nullTB.invalid());
    QVERIFY( ! nullTB.isNull());
    QVERIFY( ! nullTB.isTrue());
    QVERIFY( ! nullTB.isFalse());
    nullTB.set();
    QVERIFY(nullTB.value());
    QVERIFY( ! nullTB.cheap());
    QVERIFY(nullTB.valid());
    QVERIFY( ! nullTB.invalid());
    QVERIFY( ! nullTB.isNull());
    QVERIFY(nullTB.isTrue());
    QVERIFY( ! nullTB.isFalse());
    nullTB.invalidate();
    QVERIFY( ! nullTB.value());
    QVERIFY(nullTB.cheap());
    QVERIFY( ! nullTB.valid());
    QVERIFY(nullTB.invalid());
    QVERIFY( ! nullTB.isNull());
    QVERIFY( ! nullTB.isTrue());
    QVERIFY( ! nullTB.isFalse());

    TriBool trueTB(true);
    QVERIFY(trueTB.value());
    QVERIFY( ! trueTB.cheap());
    QVERIFY(trueTB.valid());
    QVERIFY( ! trueTB.invalid());
    QVERIFY( ! trueTB.isNull());
    QVERIFY(trueTB.isTrue());
    QVERIFY( ! trueTB.isFalse());
    trueTB.reset();
    QVERIFY( ! trueTB.value());
    QVERIFY(trueTB.cheap());
    QVERIFY(trueTB.valid());
    QVERIFY( ! trueTB.invalid());
    QVERIFY( ! trueTB.isNull());
    QVERIFY( ! trueTB.isTrue());

    TriBool falseTB(false);
    QVERIFY( ! falseTB.value());
    QVERIFY(falseTB.cheap());
    QVERIFY(falseTB.valid());
    QVERIFY( ! falseTB.invalid());
    QVERIFY( ! falseTB.isNull());
    QVERIFY( ! falseTB.isTrue());
    QVERIFY(falseTB.isFalse());
    falseTB.set();
    QVERIFY(falseTB.isTrue());
    QVERIFY( ! falseTB.isFalse());
    QVERIFY(falseTB.value());
    QVERIFY( ! falseTB.cheap());
    QVERIFY(falseTB.valid());
    QVERIFY( ! falseTB.invalid());
    QVERIFY( ! falseTB.isNull());
}

QTEST_APPLESS_MAIN(testBase)

#include "tst_testbase.moc"
