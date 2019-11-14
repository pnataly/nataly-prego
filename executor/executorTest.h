#ifndef __EXECUTORTEST_H__
#define __EXECUTORTEST_H__
#include "executor.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;


TEST_RESULT CreateTest1();

TEST_RESULT CreateTest2();

TEST_RESULT DestroyTest1();

TEST_RESULT DestroyTest2();

TEST_RESULT AddTest1();

TEST_RESULT AddTest2();

TEST_RESULT AddTest3();

TEST_RESULT AddTest4();

TEST_RESULT RunTest1();

TEST_RESULT RunTest2();

TEST_RESULT RunTest3();

TEST_RESULT RunTest4();

TEST_RESULT PauseTest1();

TEST_RESULT PauseTest2();



void PrintResult (int _result, char _string[]);


#endif /*__EXECUTORTEST_H__*/ 
