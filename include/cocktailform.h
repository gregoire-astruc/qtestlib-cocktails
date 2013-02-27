#ifndef COCKTAILFORM_H
#define COCKTAILFORM_H

#include <QWidget>

namespace Ui {
class CocktailForm;
}

class CocktailForm : public QWidget
{
    Q_OBJECT

public:
    explicit CocktailForm(QWidget *parent = 0);
    ~CocktailForm();
    
private:
    Ui::CocktailForm *ui;
};

#endif // COCKTAILFORM_H
