#include <string.h>
#include <stdio.h>
#include "genericSort.h"


static int MaxSort(const void* _num1, const void* _num2)
{
	int *a = (int*)_num1;
	int *b = (int*)_num2;
	if (*a > *b)
	{
		return TRUE;
	}
	return FALSE;
}

static int CharSort(const void* _str1, const void* _str2)
{
    char *a = (char *)_str1;
    char *b = (char *)_str2;
    if(strcmp(a, b) > 0)
	{
		return FALSE;
	}
	return TRUE;
}

int main()
{
	int i;
	int choice = 0;
	int (*funcSort)(const void*, const void*);
	int (*funcSortArray[])(const void*, const void*) = {MaxSort, CharSort};
	int arrayInt[7]= {12,1,5,2,8,6,3};
	char arrayChar[7] = {'c', 'f', 'a', 'n', 'b', 'u', 'd'};

	while (choice != 3)
	{
		printf("Please choose an option:\n");
		printf("1) int Sort\n");
		printf("2) char Sort\n");
		printf("3) Exit\n");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
					printf("Before sort:\n");
					for(i=0; i<7; i++)
					{
						printf("%d, ", arrayInt[i]);
					}
					printf("\n");
					BubbleSort(arrayInt, 7, sizeof(int), funcSortArray[0]);
					printf("After sort:\n");
					for(i=0; i<7; i++)
					{
						printf("%d, ", arrayInt[i]);
					}
					printf("\n");
					break;

			case 2:

					printf("Before sort:\n");
					for(i=0; i<7; i++)
					{
						printf("%c, ", arrayChar[i]);
					}
					printf("\n");
					BubbleSort(arrayChar, 7, sizeof(char), funcSortArray[1]);
					printf("After Sort:\n");
					for(i=6; i>=0; i--)
					{
						printf("%c, ", arrayChar[i]);
					}
					printf("\n");
					break;

			case 3:
					printf("Exit\n");
					return 0;
		}
	}
	return 0;
}
