#include "genericDoubleList.h"
#include "mu_test.h"
#include <limits.h>

/************************/
/* functions under test */

void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

/************************/

UNIT(create_list)	
	List* list;
	list = List_Create();
	ASSERT_THAT(list != NULL);	
	free(list);	
END_UNIT


UNIT(push_head_to_null_list)	
	List* list = NULL;
	int array[2]= {1,2};

	ASSERT_THAT(List_PushHead(list, &array[0]) == LIST_UNINITIALIZED_ERROR);	
END_UNIT



UNIT(push_head_item_null_to_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushHead(list, NULL) == LIST_NULL_ELEMENT_ERROR);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(push_head_to_list)	
	List* list;
	int array[2]= {1,2};
	list = List_Create();

	ASSERT_THAT(list != NULL);
	
	ASSERT_THAT(List_PushHead(list, &(array[0])) == LIST_SUCCESS);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(push_tail_to_null_list)	
	List* list = NULL;
	int array[2]= {1,2};

	ASSERT_THAT(List_PushTail(list, &array[0]) == LIST_UNINITIALIZED_ERROR);	
END_UNIT


UNIT(push_tail_item_null_to_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PushTail(list, NULL) == LIST_NULL_ELEMENT_ERROR);	
	List_Destroy(&list, NULL);
END_UNIT



UNIT(push_tail_to_list)	
	List* list;
	int array[2]= {1,2};
	list = List_Create();

	ASSERT_THAT(list != NULL);
	
	ASSERT_THAT(List_PushTail(list, &(array[0])) == LIST_SUCCESS);	
	List_Destroy(&list, NULL);
END_UNIT


UNIT(pop_from_head_null_list)	
	List* list = NULL;
	int* Pdata;
	
	ASSERT_THAT(List_PopHead(list, (void*)&Pdata) == LIST_UNINITIALIZED_ERROR);	
END_UNIT


UNIT(pop_head_item_null_from_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PopHead(list, NULL) == LIST_NULL_ELEMENT_ERROR);	
	List_Destroy(&list, NULL);
END_UNIT

UNIT(pop_head_from_empty_list)	
	List* list;
	int* Pdata;
	list = List_Create();

	ASSERT_THAT(list != NULL);
	ASSERT_THAT(List_PopHead(list, (void*)&Pdata) == LIST_UNDERFLOW_ERROR);	
	List_Destroy(&list, NULL);	
END_UNIT


UNIT(pop_head_from_list)	
	List* list;
	int* Pdata;
	int array[2]= {1,2};
	list = List_Create();

	ASSERT_THAT(list != NULL);
	ASSERT_THAT(List_PushTail(list, &(array[0])) == LIST_SUCCESS);
	ASSERT_THAT(List_PopHead(list, (void*)&Pdata) == LIST_SUCCESS);
	List_Destroy(&list, NULL);	
END_UNIT


UNIT(pop_from_tail_null_list)	
	List* list = NULL;
	int* Pdata;
	
	ASSERT_THAT(List_PopTail(list, (void*)&Pdata) == LIST_UNINITIALIZED_ERROR);	
END_UNIT

UNIT(pop_tail_item_null_from_list)	
	List* list;
	list = List_Create();

	ASSERT_THAT(list != NULL);	
	ASSERT_THAT(List_PopTail(list, NULL) == LIST_NULL_ELEMENT_ERROR);	
	List_Destroy(&list, NULL);
END_UNIT

UNIT(pop_tail_from_empty_list)	
	List* list;
	int* Pdata;
	list = List_Create();

	ASSERT_THAT(list != NULL);
	ASSERT_THAT(List_PopTail(list, (void*)&Pdata) == LIST_UNDERFLOW_ERROR);	
	List_Destroy(&list, NULL);	
END_UNIT

UNIT(pop_tail_from_list)	
	List* list;
	int* Pdata;
	int array[2]= {1,2};
	list = List_Create();

	ASSERT_THAT(list != NULL);
	ASSERT_THAT(List_PushTail(list, &(array[0])) == LIST_SUCCESS);
	ASSERT_THAT(List_PopTail(list, (void*)&Pdata) == LIST_SUCCESS);
	List_Destroy(&list, NULL);	
END_UNIT


UNIT(list_null_size)	
	List* list = NULL;
	ASSERT_THAT(List_Size(list) == 0);
END_UNIT


UNIT(list_size)	
	List* list;
	int array[2]= {1,2};
	list = List_Create();

	ASSERT_THAT(list != NULL);
	ASSERT_THAT(List_PushTail(list, &(array[0])) == LIST_SUCCESS);
	ASSERT_THAT(List_Size(list) == 1);
	List_Destroy(&list, NULL);	
END_UNIT



TEST_SUITE(C Unit Test Demo for mu_test!)
	TEST(create_list)
	TEST(push_head_to_null_list)
	TEST(push_head_item_null_to_list)	
	TEST(push_head_to_list)
	TEST(push_tail_to_null_list)
	TEST(push_tail_item_null_to_list)	
	TEST(push_tail_to_list)
	TEST(pop_from_head_null_list)
	TEST(pop_head_item_null_from_list)
	TEST(pop_head_from_empty_list)
	TEST(pop_head_from_list)
	TEST(pop_from_tail_null_list)
	TEST(pop_tail_item_null_from_list)
	TEST(pop_tail_from_empty_list)
	TEST(pop_tail_from_list)
	TEST(list_null_size)
	TEST(list_size)
END_SUITE




