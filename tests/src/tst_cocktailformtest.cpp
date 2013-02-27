#include "tst_cocktailformtest.h"

#include <QtCore/QString>
#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "ui_cocktailform.h"
#include "cocktail.h"
#include "cocktailform.h"

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
