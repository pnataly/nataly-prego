#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "hashTest.h"


TEST_RESULT CreateTest1()
{
	if(HashCreate(0) == NULL)
	{
		return PASSED;
	}
	HashDestroy(newHash);
	return FAILED;
}


TEST_RESULT CreateTest2()
{
	if(HashCreate(10000000000) == NULL)
	{
		return PASSED;
	}
	return FAILED;
}


TEST_RESULT CreateTest3()
{
	if(HashCreate(5) != NULL)
	{
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT DestroyTest1()
{
	Hash* newHash;
	newHash = HashCreate(5);
	if(newHash != NULL)
	{
		HashDestroy(newHash);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT InsertTest1()
{
	Hash* newHash;
	newHash = HashCreate(5);
	if(newHash != NULL)
	{
		if(HashInsert(newHash, 3) == ERR_OK)
		{
			HashDestroy(newHash);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT InsertTest2()
{
	Hash* newHash;
	newHash = HashCreate(5);
	if(newHash != NULL)
	{
		HashDestroy(newHash);
		if(HashInsert(newHash, 3) == ERR_UNINITINALAIZED)
		{
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT InsertTest3()
{
	Hash* newHash;
	newHash = HashCreate(5);
	if(newHash != NULL)
	{
		if(HashInsert(newHash, 3) == ERR_OK)
		{
			if(HashInsert(newHash, 5) == ERR_OK)
			{
				if(HashInsert(newHash, 4) == ERR_OK)
				{
					HashDestroy(newHash);
					return PASSED;
				}
			}

		}
	}
	return FAILED;
}

TEST_RESULT IsDataFound1()
{
	Hash* newHash;
	newHash = HashCreate(5);
	if(newHash != NULL)
	{
		if(HashInsert(newHash, 3) == ERR_OK)
		{
			if(HashIsFound(newHash,3))
			{
				HashDestroy(newHash);
				return PASSED;
			}
		}
	}	
	return FAILED;
}


void PrintResult(int _result, char _string[])
{

	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
	printf("\n");
}
