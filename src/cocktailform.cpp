#include "cocktailform.h"
#include "ui_cocktailform.h"

#include "cocktail.h"

CocktailForm::CocktailForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CocktailForm),
    cocktail_(new Cocktail("Default"))
{
    ui->setupUi(this);
    connect(ui->nameLineEdit, SIGNAL(textChanged(QString)), cocktail_, SLOT(setName(QString)));
    connect(ui->LongIslandLoadPushButton, SIGNAL(clicked()), this, SLOT(setLongIsland()));
}

CocktailForm::~CocktailForm()
{
    delete ui;
}

void CocktailForm::setLongIsland()
{
    cocktail_->setName("Long Island");
}
