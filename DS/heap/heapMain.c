#include <stdio.h>
#include "heap.h"


int main()
{
	Heap* newHeap;
	Vector* newVector;
	int data;
	int* pData = &data;
	size_t numOfItems;
	size_t* pnumOfItems = &numOfItems;
	int result;
	size_t initialSize;
	size_t extensionBlockSize;
	int choice = 0;

	while (choice != 9)
	{
		printf("*Please choose an option:\n");
		printf("1) Create Heap\n");
		printf("2) Destroy Heap\n");
		printf("3) Heap insert\n");
		printf("4) Heap Max\n");
		printf("5) Extract Heap Max\n");
		printf("6) Items Number\n");
		printf("7) Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					printf("Enter the intial size:\n");
					scanf("%lu", &initialSize);
					printf("Enter the extention block size:\n");
					scanf("%lu", &extensionBlockSize);

					newVector = VectorCreate(initialSize, extensionBlockSize);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}

					newHeap = HeapBuild(newVector);
					if(newHeap == NULL)
					{
						printf("ERROR- the Heap not created\n");
						printf("\n");	
						break;
					}
					printf("The Heap is created.\n");
					printf("\n");	
					break;

			case 2:
					if(newHeap == NULL)
					{
						printf("ERROR - please create Heap first\n");
						break;
					}
					VectorDestroy(newVector);
					HeapDestroy(newHeap);
					newHeap = NULL;
					printf("Your Heap has been Destroyed.\n");
					printf("\n");		
					break;

			case 3:
					printf("Please enter a data to insert:\n");
					scanf("%d", &data);
					result = HeapInsert(newHeap ,data);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR - please create Heap first\n");
						break;
					}
					if(result == ERR_ALLOC_FAIL)
					{
						printf("ERROR - allocation fault\n");
						break;
					}
					printf("The data is added.\n");
					HeapPrint(newHeap);
					printf("\n");		
					break;

			case 4:
					result = HeapMax(newHeap, pData);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR - please create Heap first\n");
						break;
					}
					if(result == ERR_UNDERFLOW)
					{
						printf("The heap is empty\n");
						break;
					}
					printf("The heap max is: %d\n", *pData);
					HeapPrint(newHeap);
					printf("\n");		
					break;

			case 5:
					result = HeapExtractMax(newHeap, pData);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR - please create Heap first\n");
						break;
					}
					if(result == ERR_UNDERFLOW)
					{
						printf("The heap is empty\n");
						break;
					}
					printf("The heap extract max is: %d\n", *pData);
					HeapPrint(newHeap);
					printf("\n");		
					break;

			case 6:
					result = HeapItemsNum(newHeap);
					if(result == -1)
					{
						printf("ERROR - please create Heap first\n");
						break;
					}
					if (result == ERR_UNDERFLOW)
					{
						printf("The heap is empty\n");
						break;
					}
					printf("Number of items in the heap: %ld\n", *pnumOfItems);	
					HeapPrint(newHeap);
					printf("\n");		
					break;

			case 7:
					printf("* Exit *\n");
					return 0;
		
			default:
					printf("Please enter a number between 1-7.\n");
					printf("\n");	
					choice = 0;
					break;
		}

	}
	return 0;
}
