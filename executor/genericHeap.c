#include <stdio.h>
#include <stdlib.h>
#include "genericHeap.h"

#define PARENT(i) (i)/2
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
#define NOT_INITIALIZED_ERR 0
#define FALSE 0
#define TRUE 1

struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator m_less;
};


static void Swap(Vector* _vector, size_t _i, size_t _switch)
{
	void* son = 0;
	void* parent = 0;
	
	Vector_Get(_vector, _i, &parent);
	Vector_Get(_vector, _switch, &son);
	Vector_Set(_vector,_i, son);
	Vector_Set(_vector,_switch, parent);
}


int FindMax(Heap* _heap, int _lastParent)
{
	void* rightItem = NULL;
	void* leftItem= NULL;
	void* parentItem = NULL;
	
	if (_lastParent > ((_heap->m_heapSize-1) / 2))
	{
		return _lastParent;
	}
	
	Vector_Get(_heap->m_vec,_lastParent,&parentItem);
	Vector_Get(_heap->m_vec, LEFT(_lastParent),&leftItem);
	
	/*If we do have right son*/
	if (RIGHT(_lastParent) <= _heap->m_heapSize-1)
	{
		Vector_Get(_heap->m_vec, RIGHT(_lastParent),&rightItem);
		
		/*If left son should be the parent*/
		if(_heap->m_less(leftItem, parentItem) == TRUE && _heap->m_less(leftItem,rightItem) == TRUE)
		{
			return  LEFT(_lastParent);
		}
		/*if right son should be the parent*/
		if(_heap->m_less(rightItem,parentItem) == TRUE && _heap->m_less(rightItem,leftItem) == TRUE)
		{
			return  RIGHT(_lastParent);
		}
	}
	
	/*If we do NOT have right son*/
	else
	{
		/*If left son should be the parent*/
		if(_heap->m_less(leftItem,parentItem) == TRUE )
		{
			return  LEFT(_lastParent);
		}
	}
	
	return _lastParent;
}

static void Heapify(Heap* _heap, size_t _lastParent)
{
	int max = 0;	
	
	if (_heap == NULL)
	{
		return;
	}
	
	if (_lastParent > ((_heap->m_heapSize-1) /2))
	{
		return;
	}
	
	max = FindMax(_heap, _lastParent);
	if (max != _lastParent)
	{
		Swap(_heap->m_vec, _lastParent, max);
		Heapify(_heap, max);
	}	
}

static void ShiftUp(Heap* _heap, int _son)
{
	void* parentItem = 0;
	void* sonItem = 0;
	
	if (_heap == NULL)
	{	
		return;
	}
	
	Vector_Get(_heap->m_vec, _son, &sonItem);
	Vector_Get(_heap->m_vec, PARENT(_son), &parentItem);

	if (_heap->m_less(sonItem, parentItem))
	{
		Swap(_heap->m_vec, PARENT(_son), _son);
		ShiftUp(_heap, PARENT(_son));	
	}
}

Heap* Heap_Build(Vector* _vector, LessThanComparator _pfLess)
{
	Heap* heap;
	size_t lastParent;
			
	if (_vector == NULL || _pfLess == NULL)
	{
		return NULL;
	}

	heap = (Heap*) malloc(sizeof(Heap));
	if (heap == NULL)
	{
		return NULL;
	}
	heap->m_vec = _vector;
	heap->m_less = _pfLess;
	heap->m_heapSize = Vector_Size(_vector);	
	
	lastParent = ((heap->m_heapSize)/2) -1;
	/*No need heapify*/
	if (heap->m_heapSize < 2)
	{
		return heap;
	}
	while (lastParent >= 0)
	{	
		/*Heapifying all elements*/
		Heapify(heap, lastParent);
		lastParent--;
	}
	return heap;
} 

Vector* Heap_Destroy(Heap** _heap)
{
	Vector* vector;
	if (_heap == NULL || *_heap == NULL)
	{
		return NULL;
	}
	vector = (*_heap)->m_vec;
	free(*_heap);
	*_heap = NULL;
	return vector;
}

Heap_ResultCode Heap_Insert(Heap* _heap, void* _element)
{
	size_t son;
	if (_heap == NULL)
	{
		return HEAP_NOT_INITIALIZED;
	}
	
	if (_element == NULL)
	{
		return HEAP_INPUT_NULL;
	}

	if(Vector_Append(_heap->m_vec, _element) != VECTOR_SUCCESS)
	{
		return VECTOR_OVERFLOW_ERROR;
	}
	_heap->m_heapSize++;	
	
	son = _heap->m_heapSize;
	ShiftUp(_heap, son-1);

	return HEAP_SUCCESS;
}

const void* Heap_Peek(const Heap* _heap)
{
	void* max;

	if (_heap == NULL)
	{
		return NULL;
	}
	
 	Vector_Get(_heap->m_vec, 0, &max);

	return max; 
}

void* Heap_Extract(Heap* _heap)
{
	void* max;
	void* last;
	
	if (_heap == NULL || _heap->m_heapSize == 0)
	{
		return NULL;
	}
	Vector_Get(_heap->m_vec, 0, &max);
	Vector_Remove(_heap->m_vec, &last);
	
	/*Setting Max as last*/
	Vector_Set(_heap->m_vec, 0, last);	
	_heap->m_heapSize--;	
	
	Heapify(_heap, 0);

	return max;
}

size_t Heap_Size(const Heap* _heap)
{
	if (_heap == NULL)
	{
		return 0; 
	}
	
	return Vector_Size(_heap->m_vec);
}	

size_t Heap_ForEach(const Heap* _heap, ActionFunction _action, void* _context)
{
	if (_heap == NULL || _action == NULL)
	{
		return 0;
	}
	return 	Vector_ForEach(_heap->m_vec, (VectorElementAction) _action, _context);
}


