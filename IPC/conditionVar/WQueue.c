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
	condVar* m_cv;
};

struct condVar
{
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
};

static condVar* Create_ConditionVariable()
{
	condVar* cv = NULL;
	cv = (condVar*)malloc(sizeof(condVar));
	if (cv == NULL)
	{
		return NULL;
	}
	if(pthread_cond_init(&(cv->m_cond), NULL) != 0)
	{
		perror("cond_init");
		return NULL;
	}
	if (pthread_mutex_init(&(cv->m_mutex), NULL) != 0)
	{
		perror("mutex_init");
		return NULL;
	}
	return cv;
}

static void Destroy_ConditionVariable(condVar** _condVar)
{
	if (_condVar == NULL || *_condVar == NULL)
	{
		return;
	}
	pthread_mutex_lock(&(*_condVar)->m_mutex);
	pthread_mutex_destroy(&(*_condVar)->m_mutex);
	pthread_cond_destroy(&(*_condVar)->m_cond);
	free(*_condVar);
	*_condVar = NULL;
}


WQ* WQueue_Create(size_t _size)
{
	WQ* wq = NULL;
	condVar* cv = NULL;
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
	if (wq->m_vec == NULL)
	{
		free(wq);
		return NULL;
	}
	wq->m_size = _size;
	wq->m_nItems = 0;
	wq->m_head = 0;
	wq->m_tail = 0;
	cv = Create_ConditionVariable();
	if (cv == NULL)
	{
		return NULL;
	}
	wq->m_cv = cv;
	return wq;
}

void WQueue_Enqueue(WQ* _wq, void* _item)
{
	if (_wq == NULL || _item == NULL)
	{
		return;
	}
	/*up*/
	pthread_mutex_lock(&_wq->m_cv->m_mutex);
	while (_wq->m_size == _wq->m_nItems)
	{
		pthread_cond_wait(&(_wq->m_cv->m_cond), &(_wq->m_cv->m_mutex));
	}
	/*insert to queue */
	_wq->m_vec[_wq->m_tail] = _item;
	_wq->m_nItems++;
	_wq->m_tail = (_wq->m_tail+1) % _wq->m_size;

    pthread_cond_signal(&_wq->m_cv->m_cond); 
	pthread_mutex_unlock(&_wq->m_cv->m_mutex);
}

void WQueue_Dequeue(WQ* _wq, void** _pValue)
{
	if (_wq == NULL || _pValue == NULL)
	{
		return;
	}
	/*down*/
	pthread_mutex_lock(&(_wq->m_cv->m_mutex));
	while (_wq->m_nItems == 0) 
	{
		pthread_cond_wait(&(_wq->m_cv->m_cond), &(_wq->m_cv->m_mutex));
	}

	/*remove from queue*/
	*_pValue = _wq->m_vec[_wq->m_head];
	_wq->m_head = (_wq->m_head+1) % _wq->m_size;
	_wq->m_nItems--;

	pthread_mutex_unlock(&_wq->m_cv->m_mutex);
}

void WQueue_Destroy(WQ** _wq, void (*_elementDestroy)(void* _item))
{
	size_t i = 0;
	if (_wq == NULL || *_wq == NULL)
	{
		return;
	}
	if (_elementDestroy != NULL)
	{
		while(i<(*_wq)->m_nItems)
		{
			_elementDestroy((*_wq)->m_vec[(((*_wq)->m_head)+i) % (*_wq)->m_size]);
			i++;
		}
	}
	Destroy_ConditionVariable(&(*_wq)->m_cv);
	free((*_wq)->m_vec);
	free(*_wq);	
	*_wq = NULL;
}

