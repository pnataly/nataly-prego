#ifndef _TESTS_H
#define _TESTS_H
#include "queue.h"
#include "ADTErr.h"

typedef enum TEST_RESULT {FAILED=0, PASSED} TEST_RESULT;


/* @Description: check the result when we create queue with size 0.
 * @Return: if QueueCreate return NULL the function return passed, if not return failed.
*/ 
TEST_RESULT CreateLimTest1();


/* @Description: check the result when we create queue with big size.
 * @Return: if QueueCreate return NULL the function return passed, if not return failed.
*/ 
TEST_RESULT CreateLimTest2();



TEST_RESULT CreateLimTest3();


/* @Description: check the result when we insert numbers to queue.
 * @Return: if QueueInsert return ERR_OK the function return passed, if not return failed.
*/ 
TEST_RESULT InsertPosTest3();


/* @Description: check the result when we destroy queue and try to insert number to the destroy queue.
 * @Return: if QueueInsert return ERR_UNINITINALAIZED the function return passed, if not return failed.
*/ 
TEST_RESULT InsertNegTest4();


/* @Description: check the result when we insert number when the queue is full.
 * @Return: if QueueInsert return ERR_OVERFLOW the function return passed, if not return failed.
*/ 
TEST_RESULT InsertNegTest5();


/* @Description: check the result when we insert numbers to queue and remove them.
 * @Return: if QueueRemove return ERR_OK the function return passed, if not return failed.
*/ 
TEST_RESULT RemovePosTest6();

/* @Description: check the result when we remove from empty queue.
 * @Return: if QueueRemove return ERR_EMPTY the function return passed, if not return failed.
*/ 
TEST_RESULT RemoveNegTest7();


/* @Description: check the result when we insert number to queue and check if the queue is empty.
 * @Return: if IsEmptyQueue return !TRUE the function return passed, if not return failed.
*/ 
TEST_RESULT IsEmptyPosTest8();


/* @Description: check the result when we create empty queue and check if the queue is empty.
 * @Return: if IsEmptyQueue return TRUE the function return passed, if not return failed.
*/ 
TEST_RESULT IsEmptyNegTest9();


/* @Description: Prints the result of the tests function of Queue.
 * @Input: _string = the name of the function.
 * @Input: _result = function's result. 
*/ 
void PrintResult (int _result, char _string[]);

#endif /*_TESTS_H*/
