#ifndef _VECTORTESTS_H
#define _VECTORTESTS_H
#include "genericVector.h"
#include "ADTErr.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;


TEST_RESULT CreateTest1();

TEST_RESULT CreateTest2();

TEST_RESULT CreateTest3();

TEST_RESULT VectorSizeTest1();

TEST_RESULT VectorSizeTest2();

TEST_RESULT VectorCapacityTest1();

TEST_RESULT VectorCapacityTest2();

TEST_RESULT AddTest1();

TEST_RESULT AddTest2();

TEST_RESULT AddTest3();

TEST_RESULT AddTest4();

TEST_RESULT RemoveTest1();

TEST_RESULT RemoveTest2();

TEST_RESULT RemoveTest3();

TEST_RESULT RemoveTest4();

TEST_RESULT GetTest1();

TEST_RESULT GetTest2();

TEST_RESULT GetTest3();

TEST_RESULT GetTest4();

TEST_RESULT SetTest1();

TEST_RESULT SetTest2();

TEST_RESULT SetTest3();

TEST_RESULT SetTest4();

#endif /*_VECTORTESTS_H*/
