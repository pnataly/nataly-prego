#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main()
{
	int _item;
	int* _pItem= &_item;
	size_t _size;
	Queue* newQueue;
	int result;
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
		printf("6) Exit\n");
		scanf("%d",&choice);

		switch (choice)
		{

			case 1:
				printf("Enter the size:\n");
				scanf("%lu", &_size);
				newQueue = QueueCreate(_size);
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
				
				QueueDestroy(newQueue);
				newQueue = NULL;
				printf("Your queue has been Destroyed.\n");
				printf("\n");		
				break;

			case 3:
				printf("Please enter an item to insert:\n");
				scanf("%d", &_item);
				result = QueueInsert(newQueue, _item);
				if(result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- queue not created\n");
					printf("\n");	
					break;
				}
				if(result == ERR_OVERFLOW)
				{
					printf("ERROR- there is no room in queue\n");
					printf("\n");	
					break;
				}
				printf("The item has been added\n");
				printf("\n");	
				PrintQueue(newQueue);
				printf("\n");	
				break;
			
			case 4:
				result = QueueRemove(newQueue, _pItem);
				if(result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- queue not created\n");
					printf("\n");	
					break;
				}
				if(result == ERR_EMPTY)
				{
					printf("ERROR- the queue is empty\n");
					printf("\n");	
					break;
				}

				printf("The item: %d is removed\n", *_pItem);
				printf("\n");	
				PrintQueue(newQueue);
				printf("\n");	
				break;

			case 5:
				result = IsEmptyQueue(newQueue);
				if(result)
				{
					printf("The queue is empty\n");
					printf("\n");	
					break;
				}
				printf("The queue is not empty\n");
				printf("\n");	
				PrintQueue(newQueue);
				printf("\n");	
				break;

			case 6:
				printf("* Exit *\n");
				return 0;
			
			default:
				printf("Please enter a number between 1-6.\n");
				printf("\n");	
				choice = 0;
						
				printf("\n");
				break;
		}
	}
	return 0;
}




