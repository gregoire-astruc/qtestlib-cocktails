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
    const QString &name() const { return name_; }

public slots:
    void setName(const QString &);

signals:
    void nameChanged(QString);

protected:
    QString name_;
};

#endif // COCKTAIL_H
