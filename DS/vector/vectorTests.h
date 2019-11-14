#ifndef _VECTORTESTS_H
#define _VECTORTESTS_H
#include "vector.h"
#include "ADTErr.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;


TEST_RESULT CreateTest1();

TEST_RESULT CreateTest2();

TEST_RESULT CreateTest3();

TEST_RESULT AddTest1();

TEST_RESULT AddTest2();

TEST_RESULT AddTest3();

TEST_RESULT RemoveTest1();

TEST_RESULT RemoveTest2();


#endif /*_VECTORTESTS_H*/
