#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
#define FATHER(i) ((i+1)/2-1)

#include "genericHeap.h"

static Vector *BuildVec(size_t size, size_t block);
int PrintInt(const void * _element,  void* _context);
int HighToLow(const void * _left, const void * _right);
int LowToHigh(const void * _left, const void * _right);
int IntEqualTo(void * _element, void* _context);
int IntBiggerThan(void * _element, void* _context);
int ChangeZero(void * _element, void* _context);
int LowestFirstDigitToHigh( void * _left,  void * _right);
int NumberOfDigitsFewToMost( void * _left,  void * _right);
/*static char *CheckIfHeap(Heap *_heap);*/

int main()
{
	Heap* heap;
	Vector* vec;
	int user_dec = 1;

	int* item;
	vec = BuildVec(100,1);
	while (1)
		{
			printf("------------------------------------:\n");
			printf("Choose:\n");
			printf("1. Create a new heap\n2. Destroy heap\n3. add data to heap\n4. find max element in heap\n5. delete max number \n6. number of items\n7. print \n8. run tests\n9.exit \n");
			scanf("%d", &user_dec);
			printf("------------------------------------:\n");
			switch (user_dec)
			{
				case 1:
					if ((heap = Heap_Build(vec,HighToLow)) != NULL)
					{
						printf("-----heap been created ---- \n");
						break;
					}	
					printf("!!!!!!!!!!!FAIL!!!!!!!!!!!!!!!!!!!!\n");

				break;

				case 2:
					printf("You choose to destroy the heap\n");
					Heap_Destroy(&heap);
				break;

				case 3:
					printf("enter a number you would like to add\n");
					item = (int*)malloc(sizeof(int));
					scanf("%d", item);
					
					if	(Heap_Insert(heap,item) == HEAP_SUCCESS)
					{	
						printf("!!!!!!!!!!!!!!!!SUCCESS!!!!!!!!!!!!!\n");
						break;
					}
					printf("!!!!!!!!!!!FAIL!!!!!!!!!!!!!!!!!!!!\n");
					break;
				
				case 4:	
					printf("Max Number is : %d\n", *(int*)Heap_Peek(heap));
					break;
			
				case 5:
					printf("Max Number is : %d\n Max number is now being delete\n", *(int*)Heap_Extract(heap));
					break;
				

				case 6:
				
					printf("the number of items in the heap is : %lu\n", Heap_Size(heap));
				
				break;

				case 7:
					Heap_ForEach(heap, PrintInt, NULL);

					break;
/*
				case 8:
				printf("%s\n", TestHeapCreate());
				printf("%s\n", TestHeapDestroy());
				printf("%s\n", TestAddData());
				printf("%s\n", TestMaxNumber());
				printf("%s\n", TestRemoveAndMax());
				printf("%s\n", TestHeapEmpty());
				break;
				case 9:
				
				return 1;
*/
			}
		}
	return 1;
}





/*************************************************/
/*************************************************/
/***************Predicate Functions***************/
/*************************************************/
/*************************************************/


int IntEqualTo(void * _element, void* _context) /*_send to _context what _element should be equal to*/
{
	if (_element == NULL || _context == NULL)
	{
		return FALSE;
	}

	if (*(int*)_element == *(int*)_context)
	{
		return TRUE;
	}
return FALSE;
}



int IntBiggerThan(void * _element, void* _context) /*find element bigger than _context*/
{
	if (_element == NULL || _context == NULL)
	{
		return FALSE;
	}
	if (*(int*)_element > *(int*)_context)
	{
		return TRUE;
	}
return FALSE;
}

/*************************************************/
/*************************************************/
/*****************Action Functions****************/
/*************************************************/
/*************************************************/

int ChangeZero(void * _element, void* _context) /*_context should be value you want to add to _element if 0*/
{
	if (_element == NULL || _context == NULL)
	{
		return FALSE;
	}
	if (*(int*)_element == 0)
	{
		*(int*)_element = *(int*)_context;
		return TRUE;
	}
return FALSE;
}

int PrintInt(const void * _element, void* _context) /*_context should be value you want to add to _element if 0*/
{
	if (_element == NULL)
	{
		return FALSE;
	}
	printf(" %d ", *(int*)_element);
return TRUE;
}


/*************************************************/
/*************************************************/
/*******************Less Fuctions*****************/
/*************************************************/
/*************************************************/


int HighToLow(const void * _left, const void * _right)
{
	int left = *(int *)_left;
	int right = *(int *)_right;
	return (left < right);
}

int LowToHigh(const void * _left, const void * _right)
{
	int left = *(int *)_left;
	int right = *(int *)_right;
	return (left > right);
}

int NumberOfDigitsFewToMost( void * _left,  void * _right)
{
	int left = *(int *)_left;
	int right = *(int *)_right;
	int leftCounter = 0;
	int rightCounter = 0;

	while(left)
	{
		left /= 10;
		leftCounter++;
	}
	while(right)
	{
		right /= 10;
		rightCounter++;
	}
	return  (leftCounter > rightCounter);
}

int LowestFirstDigitToHigh( void * _left,  void * _right)
{
	int left = *(int *)_left;
	int right = *(int *)_right;
	left = left % 10;
	right = right % 10;
	return (left > right);
}






/**************************************************/
/********** - destroy element functions - *********/
/**************************************************/


void _intElementDestroy(void* _item)
{
	if (_item == NULL)
	{
		return;
	}
	free(_item);
}


/*******************************************************************/
static Vector *BuildVec(size_t size, size_t block)
{
	Vector *vec;
	size_t i;
	int *item;

	vec = VectorCreate(size,block);
 	for (i = 0; i < size ; i++)
	{

		item = (int *)malloc(sizeof(int));
		*item = (i+1)*123 % 19;
		Vector_Append(vec, item);
	}
	printf("\nthis is the original vector - \n");
	Vector_ForEach(vec, (VectorElementAction)PrintInt,NULL);
	printf("\n");
	return vec;
}
/*
static char *CheckIfHeap(Heap *_heap)
{
	int i;
	int size = (_heap -> m_heapSize)/2 - 1;
	for(i = 0; i < size/2 - 1 ; i++)
	{
		if (FATHER(i) >= LEFT(i) && FATHER(i) >= RIGHT(i))
		{
			return "NOT HEAPED FAIL\n";
		}
	}	
	return "HEAPED CORRRECT \n";
}*/
