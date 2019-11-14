#include <stdio.h>
#include "sort.h"
#include "ADTErr.h"
#define SIZE 20

int MaxSort(int _num1, int _num2);

int MinSort(int _num1, int _num2);

int LastDigitSort(int _num1, int _num2);

int main()
{
	int i, result;
	Vector* newVector;
	int data;
	int choice = 0;
	int (*funcSort)(int, int);
	int (*funcSortArray[])(int, int) = {MaxSort, MinSort, LastDigitSort};


	while (choice != 3)
	{
		printf("Please choose an option:\n");
		printf("1) MaxSort\n");
		printf("2) MinSort\n");
		printf("3) LastDigitSort\n");
		printf("4) Exit\n");
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
						data = (rand()%40)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before  MaxSort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = BubbleSort(newVector, funcSortArray[0]);
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
					printf("After MaxSort:\n");
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
					for(i=1; i<=SIZE; i++)
					{
						data = (rand()%40)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before  MinSort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = BubbleSort(newVector, funcSortArray[1]);
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
					printf("After MinSort:\n");
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
					for(i=1; i<=SIZE; i++)
					{
						data = (rand()%40)+1;
						result = VectorAdd(newVector, data);
						if(result != ERR_OK)
						{
							break;
						}
					}
					printf("Before  LastDigitSort:\n");
					VectorPrint(newVector);
					printf("\n");
					result = BubbleSort(newVector, funcSortArray[2]);
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
					printf("After LastDigitSort:\n");
					VectorPrint(newVector);
					printf("\n");
					break;
		}
	}
	return 0;
}
