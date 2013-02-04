#ifndef TEST_H
#define TEST_H

#ifdef USE_TESTS
#define Q_TESTCLASS(Testee) friend class Testee##Test;
#else
#define Q_TESTCLASS(Testee)
#endif

#endif // TEST_H
