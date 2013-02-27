#pragma once
#include <QtCore/QObject>

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
