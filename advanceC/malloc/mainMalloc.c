#include <stdio.h>
#include <stdlib.h>

#include "memmalloc.h"
#define SIZE_ARR 1000
#define SIZE_PTR1 133
#define SIZE_PTR2 230
#define SIZE_PTR3 55
int main()
{
	int* arr;
	int* startbuff; 
	int* ptr1;
	int* ptr2;
	int* ptr3;
	
	arr = (int*)malloc(SIZE_ARR*sizeof(int));
	startbuff = memInit(arr,SIZE_ARR);
	if (startbuff == NULL)
	{
		printf("allocation error\n");
	}
	ptr1 = memMalloc(startbuff,SIZE_PTR1);
	if (ptr1 == NULL)
	{
		printf("allocation error\n");
	}
	ptr2 = memMalloc(startbuff,SIZE_PTR2);
	if (ptr2 == NULL)
	{
		printf("allocation error\n");
	}
	ptr3 = memMalloc(startbuff,SIZE_PTR3);
	if (ptr3 == NULL)
	{
		printf("allocation error\n");
	}
	mallocForEach(startbuff);
	memFree(ptr3);
	printf("after free ptr 3\n");
	mallocForEach(startbuff);
	memFree(ptr2);
	printf("after free ptr 2\n");	
	mallocForEach(startbuff);
	ptr2 = memMalloc(startbuff,SIZE_PTR2);
	if (ptr2 == NULL)
	{
		printf("allocation error\n");
	}
	printf("after allocate ptr 2\n");	
	mallocForEach(startbuff);
	memFree(ptr2);
	memFree(ptr1);
	printf("after free all\n");	
	mallocForEach(startbuff);
	
	return 0;
}	
