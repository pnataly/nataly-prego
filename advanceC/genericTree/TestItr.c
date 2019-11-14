#include <stdio.h>
#include <stdlib.h>
#include "genericBst.h"
#include "TestItr.h"

int Less(void* _left,void* _right)
{
	if(_left == NULL || _right == NULL)
	{
		return FALSE;
	}
	return (_left<_right);
}

TEST_RESULT CreateTest1() /*create BST */
{
	BSTree* tree;
	tree = BSTree_Create(Less);
	if(tree != NULL)
	{
		free(tree);
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT DestroyTest1() /* destroy BST */
{
	BSTree* tree;
	tree = BSTree_Create(Less);
	if(tree != NULL)
	{
		BSTree_Destroy(&tree, NULL);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT BeginTest1()
{
	BSTree* tree;
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTreeItr_Begin(tree) == BSTreeItr_End(tree))
	{
		BSTree_Destroy(&tree, NULL);
		return PASSED;	
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT BeginTest2()
{
	BSTree* tree = NULL;
	if(BSTreeItr_Begin(tree) == NULL)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT EndTest1()
{
	BSTree* tree = NULL;
	if(BSTreeItr_End(tree) == NULL)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT EndTest2()
{
	BSTree* tree;
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTreeItr_End(tree) == BSTreeItr_Begin(tree))
	{
		BSTree_Destroy(&tree, NULL);
		return PASSED;	
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT EqualTest1()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[1]) != BSTreeItr_End(tree))
	{
		if(!BSTreeItr_Equals(BSTreeItr_Begin(tree), NULL))
		{
			BSTree_Destroy(&tree, NULL);
			return PASSED;	
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT EqualTest2()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[1]) != BSTreeItr_End(tree))
	{
		if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
		{
			if(!BSTreeItr_Equals(BSTreeItr_End(tree) , BSTreeItr_Begin(tree)))
			{
				BSTree_Destroy(&tree, NULL);
				return PASSED;	
			}
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT NextTest1()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
	{
		if(BSTree_Insert(tree, &Array[1]) != BSTreeItr_End(tree))
		{
			if((BSTreeItr_Next(BSTreeItr_Begin(tree))) == BSTreeItr_End(tree))
			{
				BSTree_Destroy(&tree, NULL);
				return PASSED;	
			}
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT NextTest2()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
	{
		if(BSTreeItr_Next(NULL) == NULL)
		{
			BSTree_Destroy(&tree, NULL);
			return PASSED;	
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT PrevTest1()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
	{
		if(BSTreeItr_Prev(NULL) == NULL)
		{
			BSTree_Destroy(&tree, NULL);
			return PASSED;	
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT PrevTest2()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
	{
		if(BSTree_Insert(tree, &Array[1]) != BSTreeItr_End(tree))
		{
			if(BSTreeItr_Prev(BSTreeItr_End(tree)) == BSTreeItr_Begin(tree))
			{
				BSTree_Destroy(&tree, NULL);
				return PASSED;	
			}
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT GetTest1()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
	{
		if(BSTreeItr_Get(NULL) == NULL)
		{
			BSTree_Destroy(&tree, NULL);
			return PASSED;	
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT GetTest2()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, &Array[0]) != BSTreeItr_End(tree))
	{
		if((BSTreeItr_Get(BSTreeItr_End(tree))) == &Array[0])
		{
			BSTree_Destroy(&tree, NULL);
			return PASSED;	
		}
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}


TEST_RESULT InsertTest1()
{
	void* data;
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(NULL, data) == NULL)
	{
		BSTree_Destroy(&tree, NULL);
		return PASSED;	
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT InsertTest2()
{
	void* data = NULL;
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, data) == BSTreeItr_End(tree))
	{
		BSTree_Destroy(&tree, NULL);
		return PASSED;	
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}

TEST_RESULT InsertTest3()
{
	BSTree* tree;
	int Array[5] = {1,2,3,4,5};
	void* data = &Array[3];
	tree = BSTree_Create(Less);
	if(tree == NULL)
	{
		return FAILED;
	}
	if(BSTree_Insert(tree, data) == BSTreeItr_End(tree))
	{
		BSTree_Destroy(&tree, NULL);
		return PASSED;	
	}
	BSTree_Destroy(&tree, NULL);
	return FAILED;
}


void PrintResult(int _result, char _string[])
{
	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
	printf("\n");
}
