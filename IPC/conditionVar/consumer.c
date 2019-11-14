#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "WQueue.h"
#include "consumer.h"


struct Consumer
{
	size_t m_numOfThreads;
	pthread_t* m_thread;
};

static void* consThreadFunc(void* param)
{
	void* pvalue;
	WQueue_Dequeue(param, &pvalue);
	printf("Consumer dequeue: %s\n", (char*)pvalue);
	return param;
}

Consumer* Create_Consumers(WQ* _wq, size_t _num)
{
	Consumer* cons = NULL;
	pthread_t* threads = NULL;
	if (_wq == NULL || _num == 0)
	{
		return NULL;
	}
	cons = (Consumer*)malloc(sizeof(Consumer));
	if (cons == NULL)
	{
		return NULL;
	}
	cons->m_numOfThreads = _num;
	threads = (pthread_t*)malloc(sizeof(pthread_t)*_num);
	if (threads == NULL)
	{
		return NULL;
	}
	cons->m_thread = threads;
	return cons;
}

void RunCons(WQ* _wq, Consumer* _cons)
{
	int i;
	if (_cons == NULL || _wq == NULL)
	{
		return;
	}
	for(i = 0; i<_cons->m_numOfThreads; ++i)
	{
		if (pthread_create(&_cons->m_thread[i], NULL, consThreadFunc, (void*)_wq) != 0)
		{
			perror("pthread_create");
			return;
		}
	}
}

void Kill_Consumers(Consumer* _cons)
{
	int i;
	if (_cons == NULL)
	{
		return;
	}
	for(i = 0; i<_cons->m_numOfThreads; ++i)
	{
		if (pthread_cancel(_cons->m_thread[i]) != 0)
		{
			perror ("pthread_cancel");
			return;
		}
	}
}

void Join_Consumers(Consumer* _cons)
{
	int i;
	void* res;
	if (_cons == NULL)
	{
		return;
	}
	for(i = 0; i<_cons->m_numOfThreads; ++i)
	{
		if (pthread_join(_cons->m_thread[i], &res) != 0)
		{
			perror ("pthread_join");
			return;
		}
	}
}

void Destroy_Cons(Consumer* _cons)
{
	if (_cons == NULL)
	{
		return;
	}
	free(_cons->m_thread);
	free(_cons);
}

