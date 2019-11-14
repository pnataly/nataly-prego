#include "list_itr.h"
#include "listStruct.h"
#include "genericDoubleList.h"
#include "mu_test.h"
#include <limits.h>


UNIT(create_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	free(list);	
END_UNIT


UNIT(begin_null_list)	
	List* list = NULL;	
	ASSERT_THAT(ListItr_Begin(list) == NULL);	
END_UNIT


UNIT(begin_list)	
	List* list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_Begin(list) == (void*)&(list->m_tail));	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(end_null_list)	
	List* list = NULL;	
	ASSERT_THAT(ListItr_End(list) == NULL);	
END_UNIT


UNIT(end_list)	
	List* list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_End(list) == (void*)&(list->m_tail));	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(not_equal_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[1]) == LIST_SUCCESS);	
	ASSERT_THAT(!ListItr_Equals(list->m_head.m_next, NULL));	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(equal_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[1]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Equals(list->m_head.m_next, list->m_tail.m_prev));	
	List_Destroy(&list, NULL);
END_UNIT



UNIT(next_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(List_PushHead(list, &Array[1]) == LIST_SUCCESS);	
	ASSERT_THAT((ListItr_Next(ListItr_Begin(list))) == list->m_tail.m_prev);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(next_null_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Next(NULL) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(prev_null_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Prev(NULL) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(prev_itr_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT((ListItr_Prev(ListItr_Begin(list))) == &(list->m_head));	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(get_null_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Get(NULL) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(get_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT((ListItr_Get(ListItr_Begin(list))) == &Array[0]);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(set_null_itr_list)	
	List* list;
	void* data = NULL;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Set(NULL, data) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(set_itr_list)	
	List* list;
	void* data = NULL;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Set(ListItr_Begin(list), data) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(set_itr_list2)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Set(ListItr_Begin(list), &Array[1]) == &Array[0]);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(insert_null_itr_list)	
	void* data = NULL;
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_InsertBefore(NULL, data) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(insert_null_data_itr_list)	
	void* data = NULL;
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_InsertBefore(ListItr_Begin(list), data) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(insert_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	void* data = &Array[3];
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_InsertBefore(ListItr_Begin(list), data) == list->m_tail.m_prev);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(insert_itr_list2)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	void* data = &Array[3];
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_InsertBefore(ListItr_Begin(list), data) == list->m_head.m_next);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(remove_null_itr_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_Remove(NULL) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT

UNIT(remove_null_data_itr_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(ListItr_Remove(ListItr_Begin(list)) == NULL);	
	List_Destroy(&list, NULL);
END_UNIT

UNIT(remove_itr_list)	
	List* list;
	int Array[5] = {1,2,3,4,5};
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, &Array[0]) == LIST_SUCCESS);	
	ASSERT_THAT(ListItr_Remove(ListItr_Begin(list)) == &Array[0]);	
	List_Destroy(&list, NULL);
END_UNIT


TEST_SUITE(C Unit Test Demo for mu_test!)
	TEST(create_list)
	TEST(begin_null_list)
	TEST(begin_list)	
	TEST(end_null_list)
	TEST(end_list)
	TEST(not_equal_list)	
	TEST(equal_list)
	TEST(next_itr_list)
	TEST(next_null_itr_list)
	TEST(prev_null_itr_list)
	TEST(prev_itr_list)
	TEST(get_null_itr_list)
	TEST(get_itr_list)
	TEST(set_null_itr_list)
	TEST(set_itr_list)
	TEST(set_itr_list2)
	TEST(insert_null_itr_list)
	TEST(insert_null_data_itr_list)
	TEST(insert_itr_list)
	TEST(insert_itr_list2)
	TEST(remove_null_itr_list)
	IGNORE_TEST(remove_null_data_itr_list)
	TEST(remove_itr_list)
END_SUITE




