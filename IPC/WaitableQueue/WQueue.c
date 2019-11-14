#include "WQueue.h"
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

struct WQ
{
	void** m_vec;
	size_t m_size; 		/*capacity of the queue*/
	size_t m_head; 
	size_t m_tail; 
	size_t m_nItems;
	sem_t m_semEmpty;
	sem_t m_semFull;
	pthread_mutex_t m_mutex;
};

static void semInit(WQ* _wq)
{
	if (sem_init(&(_wq->m_semEmpty), 0, _wq->m_size) < 0)
	{
		perror ("semEmpty_init");
		return;
	}
	if (sem_init(&(_wq->m_semFull), 0, 0) < 0)
	{
		perror ("semFull_init");
		return;
	}
	if (pthread_mutex_init(&(_wq->m_mutex), NULL) != 0)
	{
		perror("mutex_init");
		return;
	}
}

WQ* WQueue_Create(size_t _size)
{
	WQ* wq;
	if (_size == 0)
	{
		return NULL;
	}
	wq = (WQ*)malloc(sizeof(WQ));
	if (wq == NULL)
	{
		return NULL;
	}
	wq->m_vec = (void**) malloc(_size*sizeof(void*));
	if(wq->m_vec == NULL)
	{
		free(wq);
		return NULL;
	}
	wq->m_size = _size;
	wq->m_nItems = 0;
	wq->m_head = 0;
	wq->m_tail = 0;
	semInit(wq);
	return wq;
}

void WQueue_Enqueue(WQ* _wq, void* _item)
{
	if (_wq == NULL || _item == NULL)
	{
		return;
	}
	sem_wait(&(_wq->m_semEmpty));
	pthread_mutex_lock(&(_wq->m_mutex));
	/*insert to queue */
	_wq->m_vec[_wq->m_tail] = _item;
	_wq->m_nItems++;
	_wq->m_tail = (_wq->m_tail+1) % _wq->m_size;

	pthread_mutex_unlock(&(_wq->m_mutex));
	sem_post(&(_wq->m_semFull));
}

void WQueue_Dequeue(WQ* _wq, void** _pValue)
{
	if (_wq == NULL || _pValue == NULL)
	{
		return;
	}
	sem_wait(&(_wq->m_semFull));
	pthread_mutex_lock(&(_wq->m_mutex));
	/*remove from queue*/
	*_pValue = _wq->m_vec[_wq->m_head];
	_wq->m_head = (_wq->m_head+1) % _wq->m_size;
	_wq->m_nItems--;

	pthread_mutex_unlock(&(_wq->m_mutex));
	sem_post(&(_wq->m_semEmpty));
}

void WQueue_Destroy(WQ** _wq, void (*_elementDestroy)(void* _item))
{
	size_t i = 0;
	if (_wq == NULL || *_wq == NULL)
	{
		return;
	}
	if(_elementDestroy != NULL)
	{
		while(i<(*_wq)->m_nItems)
		{
			_elementDestroy((*_wq)->m_vec[(((*_wq)->m_head)+i) % (*_wq)->m_size]);
			i++;
		}
	}
	sem_destroy(&(*_wq)->m_semEmpty);
	sem_destroy(&(*_wq)->m_semFull);
	pthread_mutex_destroy(&(*_wq)->m_mutex);
	free((*_wq)->m_vec);
	free(*_wq);	
	*_wq = NULL;
}

