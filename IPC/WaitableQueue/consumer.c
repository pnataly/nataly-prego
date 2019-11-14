#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "WQueue.h"
#include "consumer.h"


struct Consumer
{
	size_t m_num;
	pthread_t* m_thread;
};

static void* consThreadFunc(void* param)
{
	void* pvalue;
	WQueue_Dequeue(param, &pvalue);
	printf("Consumer dequeue the message: %s\n", (char*)pvalue);
	return param;
}

Consumer* Create_Consumers(WQ* _wq, size_t _num)
{
	int i;
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
	cons->m_num = _num;
	threads = (pthread_t*)malloc(sizeof(pthread_t)*_num);
	if (threads == NULL)
	{
		return NULL;
	}
	cons->m_thread = threads;
	for(i=0; i<_num; ++i)
	{
		if (pthread_create(&cons->m_thread[i], NULL, consThreadFunc, (void*)_wq) != 0)
		{
			perror("pthread_create");
			return NULL;
		}
	}
	return cons;
}


void Join_Consumers(Consumer* _cons)
{
	int i;
	void* res;
	for(i=0; i<_cons->m_num; ++i)
	{
		if (pthread_join(_cons->m_thread[i], &res) != 0)
		{
			perror ("pthread_join");
			return;
		}
	}
}

void Kill_Consumers(Consumer* _cons)
{
	int i;
	for(i=0; i<_cons->m_num; ++i)
	{
		if (pthread_cancel(_cons->m_thread[i]) != 0)
		{
			perror ("pthread_cancel");
			return;
		}
	}
}
