#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>
#include <QSignalSpy>

#include "ui_cocktailform.h"
#include "cocktail.h"
#include "cocktailform.h"

class CocktailFormTest : public QObject
{
    Q_OBJECT

public:
    CocktailFormTest();

private Q_SLOTS:
    void testName();
    void testName_data();
    void testLoad();
};

CocktailFormTest::CocktailFormTest()
{
}

void CocktailFormTest::testName()
{
    CocktailForm form;
    QTest::keyClicks(form.ui->nameLineEdit, "Mojito");

    QCOMPARE(form.cocktail()->name(), QString("Mojito"));
}

void CocktailFormTest::testName_data()
{
}

void CocktailFormTest::testLoad()
{
    CocktailForm form;
    QTest::mouseClick(form.ui->LongIslandLoadPushButton, Qt::LeftButton);

    QCOMPARE(form.cocktail()->name(), QString("Long Island"));
}

QTEST_MAIN(CocktailFormTest)

#include "tst_cocktailformtest.moc"

