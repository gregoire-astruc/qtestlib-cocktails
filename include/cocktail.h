#ifndef COCKTAIL_H
#define COCKTAIL_H

#include <QObject>

#include "tests/test.h"

class Cocktail : public QObject
{
    Q_OBJECT
    Q_TESTCLASS(Cocktail)
public:
    explicit Cocktail(const QString &name, QObject *parent = 0);
};

#endif // COCKTAIL_H
