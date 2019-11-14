#include <stdio.h>
#include <time.h>
#include "sort.h"
#include "ADTErr.h"
#define SIZE 100

int main()
{
	int i, result;
	Vector* newVector;
	int data;
	int choice = 0;
	
	while (choice != 8)
	{
		printf("Please choose an option:\n");
		printf("1) Bubble Sort\n");
		printf("2) Shake Sort\n");
		printf("3) Quick Sort\n");
		printf("4) Insertion Sort\n");
		printf("5) Shell Sort\n");
		printf("6) Selction Sort\n");
		printf("7) Counting Sort\n");
		printf("8) Radix Sort\n");
		printf("9) Exit\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=1; i<=SIZE; i++)
					{
						data = (rand()%20)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before Bubble sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = BubbleSort(newVector);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After Bubble sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;


			case 2:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<=SIZE; i++)
					{
						data = (rand()%20)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before Shake sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = ShakeSort(newVector);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After Shake sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;

			case 3:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<SIZE; i++)
					{
						data = (rand()%20)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}

					printf("Before Quick sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = QuickSort(newVector);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After Quick sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;
			
			case 4:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<SIZE; i++)
					{
						data = (rand()%20)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before Insertion sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = InsertionSort(newVector);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After Insertion sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;

			case 5:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<SIZE; i++)
					{
						data = (rand()%20)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before Shell sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = ShellSort(newVector);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After Shell sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;

			case 6:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<SIZE; i++)
					{
						data = (rand()%20)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before Selction sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = SelctionSort(newVector);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After Selction sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;				
	
			case 7:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<SIZE; i++)
					{
						data = (rand()%30);
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before Counting sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = CountingSort(newVector, 30);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					if(result == ERR_ALLOC_FAIL)
					{
						printf("Error allocation\n");
						break;
					}
					printf("After Counting sort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;

			case 8:
					newVector = VectorCreate(SIZE,0);
					if(newVector == NULL)
					{
						printf("NULL ERROR- vector not created");
						break;
					}
					for(i=0; i<SIZE; i++)
					{
						data = (rand()%30);
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before RadixSort sort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = RadixSort(newVector, 2);
					if(result == ERR_UNINITINALAIZED)
					{
						printf("ERROR- please create vector first\n");
						break;
					}
					if(result == ERR_EMPTY)
					{
						printf("The vector is empty\n");
						break;
					}
					printf("After RadixSort sort:\n");
					VectorPrint(newVector);
					printf("\n");
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
