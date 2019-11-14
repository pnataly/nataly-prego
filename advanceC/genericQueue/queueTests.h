#ifndef _TESTS_H
#define _TESTS_H
#include "genericQueue.h"


typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;


TEST_RESULT CreateTest1();

TEST_RESULT CreateTest2();



TEST_RESULT CreateTest3();

TEST_RESULT DestroyTest1();

TEST_RESULT DestroyTest2();


TEST_RESULT IsEmptyTest1();


TEST_RESULT IsEmptyTest2();


TEST_RESULT InsertTest1();


TEST_RESULT InsertTest2();


TEST_RESULT InsertTest3();

TEST_RESULT InsertTest4();

TEST_RESULT RemoveTest1();

TEST_RESULT RemovegTest2();

TEST_RESULT RemovegTest3();


void PrintResult (int _result, char _string[]);

#endif /*_TESTS_H*/
