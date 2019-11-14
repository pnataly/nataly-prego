#include <stdio.h>
#include <stdlib.h>
#include "genericDoubleList.h"
#include "doubleListTests.h"

void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}


TEST_RESULT CreateTest1() /* create list */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		free(list);
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT DestroyTest1() /* destroy list */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		List_Destroy(&list, IntDestroy);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT DestroyTest2() /* double destroy */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		List_Destroy(&list, IntDestroy);
		List_Destroy(&list, IntDestroy);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT PushHeadTest1() /*push to unitialaized list */
{
	List* list = NULL;
	int array[2]= {1,2};
	if(List_PushHead(list, &array[0]) == LIST_UNINITIALIZED_ERROR)
	{
		return PASSED;
	}	

	return FAILED;
}

TEST_RESULT PushHeadTest2() /* item is NULL */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushHead(list, NULL) == LIST_NULL_ELEMENT_ERROR)
		{
			List_Destroy(&list, NULL);
			return PASSED;
		}	
	}
	return FAILED;
}

TEST_RESULT PushHeadTest3() /* push to head list */
{
	List* list;
	int array[2]= {1,2};
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushHead(list, &(array[0])) == LIST_SUCCESS)
		{
			free(list);
			return PASSED;
		}	
	}
	return FAILED;
}

TEST_RESULT PushTailTest1() /*push to unitialaized list */
{
	List* list = NULL;
	int array[2]= {1,2};
	if(List_PushTail(list, &(array[0])) == LIST_UNINITIALIZED_ERROR)
	{
		free(list);
		return PASSED;
	}	

	return FAILED;
}

TEST_RESULT PushTailTest2() /* item is NULL */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushTail(list, NULL) == LIST_NULL_ELEMENT_ERROR)
		{
			free(list);
			return PASSED;
		}	
	}
	return FAILED;
}

TEST_RESULT PushTailTest3() /* push to tail list */
{
	List* list;
	int array[2]= {1,2};
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushTail(list, &(array[0])) == LIST_SUCCESS)
		{
			free(list);
			return PASSED;
		}	
	}
	return FAILED;
}

TEST_RESULT PopHeadTest1() /*pop from unitialaized list */
{
	List* list = NULL;
	int* Pdata;
	if(List_PopHead(list, (void*)&Pdata) == LIST_UNINITIALIZED_ERROR)
	{
		free(list);
		return PASSED;
	}	
	free(list);
	return FAILED;
}

TEST_RESULT PopHeadTest2() /* item is NULL */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		if(List_PopHead(list, NULL) == LIST_NULL_ELEMENT_ERROR)
		{
			free(list);
			return PASSED;
		}	
	}
	free(list);
	return FAILED;
}

TEST_RESULT PopHeadTest3() /* pop from empty list */
{
	List* list;
	int* Pdata;
	list = List_Create();
	if(list != NULL)
	{
		if(List_PopHead(list, (void*)&Pdata) == LIST_UNDERFLOW_ERROR)
		{
			free(list);
			return PASSED;
		}	
	}
	free(list);
	return FAILED;
}

TEST_RESULT PopHeadTest4() /* pop from list's head */
{
	List* list;
	int* Pdata;
	int array[2]= {1,2};
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushTail(list, &(array[0])) == LIST_SUCCESS)
		{
			if(List_PopHead(list, (void*)&Pdata) == LIST_SUCCESS)
			{
				free(list);
				return PASSED;
			}
		}	
	}
	free(list);
	return FAILED;
} 

TEST_RESULT PopTailTest1() /*pop from unitialaized list */
{
	List* list = NULL;
	int* Pdata;
	if(List_PopTail(list, (void*)&Pdata) == LIST_UNINITIALIZED_ERROR)
	{
		free(list);
		return PASSED;
	}	
	free(list);
	return FAILED;
}

TEST_RESULT PopTailTest2() /* item is NULL */
{
	List* list;
	list = List_Create();
	if(list != NULL)
	{
		if(List_PopTail(list, NULL) == LIST_NULL_ELEMENT_ERROR)
		{
			free(list);
			return PASSED;
		}	
	}
	free(list);
	return FAILED;
}

TEST_RESULT PopTailTest3()  /* pop from empty list */
{
	List* list;
	int* Pdata;
	list = List_Create();
	if(list != NULL)
	{
		if(List_PopTail(list, (void*)&Pdata) == LIST_UNDERFLOW_ERROR)
		{
			free(list);
			return PASSED;
		}	
	}
	free(list);
	return FAILED;
}


TEST_RESULT PopTailTest4() /* pop from list's tail */
{
	List* list;
	int* Pdata;
	int array[2]= {1,2};
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushTail(list, &(array[0])) == LIST_SUCCESS)
		{
			if(List_PopTail(list, (void*)&Pdata) == LIST_SUCCESS)
			{
				free(list);
				return PASSED;
			}
		}	
	}
	free(list);
	return FAILED;
} 

TEST_RESULT ListSizeTest1() /* size of unitialaized list */
{
	List* list = NULL;
	if(List_Size(list) == 0)
	{
		return PASSED;
	}
	return FAILED;
}


TEST_RESULT ListSizeTest2() /* size of list */
{
	List* list;
	int array[2]= {1,2};
	list = List_Create();
	if(list != NULL)
	{
		if(List_PushTail(list, &(array[0])) == LIST_SUCCESS)
		{
			if(List_Size(list) == 1)
			{
				free(list);
				return PASSED;
			}
		}
	}
	free(list);
	return FAILED;
}

void PrintResult(int _result, char _string[])
{
	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
	printf("\n");
}


