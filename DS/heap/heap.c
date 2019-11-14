#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "ADTErr.h"
#define MAGIC_NUMBER 0XBEEFBEEF

/* 
* functions.h
 * Max Heap
 * a framework to create an Max Heap. 
 * Heap start in index 1.
 * Version: 0.01
 *      Author: Nataly Prego.  
 */

struct Heap
{
	unsigned int m_magicNumber;
	Vector* m_vec;
	size_t m_heapSize;
};

static void Heapify(Heap* _heap, int i)
{
    int left, right, status, i, temp;
	int parentData, lData, rData;

    left = 2*lastParent;
    right = left+1;
    if (left >= _heap->m_heapSize)
	{
        return;
	}
   	status = VectorGet(_heap->m_vec, lastParent, &parentData);
	if(status != ERR_OK)
	{
		return;
	} 
	status =  VectorGet(_heap->m_vec, left, &lData);
	if(status != ERR_OK)
	{
		return;
	} 
	status =  VectorGet(_heap->m_vec, right, &rData);
	if(status != ERR_OK)
	{
		return;
	} 
	for(i=lastParent; i>=0; i--)
	{
		if(parentData < lData)
		{
			temp = parentData;
			status = VectorSet(_heap->m_vec, lastParent, lData);
			if(status != ERR_OK)
			{
				return;
			} 
			status = VectorSet(_heap->m_vec, left, temp);
			if(status != ERR_OK)
			{
				return;
			} 
		}
		if(parentData < rData)
		{
			temp = parentData;
			status = VectorSet(_heap->m_vec, lastParent, rData);
			if(status != ERR_OK)
			{
				return;
			} 
			status = VectorSet(_heap->m_vec, right, temp);
			if(status != ERR_OK)
			{
				return;
			} 
		}
	}
}

static void shiftUp(Heap* _heap, int _i)
{
	int status, temp, father, son;
	if(_i == 1)
	{
		return;
	}

	VectorGet(_heap->m_vec, _i/2, &father);
	VectorGet(_heap->m_vec, _i, &son);
	 
	if(father < son)
	{
		temp = father;
		VectorSet(_heap->m_vec, father, son);
		VectorSet(_heap->m_vec, _heap->m_heapSize, temp);
		shiftUp(_heap, _i/2);	
	}
}

Heap* HeapBuild(Vector* _vec)
{
	Heap* heap;
	int result;
	size_t items;
	int lastParent;
	if(_vec == NULL)
	{
		return NULL;
	}
	heap = (Heap*)malloc(sizeof(Heap));
	if(heap ==	NULL)
	{
		return NULL;
	}
	if(result = VectorItemsNum(_vec, &items) != ERR_OK)
	{
		free(heap);
		return NULL;
	}
	heap->m_heapSize = items;
	heap->m_vec = _vec;
	heap->m_magicNumber = MAGIC_NUMBER;
	lastParent = heap->m_heapSize;
	for(i= heap->m_heapSize/2; i>0; i--)
	{
		Heapify(heap, i);
	}
	return heap;
}


void HeapDestroy(Heap* _heap)
{
	if(_heap == NULL || _heap->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	_heap->m_magicNumber = 0;
	free(_heap);
}



ADTErr HeapInsert(Heap* _heap, int _data)
{
	int result;
	if(_heap == NULL || _heap->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED; 
	}
	if(result = VectorAdd(_heap->m_vec, _data) != ERR_OK)
	{
		return ERR_ALLOC_FAIL;
	}

	_heap->m_heapSize++;
	shiftUp(_heap, heap->m_heapSize);
	return ERR_OK;
}


ADTErr HeapMax(Heap* _heap, int* _data)
{
	
	if(_heap == NULL || _heap->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED; 
	}
	
	if(heap->m_heapSize == 0)
	{
		return ERR_UNDERFLOW;
	}

	return VectorGet(_heap->m_vec, 1, _data);
}


ADTErr HeapExtractMax(Heap* _heap, int* _data)
{
	ADTErr result;
	int max, lastItem;
	size_t numOfItems;
	if(_heap == NULL || _heap->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED; 
	}
	
	if(result = HeapMax(_heap, _data)==ERR_OK)
	{
		
		VectorDelete(_heap->m_vec, &lastItem);
		VectorSet(_heap->m_vec, 1, lastItem);
		heap->m_heapSize--;
		Heapify(_heap, 1);
		return ERR_OK;
	}
	return result;
}

int HeapItemsNum(Heap* _heap)
{
	if(_heap == NULL || _heap->m_magicNumber != MAGIC_NUMBER)
	{
		return -1;
	}
	return heap->m_heapSize;
}

void HeapPrint(const Heap* _heap)
{
	if(_heap == NULL || _heap->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}
	VectorPrint(_heap->m_vec);
}

