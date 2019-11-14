#include <stdio.h>
#include <stdlib.h>
#include "genericQueue.h"


struct Queue
{
	void** m_vec;
	size_t m_size;
	size_t m_head; /* index of head in m_vec */
	size_t m_tail; /* index of tail in m_vec */
	size_t m_nItems;
};


Queue* Queue_Create(size_t _maxSize)
{
	Queue* queue;
	if(_maxSize == 0)
	{
		return NULL;
	}
	
	queue = (Queue*) malloc(sizeof(Queue));
	if(queue == NULL)
	{
		return NULL;
	}
	queue->m_vec = (void**) malloc(_maxSize*sizeof(void*));
	if(queue->m_vec == NULL)
	{
		free(queue);
		return NULL;
	}

	queue->m_size = _maxSize;
	queue->m_nItems = 0;
	queue->m_head = 0;
	queue->m_tail = 0;

	return queue;
}

void Queue_Destroy(Queue** _queue, void (*_elementDestroy)(void* _item))
{
	size_t i;
	if(_queue == NULL || *_queue == NULL)
	{
		return;
	}
	if(_elementDestroy != NULL)
	{
		i=0; 
		while(i<(*_queue)->m_nItems)
		{
			_elementDestroy((*_queue)->m_vec[(((*_queue)->m_head)+i) % (*_queue)->m_size]);
			i++;
		}
	}
	free((*_queue)->m_vec);
	free(*_queue);	
	*_queue = NULL;
}

Queue_Result Queue_Enqueue(Queue* _queue, void* _item)
{
	if(_queue == NULL)
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	if(_item == NULL)
	{
		return QUEUE_NULL_ELEMENT_ERROR;
	}
	if((_queue->m_head == _queue->m_tail && _queue->m_nItems == _queue->m_size)|| (_queue->m_size == _queue->m_tail))
	{
		return QUEUE_OVERFLOW;
	}
	
	_queue->m_vec[_queue->m_tail] = _item;
	_queue->m_nItems++;
	_queue->m_tail = (_queue->m_tail+1) % _queue->m_size;

	return QUEUE_SUCCESS;
}

Queue_Result Queue_Dequeue(Queue* _queue, void** _pValue)
{
	if(_queue == NULL)
	{
		return QUEUE_UNINITIALIZED_ERROR;
	}
	if(_pValue == NULL)
	{
		return QUEUE_NULL_ELEMENT_ERROR;
	}
	if((_queue->m_head == _queue->m_tail && _queue->m_nItems == 0) || (_queue->m_size == _queue->m_head))
	{
		return QUEUE_UNDERFLOW;
	}
	*_pValue = _queue->m_vec[_queue->m_head];
	_queue->m_head = (_queue->m_head+1) % _queue->m_size;
	_queue->m_nItems--;
	

	return QUEUE_SUCCESS;	
}

int Queue_IsEmpty(const Queue* _queue)
{
	if(_queue == NULL)
	{
		return TRUE;
	}

	return !(_queue->m_nItems);
}

size_t Queue_ForEach(const Queue* _queue, QueueElementAction _action, void* _context)
{
	size_t i;
	if(_queue == NULL || _action == NULL)
	{
		return 0;
	}

    for(i = 0; i < _queue->m_nItems; i++)
	{
         if(_action(_queue->m_vec[((_queue->m_head)+i) % _queue->m_size],i, _context) == 0)
				break;	
	}
	return i;
}










