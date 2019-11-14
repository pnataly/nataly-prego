#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "WQueue.h"
#include "producer.h"

#define PRODUCER_MSG "producer >> consumer"

struct Producer
{
	size_t m_num;
	pthread_t* m_thread;
};

static void* prodTreadFunc(void* param)
{
	WQueue_Enqueue(param, (void*)PRODUCER_MSG);
	printf("Producer enqueue the message: %s\n", PRODUCER_MSG);
	return param;
}

Producer* Create_Producers(WQ* _wq, size_t _num)
{
	int i;
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
	prod->m_num = _num;
	threads = (pthread_t*)malloc(sizeof(pthread_t)*_num);
	if (threads == NULL)
	{
		return NULL;
	}
	prod->m_thread = threads;
	for(i=0; i<_num; ++i)
	{
		if (pthread_create(&prod->m_thread[i], NULL, prodTreadFunc, (void*)_wq) != 0)
		{
			perror("pthread_create");
			return NULL;
		}
	}
	return prod;
}


void Join_Producers(Producer* _prod)
{
	int i;
	void* res;
	for(i=0; i<_prod->m_num; ++i)
	{
		if (pthread_join(_prod->m_thread[i], &res) != 0)
		{
			perror("pthread_join");
			return;
		}
	}
}
