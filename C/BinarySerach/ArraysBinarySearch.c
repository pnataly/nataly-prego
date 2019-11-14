# include <stdio.h>
# include <stdlib.h>
# include "ArraysBinarySearch.h"

void PrintArray (int _array[], int _size)
{
	int i;
	for (i=0; i<_size; i++)
	{	
		printf("%d ", _array[i]);
		printf ("\n");
	}	
}

int NullCheck (int _array[], int _size)
{
	if (!_array)
	{
		return ERROR;
	}	 
	return DONE;		
}

void Swap (int *num1, int *num2)
	{
		int temp;
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;	
	}
	
int BubbleUp (int _array[], int _size, int i)
{
	int j;
	int isSwapped = 0;
	
	for (j=0; j<(_size-1-i); j++)
	{ 	
		if (_array[j] > _array[j+1])
		{				
			Swap ( _array+j, _array+j+1);
			isSwapped = 1;
		}
		
	}
	return isSwapped;
}

int BubbleSort(struct *_array, int _size)
{
	int i, isSwapped;
	
	NullCheck (_array, _size);

		for (i=0; i<_size; i++)
		{	
			isSwapped = BubbleUp(_array, _size, i);
			
			if (!isSwapped)	
			{
				break;
			} 
		}
	
	PrintArray(_array, _size);
	return DONE;
}

int BinarySearch(int *_array, int _size, int _numToSearch)
{
	int middle, first, last;
	
	BubbleSort(_array, _size);
	
	first = 0;
	last = _size-1;
	middle =1+ (first+last)/2;

	while (first < last) 
	{
		if (_numToSearch == _array[0]) 
		{
			middle = 1;			
			return middle;	
		}
		else if (_array[middle] < _numToSearch) 
		{
			first  = middle + 1;
		} 
		else if (_array[middle] > _numToSearch)  
		{
			last = middle - 1;
		}
		else if (_array[middle] == _numToSearch)
		{	
			return middle;		
		}
		middle =1 + (first+last)/2;
	}
	
	if (first > last)
	{
		return NOT_FOUND;	
	}
	return DONE;

}	

int* CreateArray(int _size, int *_numOfElements)
{
	int *_array;
	*_numOfElements = 0;

	return malloc(_size*sizeof(int));;
}


void* Destroy(int* _array)
{
	free(_array);
}


int AddNumber(int **_array, int *_size, int *_numOfElements, int _numToAdd, int increase)
{
	int *_newArray;
	if(_array == NULL || *_size=0)
	{
		return ERROR;
	}
	if(*_numOfElements == *size || increase != 0)
	{
		*_size += increase;
		*_array = realloc(*_array,*_size*sizeof(int));
		if(*_array == NULL)
		{
			return ERROR;
		}
	}
	*_array[*_numOfElements] = _numToAdd;
	*_numOfElements+=1;
		
	return DONE;
}



/*

int* AddNumber(int *_array, int* _size, int _numToBeAdded)
{
	int *_newArray;
	
	printf("%d\n", *_size);
	*_size = *_size+(*(_size)*0.2*sizeof(int));
	printf("%d\n", *_size);

	_newArray = realloc(_array,*_size);
		
	NullCheck(_newArray, *_size);
	
	_newArray[*(_size)-1] = _numToBeAdded;
	
	return _newArray;
}
*/

int* RemoveNumber(int* _array, int* _size, int _search)
{
	int *_newArray;	
	*_size = *_size-(*(_size-1)*sizeof(int));
	
	Swap( _array+_search, _array+(*_size));

	_newArray = realloc(_array,*_size);
		
	NullCheck(_newArray,*_size);
	
	return _newArray;
}












			
			







