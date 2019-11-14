#include <stdio.h>
#include <stdlib.h>
#include "genericDoubleList.h"

void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}


int main()
{

	List* newList;
	int items[20];
	int i=0;
	int item;
	int* Pdata;
	int result;
	size_t count;
	int choice = 0;
	while (choice != 9)
	{
		printf("*Please choose an option:\n");
		printf("1) Create double list\n");
		printf("2) Destroy double list\n");
		printf("3) Push to list head\n");
		printf("4) Push to list tail\n");
		printf("5) Pop from list head\n");
		printf("6) Pop from list tail\n");
		printf("7) Count items\n");
		printf("8) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				newList = List_Create();
				if(newList == NULL)
				{
					printf("NULL ERROR- double list not created\n");
					break;
				}
				printf("The double list is created.\n");
				printf("\n");	
				break;

			case 2:
				if(newList == NULL)
				{
					printf("ERROR - please create a double list first\n");
					printf("\n");	
					break;
				}
			
				List_Destroy(&newList, NULL);
				newList = NULL;
				printf("Your double list has been Destroyed.\n");
				printf("\n");		
				break;
		
			case 3:
				printf("Please enter a number to push to the list:\n");
				scanf("%d", &items[i]);
				result= List_PushHead(newList, &items[i++]);
				if(result == LIST_UNINITIALIZED_ERROR)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(result == LIST_NULL_ELEMENT_ERROR)
				{
					printf("ERROR - the item is invalid\n");
					break;
				}
				if(result == LIST_ALLOCATION_ERROR)
				{
					printf("ERROR - allocation fault\n");
					break;
				}
				printf("the data has been added.\n");
				ListPrint(newList);
				printf("\n");		
				break;

			case 4:
				printf("Please enter a number to push to the list:\n");
				scanf("%d", &items[i]); 
				result= List_PushTail(newList, &items[i++]);
				if(result == LIST_UNINITIALIZED_ERROR)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(result == LIST_NULL_ELEMENT_ERROR)
				{
					printf("ERROR - the item is invalid\n");
					break;
				}
				if(result == LIST_ALLOCATION_ERROR)
				{
					printf("ERROR - allocation fault\n");
					break;
				}
				printf("the data has been added.\n");
				ListPrint(newList);
				printf("\n");		
				break;


			case 5:
				result = List_PopHead(newList, (void*)&Pdata);
				if(result == LIST_UNINITIALIZED_ERROR)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(result == LIST_UNDERFLOW_ERROR)
				{
					printf("ERROR - the list is empty\n");
					break;
				}
				if(result == LIST_NULL_ELEMENT_ERROR)
				{
					printf("ERROR - the item is invalid\n");
					break;
				}
				printf("the data: %d has been removed.\n", *Pdata);
				ListPrint(newList);
				printf("\n");		
				break;

			case 6:
				result = List_PopTail(newList, (void*)&Pdata);
				if(result == LIST_UNINITIALIZED_ERROR)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(result == LIST_UNDERFLOW_ERROR)
				{
					printf("ERROR - the list is empty\n");
					break;
				}
				if(result == LIST_NULL_ELEMENT_ERROR)
				{
					printf("ERROR - the item is invalid\n");
					break;
				}
				printf("the data: %d has been removed.\n", *Pdata);
				ListPrint(newList);
				printf("\n");		
				break;


			case 7:
				count = List_Size(newList);
				if(count == 0)
				{
					printf("ERROR- double list not created\n");
					break;
				}
				printf("There is %ld items in the list.\n", count);
				break;


			case 8:
				printf("* Exit *\n");
				return 0;
		
			default:
				printf("Please enter a number between 1-8.\n");
				printf("\n");	
				choice = 0;				
				break;
		}
	}

	return 0;
}
