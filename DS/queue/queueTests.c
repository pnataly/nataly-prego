#include <stdio.h>
#include <stdlib.h>
#include "genericQueue.h"
#include "queueTests.h"



TEST_RESULT CreateLimTest1()
{
	if(QueueCreate(0) == NULL)
	{
		return PASSED;
	}
	return FAILED;
}


TEST_RESULT CreateLimTest2()
{
	if(QueueCreate(10000000000) == NULL)
	{
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT CreateLimTest3()
{
	if(QueueCreate(5) != NULL)
	{
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT InsertPosTest3()
{
	Queue* newQueue;
	newQueue = QueueCreate(3);
	if(newQueue != NULL)
	{
		if(QueueInsert(newQueue, 3) == ERR_OK)
		{
			QueueDestroy(newQueue);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT InsertNegTest4()
{
	Queue* newQueue;
	newQueue = QueueCreate(5);
	if(newQueue != NULL)
	{
		QueueDestroy(newQueue);
		if(QueueInsert(newQueue,1) == ERR_UNINITINALAIZED)
		{
			return PASSED;
		}
	}
	return FAILED;
}


TEST_RESULT InsertNegTest5()
{
	Queue* newQueue;
	int count = 0;
	int i = 0;
	newQueue = QueueCreate(5);
	if(newQueue != NULL)
	{
		while(i<5)
		{
			if(QueueInsert(newQueue, 3) == ERR_OK)
			{
				count++;
			}
			i++;
		}
		if(count == 5)
		{
			if(QueueInsert(newQueue, 3) == ERR_OVERFLOW)
			{
				QueueDestroy(newQueue);
				return PASSED;
			}
		}
		
	}
	return FAILED;
}

TEST_RESULT RemovePosTest6()
{
	Queue* newQueue;
	int _item = 8;
	int* _pItem = &_item;
	newQueue = QueueCreate(3);
	if(newQueue != NULL)
	{
		if(QueueInsert(newQueue, _item) == ERR_OK)
		{
			if(QueueRemove(newQueue, _pItem) == ERR_OK)
			{
				QueueDestroy(newQueue);
				return PASSED;
			}
		}
	}
	return FAILED;
}

TEST_RESULT RemoveNegTest7()
{
	Queue* newQueue;
	int _item=5;
	int* _pItem = &_item;
	newQueue = QueueCreate(5);
	if(newQueue != NULL)
	{
		if(QueueRemove(newQueue, _pItem) == ERR_UNDERFLOW)
		{
			QueueDestroy(newQueue);
			return PASSED;
		}
	}
	return FAILED;
}


TEST_RESULT IsEmptyPosTest8()
{
	Queue* newQueue;
	newQueue = QueueCreate(5);
	if(newQueue != NULL)
	{
		if(QueueInsert(newQueue, 3) == ERR_OK)
		{
			if(!IsEmptyQueue(newQueue))
			{
				QueueDestroy(newQueue);
				return PASSED;
			}
		}
	}	
	return FAILED;
}


TEST_RESULT IsEmptyNegTest9()
{
	Queue* newQueue;
	newQueue = QueueCreate(5);
	if(newQueue != NULL)
	{
		if(IsEmptyQueue(newQueue))
		{
			QueueDestroy(newQueue);
			return PASSED;
		}
	}	
	return FAILED;
}


void PrintResult(int _result, char _string[])
{

	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
	printf("\n");
}


