#ifndef THREAD_H
#define THREAD_H

#include "commons.h"
#include "exceptions.h"

namespace advcpp{
class IRunnable;

class Thread
{
public:
	Thread(shared_ptr<IRunnable>) throw (Thread_Create_Failure_Exception);
	~Thread() NOEXCEPT; 	
	
	void Join();
	void Detach();
	static void Yield();
	static void Sleep(unsigned int seconds);
	static int CPU_Cores();
	
private:
	Thread(const Thread& th);
	Thread& operator= (const Thread& th);
	static void* work(void*);
	
private:
	pthread_t m_id;
	shared_ptr<IRunnable> m_runnable;
	bool m_flag;
};

}

#endif /*THREAD_H*/ 
