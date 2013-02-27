#include <QtTest/qtest_gui.h>

#include "tst_cocktailformtest.h"
#include "tst_cocktailtest.h"

template<typename TestClass>
static int runTests(int argc, char *argv[])
{
    TestClass tc;
    return QTest::qExec(&tc, argc, argv);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int status = 0;

    status |= runTests<CocktailTest>(argc, argv);
    status |= runTests<CocktailFormTest>(argc, argv);


    return status;

}
