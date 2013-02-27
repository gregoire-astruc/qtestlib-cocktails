#include "tst_cocktailtest.h"
#include <QtCore/QString>
#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "cocktail.h"

CocktailTest::CocktailTest()
{
}

void CocktailTest::testName()
{
    QFETCH(QString, name);
    Cocktail cocktail(name);
    QSignalSpy spy(&cocktail, SIGNAL(nameChanged(QString)));

    QCOMPARE(cocktail.name(), name);

    cocktail.setName(name + " is good!");

    QCOMPARE(cocktail.name(), name + " is good!");
    QCOMPARE(spy.count(), 1);

    QVariantList args = spy.takeFirst();
    QCOMPARE(args.at(0).toString(), name + " is good!");
}

void CocktailTest::testName_data()
{
    QTest::addColumn<QString>("name");
    QTest::newRow("Long island") << "Long island";
}
