#include "cocktailform.h"
#include "ui_cocktailform.h"

CocktailForm::CocktailForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CocktailForm)
{
    ui->setupUi(this);
}

CocktailForm::~CocktailForm()
{
    delete ui;
}
