#ifndef __HASHTEST_H__
#define __HASHTEST_H__
#include "hash.h"
#include "ADTErr.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;

TEST_RESULT CreateTest1();

TEST_RESULT CreateTest2();

TEST_RESULT CreateTest3();

TEST_RESULT DestroyTest1();

TEST_RESULT InsertTest1();

TEST_RESULT InsertTest2();

TEST_RESULT InsertTest3();

TEST_RESULT IsDataFound1();

#endif /*__HASHTEST_H__*/
