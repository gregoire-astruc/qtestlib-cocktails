#ifndef COCKTAILFORM_H
#define COCKTAILFORM_H

#include <QWidget>

#include "tests/test.h"

class Cocktail;

namespace Ui {
class CocktailForm;
}

class CocktailForm : public QWidget
{
    Q_OBJECT
    Q_TESTCLASS(CocktailForm)

public:
    explicit CocktailForm(QWidget *parent = 0);
    ~CocktailForm();
    Cocktail *cocktail() const { return cocktail_; }

private slots:
    void setLongIsland();

private:
    Ui::CocktailForm *ui;
    Cocktail *cocktail_;
};

#endif // COCKTAILFORM_H
