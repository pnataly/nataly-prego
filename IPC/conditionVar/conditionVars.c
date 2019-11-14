#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "conditionVars.h"

#define SIZE 5

struct condVar
{
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
};

condVar* Create_ConditionVariable()
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

void Destroy_ConditionVariable(condVar** _condVar)
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

void Up(condVar* _condVar)
{
	if (_condVar == NULL)
	{
		return;
	}
	pthread_mutex_lock(&(_condVar->m_mutex));
	while (_condVar->m_val == SIZE)
	{
		pthread_cond_wait(&(_condVar->m_cond), &(_condVar->m_mutex));
	}
	_condVar->m_val++;
}


void Down(condVar* _condVar)
{
	if (_condVar == NULL)
	{
		return;
	}
	while (_condVar->m_val == 0) 
	{
		pthread_cond_wait(&(_condVar->m_cond), &(_condVar->m_mutex));
	}
	_condVar->m_val--;
    pthread_cond_signal(&_condVar->m_cond); 
	pthread_mutex_unlock(&(_condVar->m_mutex));
}

