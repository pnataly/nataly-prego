#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "ADTErr.h"


int main()
{
	/*char error[][]={};*/
	int _item;
	int* _pItem = &_item;
	size_t _index;
	size_t _initialSize;
	size_t _extensionBlockSize;
	size_t _numOfItems;
	size_t* _pnumOfItems = &_numOfItems;
	Vector* newVector;
	int result;
	int choice = 0;

while (choice != 8)
	{
		printf("Please choose an option:\n");
		printf("1) Create vector\n");
		printf("2) Destroy vector\n");
		printf("3) Add number\n");
		printf("4) Delete number\n");
		printf("5) Get item\n");	
		printf("6) Set item\n");
		printf("7) Items Number\n");
		printf("8) Exit\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:

				printf("Enter the intial size:\n");
				scanf("%lu", &_initialSize);
				printf("Enter the extention block size:\n");
				scanf("%lu", &_extensionBlockSize);

				newVector = VectorCreate(_initialSize,_extensionBlockSize);
				if(newVector == NULL)
				{
					printf("NULL ERROR- vector not created");
					break;
				}
				printf("youre vector created\n");
				printf("\n");	
				break;	
			case 2:

				if(newVector == NULL)
				{
					printf("ERROR - please create vector first\n");
					break;
				}
				
				VectorDestroy(newVector);
				newVector = NULL;
				printf("Your Vector has been Destroyed.\n");
				printf("\n");		
				break;
				
			case 3:

				printf("Please enter an item to add:\n");
				scanf("%d", &_item);
				result = VectorAdd(newVector, _item);

				if(result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- please create vector first\n");
					break;
				}
				if(result == ERR_OVERFLOW)
				{
					printf("Error- the vector is full.\n");
					break;
				}
				if(result == ERR_ALLOC_FAIL)
				{
					printf("ERROR- allocation fail\n");
					break;
				}
				VectorPrint(newVector);
				printf("\n");		
				break;

			case 4:
				result = VectorDelete(newVector, _pItem);
				if(result == ERR_UNINITINALAIZED)
				{
					printf("ERROR - please create vector first\n");
					break;
				}
				if(result == ERR_UNDERFLOW)
				{
					printf("ERROR - the vector is empty\n\n");
					break;
				}
				if(result == ERR_ALLOC_FAIL)
				{
					printf("ERROR- allocation fail\n");
					break;
				}
				printf("the item is deleted\n");
				VectorPrint(newVector);
				printf("\n");		
				break;
		
			case 5:
				printf("Enter a index of number:\n");
				scanf("%lu", &_index);

				result = VectorGet(newVector, _index, _pItem);
				
				if (result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- there is no vector\n");
					break;
				}
				if(result == ERR_ITEM_NOT_FOUND)
				{
					printf("The item not found\n");
					break;
				}
				if (result == ERR_OK)
				{
					printf("The number in index %lu is: %d\n", _index, _item);	
				}
				printf("\n");		
				VectorPrint(newVector);
				printf("\n");		
				break;

			case 6:
				printf("Enter a index of number:\n");
				scanf("%lu", &_index);
				printf("Enter a number to set:\n");
				scanf("%d", &_item);

				result = VectorSet(newVector, _index, _item);
				
				if (result == ERR_UNINITINALAIZED)
				{
					printf("ERROR! Vector hasn't been created yet.\n");	
					break;
				}
				if(result == ERR_ITEM_NOT_FOUND)
				{
					printf("The item not found\n");
					break;
				}

				printf("The number in index %lu is: %d\n", _index, _item);	
				VectorPrint(newVector);

				printf("\n");		
				break;

			case 7:
				result = VectorItemsNum(newVector, _pnumOfItems);
					
				if (result == ERR_UNDERFLOW)
				{
					printf("The vector is empty\n");
				}
				printf("Number of items in Vector: %ld\n", *_pnumOfItems);	
				VectorPrint(newVector);

				printf("\n");		
				break;

			case 8: 
				printf("* Exit *\n");
				return 0;	

			default:
				printf("Please enter a number between 1-8.\n");
				choice = 0;
				printf("\n");
				break;
		}
	}

return 0;
}
