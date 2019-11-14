#include "ConditionVariable.h"
#include "Mutex.h"


namespace advcpp{


ConditionVariable::ConditionVariable() throw(CondVar_Create_Failure_Exception)
{
	if(int res = pthread_cond_init(&m_cond,0))
	{
		throw CondVar_Create_Failure_Exception(res);
	}
}


ConditionVariable::~ConditionVariable() NOEXCEPT
{
	if(pthread_cond_destroy(&m_cond))
	{
		assert(false and "destroy conditionVariable fail");
	}
}


void ConditionVariable::internal_wait(Mutex& mutex)
{
	if(int res = pthread_cond_wait(&m_cond, &mutex.m_mutex))
	{
		throw CondVar_Wait_Failure_Exception(res);
	}
}


void ConditionVariable::Broadcast() throw(CondVar_Broadcast_Failure_Exception)
{
	if(int res = pthread_cond_broadcast(&m_cond))
	{
		throw CondVar_Broadcast_Failure_Exception(res);
	}
}


void ConditionVariable::Signal() throw(CondVar_Signal_Failure_Exception)
{
	if(int res = pthread_cond_signal(&m_cond))
	{
		throw CondVar_Signal_Failure_Exception(res);
	}
}

}

