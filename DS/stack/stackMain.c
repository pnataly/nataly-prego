#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "vector.h"



int main()
{
	int _item;
	int* _pItem = &_item;
	size_t _initialSize;
	size_t _blockSize;
	Stack* newStack;
	int result;
	int choice = 0;

while (choice != 7)
	{
		printf("*Please choose an option:\n");
		printf("1) Create stack\n");
		printf("2) Destroy stack\n");
		printf("3) Push number\n");
		printf("4) Pop number\n");
		printf("5) Stack top\n");	
		printf("6) Is stack is empty\n");
		printf("7) Exit\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
				printf("Enter the intial size:\n");
				scanf("%lu", &_initialSize);
				printf("Enter the extention block size:\n");
				scanf("%lu", &_blockSize);

				newStack = StackCreate(_initialSize,_blockSize);
				if(newStack == NULL)
				{
					printf("NULL ERROR- stack not created");
					break;
				}
			
				/*StackrPrint(newStack);*/ 
				printf("The stack is created\n");
				printf("\n");	
				break;	
			case 2:

				if(newStack == NULL)
				{
					printf("ERROR - please create a stack first\n");
					break;
				}
				
				StackDestroy(newStack);
				newStack = NULL;
				printf("Your stack has been Destroyed.\n");
				printf("\n");		
				break;
				

			case 3:

				printf("Please enter an item to add:\n");
				scanf("%d", &_item);
				result = StackPush(newStack, _item);

				if(result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- there is no stack\n");
					break;
				}
				if(result == ERR_OVERFLOW)
				{
					printf("Error over flow- cannot add another number.\n");
					break;
				}

				if(result == ERR_ALLOC_FAIL)
				{
					printf("ERROR- aloocation fail\n");
					break;
				}

				StackrPrint(newStack); 
				printf("\n");		
				break;

			case 4:
				result = StackPop(newStack, _pItem);
				if(result == ERR_UNINITINALAIZED)
				{
					printf("ERROR - please create a stack first\n");
					break;
				}
				if(result == ERR_UNDERFLOW)
				{
					printf("ERROR - the stack is empty\n");
					break;
				}
				printf("The item: %d has deleted\n", *_pItem);
				StackrPrint(newStack); 
				printf("\n");
				break;
		
			case 5:
				
				result = StackTop(newStack, _pItem);
				
				if (result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- there is no stack\n");
					break;
				}
				if(result == ERR_UNDERFLOW)
				{
					printf("The stack is empty\n");
					break;
				}
				if (result == ERR_OK)
				{
					printf("The item in the top is: %d\n", *_pItem);	
				}

				StackrPrint(newStack); 
				printf("\n");		
				break;

			case 6:
				result = StackIsEmpty(newStack);	 
				if (result == ERR_UNINITINALAIZED)
				{
					printf("ERROR- there is no stack\n");
					break;
				}
				printf("The number of items in the stack is:%d\n", _item);
				StackrPrint(newStack); 
				printf("\n");		
				break;

			case 7:
				printf("* Exit *\n");
				return 0;
			
			default:
				printf("Please enter a number between 1-7.\n");
				choice = 0;	
				printf("\n");
				break;
		}
	}

return 0;
}
