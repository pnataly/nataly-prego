#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "WQueue.h"
#include "producer.h"

#define PRODUCER_MSG "producer >> consumer"

struct Producer
{
	size_t m_numOfThreads;
	pthread_t* m_thread;
};

static void* prodThreadFunc(void* param)
{
	WQueue_Enqueue(param, (void*)PRODUCER_MSG);
	printf("Producer enqueue: %s\n", PRODUCER_MSG);
	return param;
}

Producer* Create_Producers(WQ* _wq, size_t _num)
{
	Producer* prod = NULL;
	pthread_t* threads= NULL;
	if (_wq == NULL || _num == 0)
	{
		return NULL;
	}
	prod = (Producer*)malloc(sizeof(Producer));
	if (prod == NULL)
	{
		return NULL;
	}
	prod->m_numOfThreads = _num;
	threads = (pthread_t*)malloc(sizeof(pthread_t)*_num);
	if (threads == NULL)
	{
		return NULL;
	}
	prod->m_thread = threads;
	return prod;
}

void RunProd(WQ* _wq, Producer* _prod)
{
	int i;
	if (_prod == NULL || _wq == NULL)
	{
		return;
	}
	for(i = 0; i<_prod->m_numOfThreads; ++i)
	{
		if (pthread_create(&_prod->m_thread[i], NULL, prodThreadFunc, (void*)_wq) != 0)
		{
			perror("pthread_create");
			return;
		}
	}
}

void Join_Producers(Producer* _prod)
{
	int i;
	void* res;
	if (_prod == NULL)
	{
		return;
	}
	for(i = 0; i<_prod->m_numOfThreads; ++i)
	{
		if (pthread_join(_prod->m_thread[i], &res) != 0)
		{
			perror("pthread_join");
			return;
		}
	}
}

void Destroy_Prod(Producer* _prod)
{
	if (_prod == NULL)
	{
		return;
	}
	free(_prod->m_thread);
	free(_prod);
}

