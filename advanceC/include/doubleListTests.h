#ifndef _TESTS_H
#define _TESTS_H
#include "genericDoubleList.h"


typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;


TEST_RESULT CreateTest1();

TEST_RESULT DestroyTest1();

TEST_RESULT DestroyTest2();

TEST_RESULT PushHeadTest1();

TEST_RESULT PushHeadTest2();

TEST_RESULT PushHeadTest3();

TEST_RESULT PushTailTest1();

TEST_RESULT PushTailTest2();

TEST_RESULT PushTailTest3();

TEST_RESULT PopHeadTest1();

TEST_RESULT PopHeadTest2();

TEST_RESULT PopHeadTest3();

TEST_RESULT PopHeadTest4();

TEST_RESULT PopTailTest1();

TEST_RESULT PopTailTest2();

TEST_RESULT PopTailTest3();

TEST_RESULT PopTailTest4();

TEST_RESULT ListSizeTest1();

TEST_RESULT ListSizeTest2();



void PrintResult (int _result, char _string[]);

#endif /*_TESTS_H*/
