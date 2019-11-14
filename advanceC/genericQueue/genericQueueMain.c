#include <stdio.h>
#include <stdlib.h>
#include "genericQueue.h"


void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

int QueuePrint(void* _element, size_t _index, void* _context)
{
	if(_element == NULL)
	{
		return 0;
	}
	printf("%d, ",*(int*)_element);
	return 1;
} 

int main()
{
	Queue* newQueue;
	int items[20];
	int i=0;
	int* pItem;
	size_t size;
	int result;
	size_t count;
	int choice = 0;
	newQueue = NULL;


	while (choice != 7)
	{
		printf("*Please choose an option:\n");
		printf("1) Create queue\n");
		printf("2) Destroy queue\n");
		printf("3) Insert number to queue\n");
		printf("4) Remove number from queue\n");	
		printf("5) Check if Queue is Empty\n");
		printf("6) For Each\n");
		printf("7) Exit\n");
		scanf("%d",&choice);

		switch (choice)
		{

			case 1:
				printf("Enter the size:\n");
				scanf("%lu", &size);
				newQueue=Queue_Create(size);
				if(newQueue == NULL)
				{
					printf("NULL ERROR- queue not created\n");
					break;
				}
				printf("The queue is created.\n");
				printf("\n");	
				break;

			case 2:
				if(newQueue == NULL)
				{
					printf("ERROR - please create a queue first\n");
					printf("\n");	
					break;
				}
				
				Queue_Destroy(&newQueue, NULL);
				newQueue = NULL;
				printf("Your queue has been Destroyed.\n");
				printf("\n");		
				break;

			case 3:
				printf("Please enter an item to insert:\n");
				scanf("%d", &items[i]);
				result = Queue_Enqueue(newQueue, &items[i++]);
				if(result == QUEUE_UNINITIALIZED_ERROR)
				{
					printf("ERROR- queue not created\n");
					printf("\n");	
					break;
				}
				if(result == QUEUE_OVERFLOW)
				{
					printf("ERROR- there is no room in queue\n");
					printf("\n");	
					break;
				}
				if(result == QUEUE_NULL_ELEMENT_ERROR)
				{
					printf("ERROR- item is NULL\n");
					printf("\n");	
					break;
				}
				printf("The item has been added\n");	
				break;
			
			case 4:
				result = Queue_Dequeue(newQueue, (void*)&pItem);
				if(result == QUEUE_UNINITIALIZED_ERROR)
				{
					printf("ERROR- queue not created\n");
					printf("\n");	
					break;
				}
				if(result == QUEUE_UNDERFLOW)
				{
					printf("ERROR- the queue is empty\n");
					printf("\n");	
					break;
				}
				if(result == QUEUE_NULL_ELEMENT_ERROR)
				{
					printf("ERROR- pItem is NULL\n");
					printf("\n");	
					break;
				}
				printf("The item: %d is removed\n", *pItem);
				break;

			case 5:
				result = Queue_IsEmpty(newQueue);
				if(result)
				{
					printf("The queue is empty\n");
					printf("\n");	
					break;
				}
				printf("The queue is not empty\n");
				break;
			
			case 6:
				printf("The items in the Queue:\n");
				count = Queue_ForEach(newQueue, QueuePrint, NULL);
				printf("\n");	
				break;
			case 7:
				printf("* Exit *\n");
				return 0;
			
			default:
				printf("Please enter a number between 1-7.\n");
				printf("\n");	
				choice = 0;
						
				printf("\n");
				break;
		}
	}
	return 0;
}




