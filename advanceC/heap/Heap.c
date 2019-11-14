
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "genericHeap.h"

#define MAGIC_NUMBER 0XBEEFBEEF

#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
#define FATHER(i) ((i+1)/2-1)



struct Heap
{
	Vector *m_vec;
	size_t m_heapSize;
	LessThanComparator m_less;
};

static void SwapByIndexes(Vector *_vec, size_t _index1,  size_t _index2);
static size_t LessAmong3(Vector *_vec, size_t _father, LessThanComparator _pfLess);
static void HeapifyUp(Vector *_vec, LessThanComparator _pfLess, size_t _index);

static size_t LessAmong2(Vector *_vec, size_t _father, LessThanComparator _pfLess);







Heap_ResultCode Heap_Insert(Heap* _heap, void* _element)
{
	if (_heap == NULL || _element == NULL)
		{
			return HEAP_NOT_INITIALIZED;
		}
	if (Vector_Append(_heap -> m_vec, _element) != VECTOR_SUCCESS)
	{
		return HEAP_OVERFLOW_ERROR;
	}	
	_heap->m_heapSize++;
	HeapifyUp(_heap -> m_vec, _heap -> m_less, _heap -> m_heapSize - 1);
return HEAP_SUCCESS;
}


Vector* Heap_Destroy(Heap** _heap)
{
	Vector *tempVec;
	if(_heap == NULL || *_heap == NULL)
	{
		return NULL;
	}
	tempVec = (*_heap) -> m_vec;
	free (*_heap);
	*_heap = NULL;
	return tempVec;
}


void Heapify(Vector *_vec, size_t _numberOfElements, size_t _index, LessThanComparator _pfLess)
{
	size_t LessIndex;
	if (_vec == NULL || _pfLess == NULL)
	{
		return;
	}

	if ( _index > _numberOfElements/2 - 1 )
	{
		return;
	}
	if (_numberOfElements >= 2 + LEFT(_index)) /*2 leaf*/
	{
		LessIndex = LessAmong3(_vec,_index,_pfLess);
	}
	else if (_numberOfElements >= 1 + LEFT(_index)) /*1 leaf only - left*/
	{
		LessIndex = LessAmong2(_vec,_index,_pfLess);
	}
	
	if(LessIndex != _index)
	{	/*since the "Lessest" item is not _index, we need to swap and swap down*/
		SwapByIndexes(_vec, LessIndex, _index); 

		Heapify(_vec, _numberOfElements, LessIndex, _pfLess);
	}
	if(_index == 0)
	{
		return;
	}
/*	Heapify(_vec,_numberOfElements, _index-1, _pfLess);*/
return; 
}

Heap* Heap_Build(Vector* _vector, LessThanComparator _pfLess)
{
	Heap* newHeap;
	int i;

	if (_vector == NULL || _pfLess == NULL)
	{
		return NULL;
	}

	newHeap = (Heap *)malloc(sizeof(Heap));
	if (newHeap == NULL)
	{
		return NULL;
	}

	newHeap -> m_heapSize = Vector_Size(_vector);
	newHeap -> m_less = _pfLess;
	newHeap -> m_vec = _vector;
	for (i = newHeap -> m_heapSize/2 - 1 ; i >= 0 ; i--)
	{
		Heapify(newHeap -> m_vec,newHeap -> m_heapSize , i , _pfLess);
	}
return newHeap;
}

void* Heap_Extract(Heap* _heap)
{
	void *max;
	if (_heap == NULL || _heap -> m_heapSize == 0)
	{
		return NULL;
	}
	SwapByIndexes(_heap -> m_vec, 0, _heap -> m_heapSize - 1);
	Vector_Remove(_heap -> m_vec, &max);
	_heap -> m_heapSize--;
	Heapify(_heap -> m_vec, _heap -> m_heapSize , _heap -> m_heapSize/2 - 1, _heap -> m_less);
	return max;
}

const void* Heap_Peek(const Heap* _heap)
{
	void *peek;
	if (_heap == NULL)
	{
		return NULL;
	}
	Vector_Get(_heap -> m_vec, 0, &peek);
	return peek;
}

size_t Heap_ForEach(const Heap* _heap, ActionFunction _act, void* _context)
{
	if (_heap == NULL || _act == NULL)
	{
		return 0;
	}	
	return Vector_ForEach(_heap -> m_vec, (VectorElementAction) _act, _context);
}

size_t Heap_Size(const Heap* _heap)
{
	if (_heap == NULL)
	{
		return 0;
	}
	return _heap -> m_heapSize;
}
	
static void HeapifyUp(Vector *_vec, LessThanComparator _pfLess, size_t _index)
{
	void *left, *right;
	if (_vec == NULL)
	{
		return;
	}
	while (_index > 0)
	{
		Vector_Get(_vec,_index,&right);
		Vector_Get(_vec,FATHER(_index),&left);
		if (!_pfLess(left,right)) /*we got false ==  need to change*/
		{
			SwapByIndexes(_vec, _index, FATHER(_index));
			_index = FATHER(_index);
			continue;
		}
		return;
	}
	return; 
}

static size_t LessAmong2(Vector *_vec, size_t _father, LessThanComparator _pfLess)
{
	void *left, *father;
	size_t smallestIndex = _father;
	
	Vector_Get(_vec, _father, &father);
	Vector_Get(_vec, LEFT(_father), &left);
	if (!_pfLess(left,father)) /* true = father is lessest*/
	{
		smallestIndex = LEFT(_father);
	}
return smallestIndex;
}

static size_t LessAmong3(Vector *_vec, size_t _father, LessThanComparator _pfLess)
{
	void *left,*right, *father;
	size_t smallestIndex = _father;
	
	Vector_Get(_vec, _father, &father);
	Vector_Get(_vec, LEFT(_father), &left);
	Vector_Get(_vec, RIGHT(_father), &right);
	if (!_pfLess(right,father)) /* true = father is lessest*/
	{
		smallestIndex = RIGHT(_father);
		father = right;
	}
	if (!_pfLess(left,father)) /* true = father is lessest*/
	{
		smallestIndex = LEFT(_father);
	}
return smallestIndex;
}

static void SwapByIndexes(Vector *_vec, size_t _index1,  size_t _index2)
{
	void *value1;
	void *value2;

	Vector_Get(_vec, _index1, &value1);
	Vector_Get(_vec, _index2, &value2);
	Vector_Set(_vec, _index1, value2);
	Vector_Set(_vec, _index2, value1);
}


