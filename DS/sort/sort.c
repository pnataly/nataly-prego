#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "ADTErr.h"


static int BubbleUp (Vector* _vec, size_t _start, size_t _end)
{
	int j;
	int isSwappedUp = 0;
	int item1 = 0;
	int item2 = 0;
	
	for (j = 0; j < _end-1; j++)
	{ 	
		VectorGet(_vec, j, &item1);
		VectorGet(_vec, j+1, &item2);
		if (item1 > item2)
		{				
			VectorSet(_vec, j, item2);
			VectorSet(_vec, j+1, item1);
			isSwappedUp = 1;
		}	
	}
	return isSwappedUp;
}

static int BubbleDown(Vector* _vec, size_t _start, size_t _end)
{
	int j;
	int isSwappedDown = 0;
	int item1 = 0;
	int item2 = 0;
	
	for(j=_end-1; j> 0; j--)
	{
		VectorGet(_vec, j, &item1);
		VectorGet(_vec, j-1, &item2);
		if (item1 < item2)
		{		
			VectorSet(_vec, j, item2);
			VectorSet(_vec, j-1 ,item1);						
			isSwappedDown = 1;
		}
	}
	return isSwappedDown;
}

ADTErr BubbleSort(Vector* _vec)
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
		isSwappedUp = BubbleUp(_vec, i, numOfItems);
		
		if (!(isSwappedUp))	
		{
			break;
		} 
	}
	return ERR_OK;
}


ADTErr ShakeSort(Vector* _vec)
{
	int i, isSwappedUp, isSwappedDown;
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
	for(i=0; i<numOfItems; i++)
	{	
		isSwappedUp = BubbleUp(_vec, i, numOfItems);
		isSwappedDown = BubbleDown(_vec, i, numOfItems);

		if((!(isSwappedUp)) && (!(isSwappedDown)))	
		{
			break;
		} 
	}
	return ERR_OK;
}


static size_t Partition(Vector* _vec, size_t _begin, size_t _end)
{
	int pivotVal;
	int low, high;
	size_t pivotIndex =  _begin;
	VectorGet(_vec, pivotIndex, &pivotVal);
	_begin++;

	while(_begin <= _end)
	{
		VectorGet(_vec, _begin, &low);
		VectorGet(_vec, _end, &high);


		while(low <= pivotVal && _begin < _end)
		{
			_begin++;
			VectorGet(_vec, _begin, &low);
		}
		while(high > pivotVal)
		{
			_end--;
			VectorGet(_vec, _end, &high);
		}
		if(_begin <= _end)
		{
			VectorSet(_vec, _begin, high);
			VectorSet(_vec, _end, low);
			_begin++;
		}
	}
	VectorSet(_vec, pivotIndex, high);
	VectorSet(_vec, _end, pivotVal);
	return _end;
}


static void QuickRec(Vector* _vec, size_t _begin, size_t _end)
{
	size_t index;
	if(_begin >= _end)
	{
		return;
	}
	index = Partition(_vec, _begin, _end);
	QuickRec(_vec, _begin, index-1);
	QuickRec(_vec, index+1, _end);
}

ADTErr QuickSort(Vector* _vec)
{
	size_t numOfItems;
	size_t begin = 0;
	size_t end;
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
	end = numOfItems-1;
	QuickRec(_vec, begin, end);
	return ERR_OK;
}

static void Insertion(Vector* _vec,	size_t _numOfItems, size_t _gap)
{
	size_t i;
	int item1, item2, isSwappedDown;
	for(i=0; i<_numOfItems-1; i+=_gap)
	{
		VectorGet(_vec, i, &item1);
		VectorGet(_vec, i+1, &item2);
		if(item1 > item2)
		{
			isSwappedDown = BubbleDown(_vec, 0, i+2);
			if(!isSwappedDown)
			{
				break;
			}
		}
	}
	return;
} 

ADTErr InsertionSort(Vector* _vec)
{
	size_t numOfItems, gap;
	gap = 1;
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
	Insertion(_vec, numOfItems, gap);
	
	return ERR_OK;
}


ADTErr ShellSort(Vector* _vec)
{
	size_t gap, i;
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

	for(gap=numOfItems/2; gap>0; gap=gap/2)
	{
		for(i=gap; i<numOfItems/4; i++)
		{
			Insertion(_vec, numOfItems, gap);
		}
	}
	return ERR_OK;
}



static size_t FindMin(Vector* _vec, size_t _start, size_t _end)
{
	int item1, minVal;
	size_t i, minIndex;
	minIndex = _start;
	_start++;
	for(i=_start; i<_end; i++)
	{
		VectorGet(_vec, minIndex, &minVal);
		VectorGet(_vec, i, &item1);
		if(item1 < minVal)
		{
			minIndex = i;
		}		
	}
	return minIndex;
}

ADTErr SelctionSort(Vector* _vec)
{
	size_t numOfItems, minIndex, i;
	int minVal, item;
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

	for(i=0; i<numOfItems-1; i++)
	{
		VectorGet(_vec, i, &item);
		minIndex = FindMin(_vec,i, numOfItems);
		VectorGet(_vec, minIndex, &minVal);

		VectorSet(_vec, i, minVal);
		VectorSet(_vec, minIndex, item);
	}
	return ERR_OK;
}


ADTErr CountingSort(Vector* _vec, int m_maxValue)
{
	size_t numOfItems, i;
	int* output;
	int* frequency;
	int item;
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
	output = (int*) calloc(sizeof(int), numOfItems);
	if(output == NULL)
	{
		return ERR_ALLOC_FAIL;
	}
	frequency = (int*) malloc(sizeof(int)*m_maxValue);
	if(frequency == NULL)
	{
		return ERR_ALLOC_FAIL;
	}
	for(i=0; i<numOfItems; i++)
	{
		VectorGet(_vec, i, &item);
		frequency[item]++;
	}

	for(i=0; i<m_maxValue; i++)
	{
		frequency[i+1] += frequency[i];
	}
	for(i=0; i<numOfItems; i++)
	{
		VectorGet(_vec, i, &item);
		output[frequency[item]-1] = item;
		frequency[item]--;
	}
	
	for(i=0; i<numOfItems; i++)
	{
		VectorSet(_vec, i, output[i]);
	}

	return ERR_OK;
}

static void Counting(Vector* _vec, int _exp, size_t _numOfItems)
{
	size_t i;
	int* output;
	int* frequency;
	int item;

	output = (int*) calloc(sizeof(int), _numOfItems);
	if(output == NULL)
	{
		return;
	}
	frequency = (int*) malloc(sizeof(int)*10);
	if(frequency == NULL)
	{
		return;
	}
	for(i=0; i<_numOfItems; i++)
	{
		VectorGet(_vec, i, &item);
		frequency[(item/_exp)%10]++;
	}

	for(i=0; i<10; i++)
	{
		frequency[i+1] += frequency[i];
	}
	for(i=0; i<_numOfItems; i++)
	{
		VectorGet(_vec, i, &item);
		output[frequency[(item/_exp)%10]-1] = item;
		frequency[(item/_exp)%10]--;
	}
	
	for(i=0; i<_numOfItems; i++)
	{
		VectorSet(_vec, i, output[i]);
	}
}

ADTErr RadixSort(Vector* _vec, int _nDigits)
{
	size_t numOfItems;
	int i;
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
	for(i=1; (_nDigits/i)>0; i = i*10)
	{
		Counting(_vec, i, numOfItems);
	}
	return ERR_OK;
}
