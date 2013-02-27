#include <QtGui/QApplication>
#include "cocktailform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CocktailForm c;
    c.show();

    return a.exec();
}
