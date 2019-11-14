#include "Thread.h"
#include "commons.h" //shred_ptr
#include "IRunnable.h"

#include <pthread.h>
#include <unistd.h> //sleep
#include <iostream>	//cerr
#include <cassert> 


namespace advcpp{

Thread::Thread(shared_ptr<IRunnable> runnable) throw (Thread_Create_Failure_Exception)
:	m_id(0)
,	m_runnable(runnable)
,	m_flag(false)
{
	if(!runnable)
	{
		throw std::invalid_argument("invalid argument");
	}
	if(int res = pthread_create(&m_id ,0, &work, &m_runnable) != 0)
	{
		throw Thread_Create_Failure_Exception(res);
	}
}


void* Thread::work(void* p)
{
	assert(p);
	shared_ptr<IRunnable> runnablep = *reinterpret_cast<shared_ptr<IRunnable>* >(p);
	try{
		runnablep->Run();
	}
	catch(std::exception const& x){
		std::cerr << x.what();
		assert(false);
	}
	catch(...){
		std::cerr << "unkown exception";
		assert(false);
	}
	return 0;
}

Thread::~Thread() NOEXCEPT
{
	if(!m_flag)
	{
		assert(false and "DTOR");
	}
}

void Thread::Join()
{
	if(!m_flag)
	{
		assert(pthread_join(m_id, 0) == 0);
		m_flag = true;
	}
	else
	{
		assert(false and "already join");
	}
}

void Thread::Detach()
{
	if(!m_flag)
	{
		assert(pthread_detach(m_id) == 0);
		m_flag = true;
	}
}

void Thread::Yield()
{
	pthread_yield(); 
}

void Thread::Sleep(unsigned int seconds)
{
	while(seconds)
	{
		seconds = sleep(seconds);
	}
	
}

}

