#include <stdio.h>
#include <stdlib.h>
#include "genericVector.h"

int VectorPrint(void* _element, size_t _i, void* _context)
{
	if(_element == NULL)
	{
		return 0;
	}
	printf("%d, ", *(int*)_element);
	return 1;
} 

void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

int main()
{
	int items[20];
	int item;
	int i =0;
	int* _pItem;
	size_t index;
	size_t initialSize;
	size_t extensionBlockSize;
	size_t _numOfItems;
	Vector* newVector;
	void* pValue;
	int result;
	int choice = 0;

while (choice != 9)
	{
		printf("Please choose an option:\n");
		printf("1) Create vector\n");
		printf("2) Destroy vector\n");
		printf("3) Append to vector\n");
		printf("4) Delete from vector\n");
		printf("5) Get item\n");	
		printf("6) Set item\n");
		printf("7) Items Number\n");
		printf("8) For Each\n");
		printf("9) Exit\n");
		scanf("%d",&choice);

		switch (choice)
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
				printf("youre vector created\n");
				printf("\n");	
				break;	

			case 2:

				if(newVector == NULL)
				{
					printf("ERROR - please create vector first\n");
					break;
				}
				
				VectorDestroy(&newVector, IntDestroy);
				newVector = NULL;
				printf("Your Vector has been Destroyed.\n");
				printf("\n");		
				break;
				
			case 3:
				printf("Please enter an item to add:\n");
				scanf("%d", &items[i]);
				result = Vector_Append(newVector, &items[i++]);

				if(result == VECTOR_UNITIALIZED_ERROR)
				{
					printf("ERROR- please create vector first\n");
					break;
				}
				if(result == VECTOR_OVERFLOW_ERROR)
				{
					printf("Error- the vector is full.\n");
					break;
				}
				if(result == VECTOR_ALLOCATION_ERROR)
				{
					printf("ERROR- allocation fail\n");
					break;
				}	
				printf("The items in the vector:\n");
				index = Vector_ForEach(newVector, VectorPrint, NULL);	
				break;

			case 4:
				result = Vector_Remove(newVector,(void**)&_pItem);
				if(result == VECTOR_UNITIALIZED_ERROR)
				{
					printf("ERROR - please create vector first\n");
					break;
				}
				if(result == VECTOR_UNDERFLOW_ERROR)
				{
					printf("ERROR - the vector is empty\n\n");
					break;
				}
				if(result == VECTOR_ALLOCATION_ERROR)
				{
					printf("ERROR- allocation fail\n");
					break;
				}
				printf("the item is deleted\n");	
				printf("The items in the vector:\n");
				result = Vector_ForEach(newVector, VectorPrint, NULL);		
				break;
		
			case 5:
				printf("Enter a index of number:\n");
				scanf("%lu", &index);

				result = Vector_Get(newVector, index, (void**)&_pItem);
				
				if (result == VECTOR_UNITIALIZED_ERROR)
				{
					printf("ERROR- there is no vector\n");
					break;
				}
				if(result == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
				{
					printf("The index is out of range\n");
					break;
				}
				if (result == VECTOR_SUCCESS)
				{
					printf("The number in index %lu is: %d\n", index, items[index]);	
				}	
				break;

			case 6:
				printf("Enter a index of number:\n");
				scanf("%lu", &index);
				printf("Enter a number to set:\n");
				scanf("%d", &item);

				result = Vector_Set(newVector, index, &item);
				
				if (result == VECTOR_UNITIALIZED_ERROR)
				{
					printf("ERROR! Vector hasn't been created yet.\n");	
					break;
				}
				if(result == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
				{
					printf("The index is out of range\n");
					break;
				}

				printf("The number in index %lu is: %d\n", index, items[index]);	
				printf("The items in the vector:\n");
				result = Vector_ForEach(newVector, VectorPrint, NULL);		
				break;

			case 7:
				_numOfItems = Vector_Size(newVector);
				printf("Number of items in Vector: %ld\n", _numOfItems);		
				break;

			case 8:
				printf("The items in the vector:\n");
				result = Vector_ForEach(newVector, VectorPrint, NULL);
				break;

			case 9: 
				printf("* Exit *\n");
				return 0;	

			default:
				printf("Please enter a number between 1-9.\n");
				choice = 0;
				printf("\n");
				break;
		}
	}

return 0;
}
