#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

enum TEST_RESULT {FAILED=0, PASSED};


enum TEST_RESULT CreateTest1()
{
	Vector* newVector;
	newVector = VectorCreate(0,0);
	if(newVector == NULL)
	{
		return PASSED;
	}
	free(newVector);
	return FAILED;
}

enum TEST_RESULT CreateTest2()
{
	Vector* newVector;

	newVector = VectorCreate(1000000000, 100);
	if(newVector == NULL)
	{
		return PASSED;
	}
	free(newVector);
	return FAILED;
}

enum TEST_RESULT CreateTest3()
{
	Vector* newVector;
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		free(newVector);
		return PASSED;
	}
	return FAILED;
}

enum TEST_RESULT AddTest1()
{
	Vector* newVector;
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(VectorAdd(newVector, 3) == ERR_OK)
		{
			free(newVector);
			return PASSED;
		}
	}
	return FAILED;
}

enum TEST_RESULT AddTest2()
{
	Vector* newVector;
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		VectorDestroy(newVector);
		if(VectorAdd(newVector,1) == ERR_UNINITINALAIZED)
		{
			return PASSED;
		}
	}
	return FAILED;
}

enum TEST_RESULT AddTest3()
{
	Vector* newVector;
	int count = 0;
	int i = 0;
	newVector = VectorCreate(5,0);
	if(newVector != NULL)
	{
		while(i<5)
		{
			if(VectorAdd(newVector, 3) == ERR_OK)
			{
				count++;
			}
			i++;
		}
		if(count == 5)
		{
			if(VectorAdd(newVector, 3) == ERR_OVERFLOW)
			{
				free(newVector);
				return PASSED;
			}
		}
		
	}
	return FAILED;
}

enum TEST_RESULT RemoveTest1()
{
	Vector* newVector;
	int _item = 8;
	int* _pItem = &_item;
	newVector = VectorCreate(5,5);
	if(newVector != NULL)
	{
		if(VectorAdd(newVector, _item) == ERR_OK)
		{
			if(VectorDelete(newVector, _pItem) == ERR_OK)
			{
				free(newVector);
				return PASSED;
			}
		}
	}
	return FAILED;
}

enum TEST_RESULT RemoveTest2()
{
	Vector* newVector;
	int _item=5;
	int* _pItem = &_item;
	newVector = VectorCreate(5,5);
	if(newVector != NULL)
	{
		if(VectorDelete(newVector, _pItem) == ERR_UNDERFLOW)
		{
			free(newVector);
			return PASSED;
		}
	}
	return FAILED;
}

void PrintResult(int _result, char _string[])
{

	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
}

