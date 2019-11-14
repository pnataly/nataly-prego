#include <stdio.h>
#include <stdlib.h>
#include "list_itr.h"
#include "TestItr.h"



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
		List_Destroy(&list, NULL);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT BeginTest1()
{
	List* list;
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(ListItr_Begin(list) == (void*)&(list->m_tail))
	{
		List_Destroy(&list, NULL);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT BeginTest2()
{
	List* list;
	list = NULL;
	if(ListItr_Begin(list) == NULL)
	{
		List_Destroy(&list, NULL);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT EndTest1()
{
	List* list;
	list = NULL;
	if(ListItr_Begin(list) == NULL)
	{
		List_Destroy(&list, NULL);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT EndTest2()
{
	List* list;
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(ListItr_End(list) == (void*)&(list->m_tail))
	{
		List_Destroy(&list, NULL);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT EqualTest1()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[1]) == LIST_SUCCESS)
	{
		if(!ListItr_Equals(list->m_head.m_next, NULL))
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT EqualTest2()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[1]) == LIST_SUCCESS)
	{
		if(ListItr_Equals(list->m_head.m_next, list->m_tail.m_prev))
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT NextTest1()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(List_PushHead(list, &Array[1]) == LIST_SUCCESS)
		{
			if((ListItr_Next(ListItr_Begin(list))) == list->m_tail.m_prev)
			{
				return PASSED;	
			}
		}
	}
	return FAILED;
}

TEST_RESULT NextTest2()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Next(NULL) == NULL)
		{
			return PASSED;	
		}

	}
	return FAILED;
}

TEST_RESULT PrevTest1()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Prev(NULL) == NULL)
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT PrevTest2()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if((ListItr_Prev(ListItr_Begin(list))) == &(list->m_head))
		{
			return PASSED;	
		}

	}
	return FAILED;
}

TEST_RESULT GetTest1()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Get(NULL) == NULL)
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT GetTest2()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if((ListItr_Get(ListItr_Begin(list))) == &Array[0])
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT SetTest1()
{
	void* data;
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Set(NULL, data) == NULL)
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT SetTest2()
{
	void* data = NULL;
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Set(ListItr_Begin(list), data) == NULL)
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT SetTest3()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Set(ListItr_Begin(list), &Array[1]) == &Array[0])
		{
			return PASSED;	
		}
	}
	return FAILED;
}

TEST_RESULT InsertTest1()
{
	void* data;
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}

	if(ListItr_InsertBefore(NULL, data) == NULL)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT InsertTest2()
{
	void* data = NULL;
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}

	if(ListItr_InsertBefore(ListItr_Begin(list), data) == NULL)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT InsertTest3()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	void* data = &Array[3];
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}

	if(ListItr_InsertBefore(ListItr_Begin(list), data) == list->m_tail.m_prev)
	{
		return PASSED;	
	}
	
	return FAILED;
}

TEST_RESULT InsertTest4()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	void* data = &Array[3];
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_InsertBefore(ListItr_Begin(list), data) == list->m_head.m_next)
		{
			return PASSED;	
		}
	}
	
	return FAILED;
}

TEST_RESULT RemoveTest1()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}

	if(ListItr_Remove(NULL) == NULL)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT RemoveTest2()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}

	if(ListItr_Remove(ListItr_Begin(list)) == NULL)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT RemoveTest3()
{
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();
	if(list == NULL)
	{
		return FAILED;
	}
	if(List_PushHead(list, &Array[0]) == LIST_SUCCESS)
	{
		if(ListItr_Remove(ListItr_Begin(list)) == &Array[0])
		{
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
