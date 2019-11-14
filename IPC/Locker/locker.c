#include <stdlib.h>
#include <pthread.h>
#include "locker.h"

static pthread_mutex_t* CreateMutArray(size_t _numOfLock)
{
	size_t i;
	pthread_mutex_t* mutArray;
	mutArray = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)*_numOfLock);
	if (mutArray == NULL)
	{
		return NULL;
	}
	for (i=0; i<_numOfLock; i++)
	{
		pthread_mutex_t mutex;
		if (pthread_mutex_init(&mutex, NULL) != 0)
		{
			free (mutArray);
			return NULL;
		}
		mutArray[i] = mutex;
	}
	return mutArray;
}

Locker* LockerCreate(size_t _numOfLock)
{
	Locker* lock;
	pthread_mutex_t* mutArray;
	lock = (Locker*) malloc(sizeof(Locker));
	if (lock == NULL)
	{
		return NULL;
	}
	mutArray = CreateMutArray(_numOfLock);
	if (mutArray == NULL)
	{
		free(lock);
		return NULL;
	}
	lock->m_lock = mutArray;
	lock->m_numOfLock = _numOfLock;
	return lock;	
}

void LockerDestroy(Locker** _lock)
{
	size_t i;
	if (_lock == NULL)
	{
		return;
	}
	for (i=0; i<(*_lock)->m_numOfLock; i++)
	{
		pthread_mutex_destroy(&(*_lock)->m_lock[i]);
	}
	free(&(*_lock)->m_lock);
	free(*_lock);
	*_lock = NULL;
}

void Lock(Locker* _lock, size_t _index)
{
	if (_lock == NULL)
	{
		return;
	}
	pthread_mutex_lock(&_lock->m_lock[_index]); 
}


void UnLock(Locker* _lock, size_t _index)
{
	if (_lock == NULL)
	{
		return;
	}
	pthread_mutex_unlock(&_lock->m_lock[_index]); 
}

