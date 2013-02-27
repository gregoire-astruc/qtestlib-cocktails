#pragma once
#include <QtCore/QObject>

class CocktailTest : public QObject
{
    Q_OBJECT

public:
    CocktailTest();

private Q_SLOTS:
    void testName();
    void testName_data();
};
