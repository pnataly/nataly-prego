#include <stdio.h>
#include "BinarySearchTree.h"

typedef enum TEST_RESULT {FAILED, PASSED} TEST_RESULT;


TEST_RESULT CreateTree1()
{
	if(TreeCreate() != NULL)
	{
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT DestroyTree1()
{
	Tree* newTree;
	newTree = TreeCreate();
	if(TreeCreate() != NULL)
	{
		TreeDestroy(newTree);
		TreeDestroy(newTree);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT InsertTree1()
{
	Tree* newTree;
	newTree = TreeCreate();
	if(newTree != NULL)
	{
		if(TreeInsert(newTree, 3) == ERR_OK)
		{
			TreeDestroy(newTree);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT InsertTree2()
{
	Tree* newTree;
	newTree = TreeCreate();
	if(newTree != NULL)
	{
		TreeDestroy(newTree);
		if(TreeInsert(newTree, 3) == ERR_UNINITINALAIZED)
		{
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT InsertTree3()
{
	Tree* newTree;
	newTree = TreeCreate();
	if(newTree != NULL)
	{
		if(TreeInsert(newTree, 3) == ERR_OK)
		{
			if(TreeInsert(newTree, 5) == ERR_OK)
			{
				if(TreeInsert(newTree, 4) == ERR_OK)
				{
					TreeDestroy(newTree);
					return PASSED;
				}
			}

		}
	}
	return FAILED;
}

TEST_RESULT IsDataFound1()
{
	Tree* newTree;
	newTree = TreeCreate();
	if(newTree != NULL)
	{
		if(TreeInsert(newTree, 3) == ERR_OK)
		{
			if(TreeIsDataFound(newTree,3))
			{
				TreeDestroy(newTree);
				return PASSED;
			}
		}
	}	
	return FAILED;
}

TEST_RESULT IsDataFound2()
{
	Tree* newTree;
	newTree = TreeCreate();
	if(newTree != NULL)
	{
		if(!TreeIsDataFound(newTree,1))
		{
			TreeDestroy(newTree);
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
