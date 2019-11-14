#ifndef MUTEX_H
#define MUTEX_H

#include "exceptions.h"
#include "commons.h"
#include "Uncopyable.h"

#include <pthread.h>

namespace advcpp{

class ConditionVariable;

class Mutex : public Uncopyable
{
	friend class ConditionVariable;
public:
	Mutex() throw(Mutex_Create_Failure_Exception);
	~Mutex() NOEXCEPT;
	
	void Lock() throw(Mutex_Lock_Unrecavoble_Exception);
	void Unlock() throw(Mutex_UnLock_Failure_Exception);
	
	bool IsLock() const;
private:
//	pthread_mutex_t* navtive_mutex();
	
private:
	pthread_mutex_t m_mutex;
	bool m_islcok;
};

}

#endif /*MUTEX_H*/ 

