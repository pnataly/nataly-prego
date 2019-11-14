#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "genericSort.h"


static void Swap(void* _item1, void* _item2, size_t _size, char* temp)
{
	memcpy(temp, _item2, _size);
	memcpy(_item2, _item1, _size);
	memcpy(_item1, temp, _size);
}
	
static int BubbleUp (void* _elements, size_t _size, size_t _n, int(*_less)(const void*, const void*), char* temp)
{
	size_t j;
	int isSwappedUp = 0;
	void* item1;
	void* item2;

	for (j = 0; j < _n; j++)
	{ 	
		item1= _elements;
		item2 = (char*) _elements+_size;
		if(_less(item1, item2))
		{				
			Swap(item1, item2, _size, temp);
			isSwappedUp = 1;
		}	
		_elements=item2;
	}
	return isSwappedUp;
}

int BubbleSort(void* _elements, size_t _n, size_t _size, int(*_less)(const void*, const void*))
{
	int i, isSwappedUp;
	char* temp;
	
	if(_elements == NULL)
	{
		return UNITIALIZED_ERROR;
	}
	temp = (char*)malloc(sizeof(_size));
	if(temp == NULL)
	{
		return ERR_ALLOC_FAIL;
	}


	for(i=0; i<_n; i++)
	{	
		isSwappedUp = BubbleUp(_elements, _size, _n-i, _less, temp);
		
		if (!(isSwappedUp))	
		{
			break;
		} 
	}
	free(temp);
	return SORT_OK;
}
