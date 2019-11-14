#include <stdio.h>
#include <stdlib.h>
#include "genericQueue.h"
#include "queueTests.h"

void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

TEST_RESULT CreateTest1() /*check the result when we create queue with size 0. */
{
	Queue* queue;
	queue = Queue_Create(0);
	if(queue == NULL)
	{
		return PASSED;
	}
	free(queue);
	return FAILED;
}


TEST_RESULT CreateTest2() /*check the result when we create queue with big size.*/
{
	Queue* queue;
	queue = Queue_Create(10000000000);
	if(queue == NULL)
	{
		return PASSED;
	}
	Queue_Destroy(&queue, IntDestroy);
	return FAILED;
}

TEST_RESULT CreateTest3() /* create queue */
{
	Queue* queue;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		Queue_Destroy(&queue, IntDestroy);
		return PASSED;
	}
	return FAILED;
}
TEST_RESULT DestroyTest1() /*destroy queue */
{
	Queue* queue;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		Queue_Destroy(&queue, IntDestroy);
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT DestroyTest2() /*double destroy */
{
	Queue* queue;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		Queue_Destroy(&queue, IntDestroy);
		Queue_Destroy(&queue, IntDestroy);
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT IsEmptyTest1() /*heck the result when we create empty queue and check if the queue is empty. */
{
	Queue* queue;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		if(Queue_IsEmpty(queue))
		{
			Queue_Destroy(&queue, IntDestroy);
			return PASSED;
		}
	}	
	return FAILED;
}


TEST_RESULT IsEmptyTest2() /*check the result when we insert number to queue and check if the queue is empty. */
{
	Queue* queue;
	int array[5]= {1,2,3,4,5};
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		if(Queue_Enqueue(queue, &array[0]) == QUEUE_SUCCESS)
		{
			if(!Queue_IsEmpty(queue))
			{
				Queue_Destroy(&queue, NULL);
				return PASSED;
			}
		}
	}	
	return FAILED;
} 


TEST_RESULT InsertTest1() /* check the result when we insert numbers to queue. */
{
	Queue* queue;
	int array[5]= {1,2,3,4,5};
	queue = Queue_Create(3);
	if(queue != NULL)
	{
		if(Queue_Enqueue(queue, &array[0]) == QUEUE_SUCCESS)
		{
			Queue_Destroy(&queue, NULL);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT InsertTest2() /*check the result when we destroy queue and try to insert number to the destroy queue. */
{
	Queue* queue;
	int array[5]= {1,2,3,4,5};
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		Queue_Destroy(&queue, IntDestroy);
		if(Queue_Enqueue(queue, &array[0]) == QUEUE_UNINITIALIZED_ERROR)
		{
			Queue_Destroy(&queue, NULL);
			return PASSED;
		}
	}
	return FAILED;
}


TEST_RESULT InsertTest3() /*check the result when we insert number when the queue is full. */
{
	Queue* queue;
	int array[5]= {1,2,3,4,5};
	int count = 0;
	int i = 0;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		while(i<5)
		{
			if(Queue_Enqueue(queue, &array[0]) == QUEUE_SUCCESS)
			{
				count++;
			}
			i++;
		}
		if(count == 5)
		{
			if(Queue_Enqueue(queue, &array[1]) == QUEUE_OVERFLOW)
			{
				Queue_Destroy(&queue, NULL);
				return PASSED;
			}
		}
		
	}
	return FAILED;
}

TEST_RESULT InsertTest4() /*check the result when item is NULL. */
{
	Queue* queue;
	int count = 0;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		if(Queue_Enqueue(queue, NULL) == QUEUE_NULL_ELEMENT_ERROR)
		{
			Queue_Destroy(&queue, NULL);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT RemoveTest1() /*check the result when remove item from queue */
{
	Queue* queue;
	int array[5]= {1,2,3,4,5};
	int* pItem ;
	queue = Queue_Create(3);
	if(queue != NULL)
	{
		if(Queue_Enqueue(queue, &array[1]) == QUEUE_SUCCESS)
		{
			if(Queue_Dequeue(queue, (void**)&pItem) == QUEUE_SUCCESS)
			{
				Queue_Destroy(&queue, NULL);
				return PASSED;
			}
		}
	}
	return FAILED;
}


TEST_RESULT RemoveTest2() /*check the result when we remove from empty queue */
{
	Queue* queue;
	int* pItem;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		if(Queue_Dequeue(queue, (void**)&pItem) == QUEUE_UNDERFLOW)
		{
			Queue_Destroy(&queue, NULL);
			return PASSED;
		}
	}
	return FAILED;
}


TEST_RESULT RemoveTest3() /*check the result when item is NULL*/
{
	Queue* queue;
	int* pItem;
	queue = Queue_Create(5);
	if(queue != NULL)
	{
		if(Queue_Dequeue(queue, NULL) == QUEUE_NULL_ELEMENT_ERROR)
		{
			Queue_Destroy(&queue, NULL);
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


