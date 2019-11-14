#ifndef CONDITIONVARIABLE_H
#define CONDITIONVARIABLE_H

#include "Mutex.h"

#include <cassert>

namespace advcpp{

class ConditionVariable : public Uncopyable
{
public:
	ConditionVariable() throw(CondVar_Create_Failure_Exception);
	~ConditionVariable() NOEXCEPT;
	
	template<typename Predicate>
	void Wait(Mutex& mutex, Predicate pred);

	void Broadcast() throw(CondVar_Broadcast_Failure_Exception);
	void Signal() throw(CondVar_Signal_Failure_Exception);

private:
	void internal_wait(Mutex& mutex);
	
private:
	pthread_cond_t m_cond;
};




template<typename Predicate>
void ConditionVariable::Wait(Mutex& mutex, Predicate pred)
{
	assert(mutex.IsLock());
	while(pred()) 
	{
		internal_wait(mutex);
	}
}
	
}

#endif /*CONDITIONVARIABLE_H*/ 

