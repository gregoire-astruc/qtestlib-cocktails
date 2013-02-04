#include "cocktail.h"

Cocktail::Cocktail(const QString &name, QObject *parent) :
    QObject(parent), name_(name)
{
}
