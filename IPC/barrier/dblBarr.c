#include <stdio.h>
#include <pthread.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <semaphore.h>
#include "dblBarr.h"

struct DB
{
	pthread_barrier_t m_barrierIn;
	pthread_barrier_t m_barrierOut;
	size_t m_numOfThreads;
	sem_t m_sem;
};

DB* CreateDoubleBarrier(size_t _numOfThreads)
{
	DB* db;
	if (_numOfThreads == 0)
	{
		return NULL;
	}
	db = (DB*)malloc(sizeof(DB));
	if (db == NULL)
	{
		return NULL;
	}
	db->m_numOfThreads = _numOfThreads;
	if (pthread_barrier_init(&db->m_barrierIn, NULL, db->m_numOfThreads) <0)
	{
		perror ("pthread_barrier_init");
		free(db);
		return NULL;
	}
	if (pthread_barrier_init(&db->m_barrierOut, NULL, db->m_numOfThreads) <0)
	{
		perror ("pthread_barrier_init");
		free(db);
		return NULL;
	}
	if (sem_init(&(db->m_sem), 0, db->m_numOfThreads) < 0)
	{
		perror ("sem_init");
		return NULL;
	}
	return db;
}

void DestroyDoubleBarrier(DB** _db)
{
	if (_db == NULL || *_db == NULL)
	{
		return;
	}
	pthread_barrier_destroy(&(*_db)->m_barrierIn);
	pthread_barrier_destroy(&(*_db)->m_barrierOut);
	sem_destroy(&(*_db)->m_sem);
	free(*_db);
	*_db = NULL;
}

void BarrWait(DB* _db, Func _func, void* _context)
{
	int i= _db->m_numOfThreads;
	if (_db == NULL)
	{
		return;
	}
	sem_wait(&(_db->m_sem));
	if (pthread_barrier_wait(&_db->m_barrierIn) == PTHREAD_BARRIER_SERIAL_THREAD)
	{
		if (_func != NULL)
		{
			_func(_context);
		}
		pthread_barrier_wait(&_db->m_barrierOut);
		while(i>0)
		{
			sem_post(&_db->m_sem);
			i--;
		}
	}
}



