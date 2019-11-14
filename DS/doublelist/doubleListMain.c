#include <stdio.h>
#include <stdlib.h>
#include "doubleList.h"


int main()
{

	List* _newList;
	int _data;
	int* _pdata= &_data;
	int _result;
	size_t _count;
	int choice = 0;
	_newList = NULL;
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
		printf("8) Is list empty\n");
		printf("9) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				_newList = ListCreate();
				if(_newList == NULL)
				{
					printf("NULL ERROR- double list not created\n");
					break;
				}
				printf("The double list is created.\n");
				printf("\n");	
				break;

			case 2:
				if(_newList == NULL)
				{
					printf("ERROR - please create a double list first\n");
					printf("\n");	
					break;
				}
			
				ListDestroy(_newList);
				_newList = NULL;
				printf("Your double list has been Destroyed.\n");
				printf("\n");		
				break;
		
			case 3:
				printf("Please enter a number to push to the list:\n");
				scanf("%d", &_data);
				_result= ListPushHead(_newList, _data);
				if(_result == ERR_UNINITINALAIZED)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(_result == ERR_NO_MEMORY)
				{
					printf("ERROR - no memory\n");
					break;
				}
				printf("the number has been added.\n");
				ListPrint(_newList);
				printf("\n");		
				break;

			case 4:
				printf("Please enter a number to push to the list:\n");
				scanf("%d", &_data); 
				_result= ListPushTail(_newList, _data);
				if(_result == ERR_UNINITINALAIZED)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(_result == ERR_NO_MEMORY)
				{
					printf("ERROR - no memory\n");
					break;
				}
				printf("the data has been added.\n");
				ListPrint(_newList);
				printf("\n");		
				break;


			case 5:
				_result = ListPopHead(_newList, _pdata);
				if(_result == ERR_UNINITINALAIZED)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(_result == ERR_UNDERFLOW)
				{
					printf("ERROR - the list is empty\n");
					break;
				}
				printf("the data: %d has been removed.\n", *_pdata);
				ListPrint(_newList);
				printf("\n");		
				break;

			case 6:
				_result = ListPopTail(_newList, _pdata);
				if(_result == ERR_UNINITINALAIZED)
				{
					printf("ERROR - please create a double list first\n");
					break;
				}
				if(_result == ERR_UNDERFLOW)
				{
					printf("ERROR - the list is empty\n");
					break;
				}
				printf("the data: %d has been removed.\n", *_pdata);
				ListPrint(_newList);
				printf("\n");		
				break;


			case 7:
				_count = ListCountItems(_newList);
				if(_count == 0)
				{
					printf("ERROR- double list not created\n");
					break;
				}
				printf("There is %ld items in the list.\n", _count);
				break;

			case 8:
				_result = ListIsEmpty(_newList);
				if(_result)
				{
					printf("The list is empty\n");
					printf("\n");	
					break;
				}
				printf("The list is not empty\n");
				printf("\n");	
				ListPrint(_newList);
				printf("\n");	
				break;

			case 9:
				printf("* Exit *\n");
				return 0;
		
			default:
				printf("Please enter a number between 1-9.\n");
				printf("\n");	
				choice = 0;
						
				printf("\n");
				break;

		}
	}

	return 0;
}
