#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "ADTErr.h"



int MaxSort(int _num1, int _num2)
{
	if (_num1 > _num2)
	{
		return TRUE;
	}
	return FALSE;
}

int MinSort(int _num1, int _num2)
{
	if (_num1 < _num2)
	{
		return TRUE;
	}
	return FALSE;
}

int LastDigitSort(int _num1, int _num2)
{
	int i, j;
	i = _num1%10;
	j = _num2%10;
	if(i > j)
	{
		return TRUE;
	}
	return FALSE;
}

static int BubbleUp (Vector* _vec, size_t _end, int (*funcSort)(int, int))
{
	int j;
	int isSwappedUp = 0;
	int item1 = 0;
	int item2 = 0;
	
	for (j = 0; j < _end-1; j++)
	{ 	
		VectorGet(_vec, j, &item1);
		VectorGet(_vec, j+1, &item2);
		if(funcSort(item1, item2))
		{				
			VectorSet(_vec, j, item2);
			VectorSet(_vec, j+1, item1);
			isSwappedUp = 1;
		}	
	}
	return isSwappedUp;
}


ADTErr BubbleSort(Vector* _vec, int (*funcSort)(int, int))
{
	int i, isSwappedUp;
	size_t numOfItems;
	if(_vec == NULL)
	{
		return ERR_UNINITINALAIZED;
	}
	VectorItemsNum(_vec, &numOfItems);

	if(numOfItems == 0)
	{
		return ERR_EMPTY;
	}
	if(numOfItems == 1)
	{
		return ERR_OK;
	}
	for(i=0; i<=numOfItems; i++)
	{	
		isSwappedUp = BubbleUp(_vec, numOfItems, funcSort);
		
		if (!(isSwappedUp))	
		{
			break;
		} 
	}
	return ERR_OK;
}


