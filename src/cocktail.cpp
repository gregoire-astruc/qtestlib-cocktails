#include "cocktail.h"

Cocktail::Cocktail(const QString &name, QObject *parent) :
    QObject(parent), name_(name)
{
}

void Cocktail::setName(const QString &name)
{
    if (name_ != name) {
        name_ = name;
        emit nameChanged(name_);
    }
}
