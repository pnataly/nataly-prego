#include <stdio.h>
#include <stdlib.h>
#include "genericHeap.h"

#define PARENT(i) (i)/2
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)
#define NOT_INITIALIZED_ERR 0


struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator m_less;
};

static void swap(Vector* _vec, size_t _i, size_t _switch)
{
	void* son;
	void* father;
	Vector_Get(_vec,_i,&father);
	Vector_Get(_vec,_switch,&son);
	Vector_Set(_vec,_i,son);
	Vector_Set(_vec,_switch,father);
}

void Heapify(Heap *_heap, size_t _fatherLocation, LessThanComparator _pfLess)
{
	void* rightSonItem;
	void* leftSonItem;
	void* fatherItem;
	
	if (_fatherLocation > ((_heap->m_heapSize-1) / 2))
	{
		return;
	}
	Vector_Get(_heap->m_vec, _fatherLocation, &fatherItem);
	
	/*check if there is a right son*/
	if (RIGHT(_fatherLocation) <= _heap->m_heapSize-1)
	{
		Vector_Get(_heap->m_vec, RIGHT(_fatherLocation), &rightSonItem);
		Vector_Get(_heap->m_vec, LEFT(_fatherLocation), &leftSonItem);
		
		/*if left son should be the father*/
		if(_pfLess(leftSonItem,fatherItem) && _pfLess(leftSonItem,rightSonItem))
		{
			swap(_heap->m_vec,_fatherLocation, LEFT( _fatherLocation));
			Heapify(_heap,LEFT(_fatherLocation),_pfLess);
		}
		/*if right son should be the father*/
		if(_pfLess(rightSonItem,fatherItem) && _pfLess(rightSonItem,leftSonItem))
		{
			swap(_heap->m_vec,_fatherLocation,RIGHT(_fatherLocation));
			Heapify(_heap,RIGHT(_fatherLocation),_pfLess);
		}
	}
	else 	/*if there is no right son*/
	{
		Vector_Get(_heap->m_vec,LEFT(_fatherLocation),&leftSonItem);
		/*if left son should be the father*/
		if(_pfLess(leftSonItem, fatherItem))
		{
			swap(_heap->m_vec,_fatherLocation,LEFT( _fatherLocation));
			Heapify(_heap,LEFT(_fatherLocation),_pfLess);
		}
	}
	return;
}

void ShiftUp (Heap* _heap, int _sonLocation,LessThanComparator _pfLess)
{
	void* fatherItem;
	void* sonItem;
	if (_sonLocation == 0 || _heap == NULL)
	{
		return;
	}
	Vector_Get(_heap->m_vec,_sonLocation,&sonItem);
	Vector_Get(_heap->m_vec,PARENT(_sonLocation),&fatherItem);
	
	if (_pfLess(sonItem,fatherItem))
	{
		swap(_heap->m_vec,PARENT(_sonLocation),_sonLocation);
		ShiftUp(_heap,PARENT(_sonLocation),_pfLess);
	}
	return;
}


Heap* Heap_Build(Vector* _vector, LessThanComparator _pfLess)
{
	int fatherLocation;
	size_t size;
	Heap* heap;
	if(NULL == _vector || _pfLess == NULL)
	{
		return NULL;
	}
	heap = (Heap*)malloc(sizeof(Heap));
	if (NULL == heap)
	{
		return NULL;
	}
	size = Vector_Size(_vector);
	heap->m_vec = _vector;
	heap->m_heapSize = size;
	heap->m_less = _pfLess;
	fatherLocation = ((heap->m_heapSize-1) / 2);
	if (size < 2)
	{
		return heap;
	}
	while(fatherLocation >= 0 )
	{
		/*run on all fathers up untill heap is set*/
		Heapify(heap,fatherLocation,_pfLess);
		fatherLocation --;		
	}	
	return heap;
}
	

Vector* Heap_Destroy(Heap** _heap)
{
	Vector* vector;
	if (NULL == _heap || NULL == *_heap)
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
	size_t sonLocation;
	if (NULL == _heap || NULL == _element)
	{
		return HEAP_NOT_INITIALIZED;
	}
	if(Vector_Append(_heap->m_vec, _element) != VECTOR_SUCCESS)
	{
		return HEAP_OVERFLOW_ERROR;
	}
	_heap->m_heapSize++;
	sonLocation = _heap->m_heapSize;
	ShiftUp(_heap, sonLocation-1, _heap->m_less);
	return HEAP_SUCCESS;
}


const void* Heap_Peek(const Heap* _heap)
{
	void* item;
	if (NULL == _heap)
	{
		return NULL;
	}
	Vector_Get(_heap->m_vec,0, &item);
	return item; 
}


void* Heap_Extract(Heap* _heap)
{
	void* max;
	void* last;
	if (NULL == _heap || _heap->m_heapSize == 0)
	{
		return NULL;
	}
	if(_heap->m_heapSize == 1)
	{
		Vector_Remove(_heap->m_vec, &max);
		return max;
	}
	Vector_Get(_heap->m_vec,0, &max);
	Vector_Remove(_heap->m_vec, &last);
	Vector_Set(_heap->m_vec,0,last);
	_heap->m_heapSize--;	
	Heapify(_heap,0,_heap->m_less);
	return max;
}


size_t Heap_Size(const Heap* _heap)
{
	if ( NULL == _heap)
	{
		return NOT_INITIALIZED_ERR; 
	}
	return _heap->m_heapSize;
}


size_t Heap_ForEach(const Heap* _heap, ActionFunction _act, void* _context)
{
	if (NULL == _heap || NULL == _act)
	{
		return 0;
	}
	return Vector_ForEach(_heap->m_vec, (VectorElementAction)_act, _context);
}

