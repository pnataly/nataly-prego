#ifndef __SORTTEST_H__
#define __SORTTEST_H__
#include "sort.h"
#include "ADTErr.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;

/* @Description: Bubble sort for size 1000. */
TEST_RESULT BubbleTest1();

/* @Description: Bubble sort for size 10000. */
TEST_RESULT BubbleTest2();

/* @Description: Bubble sort for size 50000. */
TEST_RESULT BubbleTest3();

/* @Description: Shake sort for size 1000. */
TEST_RESULT ShakeTest1();

/* @Description: Shake sort for size 10000. */
TEST_RESULT ShakeTest2();

/* @Description: Shake sort for size 50000. */
TEST_RESULT ShakeTest3();

/* @Description: Quick sort for size 1000. */
TEST_RESULT QuickTest1();

/* @Description: Quick sort for size 10000. */
TEST_RESULT QuickTest2();

/* @Description: Quick sort for size 50000. */
TEST_RESULT QuickTest3();

/* @Description: Insertion sort for size 1000. */
TEST_RESULT InsertionTest1();

/* @Description: Insertion sort for size 10000. */
TEST_RESULT InsertionTest2();

/* @Description: Insertion sort for size 50000. */
TEST_RESULT InsertionTest3();

/* @Description: Shell sort for size 1000. */
TEST_RESULT ShellTest1();

/* @Description: Shell sort for size 10000. */
TEST_RESULT ShellTest2();

/* @Description: Shell sort for size 50000. */
TEST_RESULT ShellTest3();

/* @Description: Selction sort for size 1000. */
TEST_RESULT SelctionTest1();

/* @Description: Selction sort for size 10000. */
TEST_RESULT SelctionTest2();

/* @Description: Selction sort for size 50000. */
TEST_RESULT SelctionTest3();

/* @Description: Counting sort for size 1000. */
TEST_RESULT CountingTest1();

/* @Description: Counting sort for size 10000. */
TEST_RESULT CountingTest2();

/* @Description: Counting sort for size 50000. */
TEST_RESULT CountingTest3();

#endif /*__SORTTEST_H__*/
