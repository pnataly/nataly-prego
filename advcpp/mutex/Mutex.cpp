#include "Mutex.h"

#include <cassert>

namespace advcpp{

Mutex::Mutex() throw(Mutex_Create_Failure_Exception)
:	m_islcok(false)
{
	if(int res = pthread_mutex_init(&m_mutex, 0))
	{
		throw Mutex_Create_Failure_Exception(res);
	}
}


Mutex::~Mutex() NOEXCEPT
{
	if(pthread_mutex_destroy(&m_mutex))
	{
		assert(false and "mutex destroy fail");
	}
}


void Mutex::Lock() throw(Mutex_Lock_Unrecavoble_Exception)
{
	if(int res = pthread_mutex_lock(&m_mutex))
	{
		throw Mutex_Lock_Unrecavoble_Exception(res);
	}
	m_islcok = true;
}

void Mutex::Unlock() throw(Mutex_UnLock_Failure_Exception)
{
	if(int res = pthread_mutex_unlock(&m_mutex))
	{
		throw Mutex_UnLock_Failure_Exception(res);
	}
	m_islcok = false;
}

/*
pthread_mutex_t* Mutex::navtive_mutex()
{
	return &m_mutex;
} */


bool Mutex::IsLock() const
{
	return m_islcok;
}

}
