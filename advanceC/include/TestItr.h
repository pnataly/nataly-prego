#ifndef __TESTITR_H__
#define __TESTITR_H__
#include <stdlib.h>
#include "list_itr.h"
#include "listStruct.h"
#include "genericDoubleList.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;

TEST_RESULT CreateTest1();

TEST_RESULT DestroyTest1();

TEST_RESULT BeginTest1();

TEST_RESULT BeginTest2();

TEST_RESULT EndTest1();

TEST_RESULT EndTest2();

TEST_RESULT EqualTest1();

TEST_RESULT EqualTest2();

TEST_RESULT NextTest1();

TEST_RESULT NextTest2();

TEST_RESULT PrevTest1();

TEST_RESULT PrevTest2();

TEST_RESULT GetTest1();

TEST_RESULT GetTest2();

TEST_RESULT SetTest1();

TEST_RESULT SetTest2();

TEST_RESULT SetTest3();

TEST_RESULT InsertTest1();

TEST_RESULT InsertTest2();

TEST_RESULT InsertTest3();

TEST_RESULT InsertTest4();

TEST_RESULT RemoveTest1();

TEST_RESULT RemoveTest2();

TEST_RESULT RemoveTest3();

void PrintResult (int _result, char _string[]);

#endif /*__TESTITR_H__*/ 
