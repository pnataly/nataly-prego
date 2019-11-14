#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAGIC_NUMBER 0XBEEFBEEF
#define DELET_MAGIC_NUMBER 0xDEADBEEF
#define TRUE 1


struct Queue
{
	unsigned int m_magicNumber;
	int* m_vec;
	size_t m_size;
	size_t m_head; /* index of head in m_vec */
	size_t m_tail; /* index of tail in m_vec */
	size_t m_nItems;
};


Queue* QueueCreate(size_t _size)
{
	Queue* _queue;
	if(_size == 0)
	{
		return NULL;
	}
	
	_queue = (Queue*) malloc(sizeof(Queue));
	if(_queue == NULL)
	{
		return NULL;
	}
	_queue->m_vec = (int*) malloc(_size*sizeof(int));
	if(_queue->m_vec == NULL)
	{
		free(_queue);
		return NULL;
	}

	_queue->m_size = _size;
	_queue->m_nItems = 0;
	_queue->m_magicNumber = MAGIC_NUMBER;
	_queue->m_head = 0;
	_queue->m_tail = 0;

	return _queue;
}

void QueueDestroy(Queue* _queue)
{
	if(_queue == NULL || _queue->m_magicNumber != MAGIC_NUMBER)
	{
		return;
	}

	_queue->m_magicNumber = DELET_MAGIC_NUMBER;
	free(_queue->m_vec);
	free(_queue);	
}

ADTErr QueueInsert(Queue* _queue, int _item)
{
	if(_queue == NULL || _queue->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	
	if((_queue->m_head == _queue->m_tail && _queue->m_nItems == _queue->m_size)|| (_queue->m_size == _queue->m_tail))
	{
		return ERR_OVERFLOW;
	}
	
	_queue->m_vec[_queue->m_tail] = _item;
	_queue->m_nItems++;
	_queue->m_tail = (_queue->m_tail+1) % _queue->m_size;

	return ERR_OK;
}

ADTErr QueueRemove(Queue* _queue, int* _item)
{
	if(_queue == NULL || _queue->m_magicNumber != MAGIC_NUMBER)
	{
		return ERR_UNINITINALAIZED;
	}
	
	if((_queue->m_head == _queue->m_tail && _queue->m_nItems == 0) || (_queue->m_size == _queue->m_head))
	{
		return ERR_EMPTY;
	}
	*_item = _queue->m_vec[_queue->m_head];
	_queue->m_head = (_queue->m_head+1) % _queue->m_size;
	_queue->m_nItems--;
	

	return ERR_OK;	
}

int IsEmptyQueue(const Queue* _queue)
{
	if(_queue == NULL || _queue->m_magicNumber != MAGIC_NUMBER)
	{
		return TRUE;
	}

	return !(_queue->m_nItems);
}

void PrintQueue(const Queue* _queue)
{
	int i;
	printf("The items in the queue: ");
	for(i=_queue->m_head; i<(_queue->m_tail) % _queue->m_size; i++)
	{
		printf("%d,\t", _queue->m_vec[i]);
	}
	printf("\n");
}









