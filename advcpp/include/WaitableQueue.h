#ifndef WAITABLEQUEUE_H
#define WAITABLEQUEUE_H

#include "Mutex.h"
#include "ConditionVariable.h"
#include "commons.h"

#include <queue>

namespace advcpp{
using std::queue;

template <class U>
class Predicate;


template <typename T>
class WaitableQueue
{
template<class U> friend class Predicate;
public:
	void Enqueue(const T& item);
	T Dequeue();
	
	bool IsEmpty();
	size_t Size();
	
private:
	bool isempty() const;

private:
	queue<T> m_queue;
	Mutex m_mutex;
	ConditionVariable m_cond;
};

template<typename U>
class Predicate
{
public:

	Predicate(WaitableQueue<U>& wq)
	:	m_wq(wq)
	{}
	bool operator()()
	{
		return m_wq.isempty();
	}
	
private:
	WaitableQueue<U>& m_wq;
};




template <typename T>
void WaitableQueue<T>::Enqueue(const T& item)
{
	m_mutex.Lock();
	try{
		m_queue.push(item);
	}
	catch(std::exception){
		m_mutex.Unlock();
		throw;
	}
	
	m_mutex.Unlock();
	m_cond.Broadcast();
}

template <typename T>
T WaitableQueue<T>::Dequeue()
{
	m_mutex.Lock();

	m_cond.Wait(m_mutex, Predicate<T>(*this));

	T item = m_queue.front();
	try{
		m_queue.pop();
	}
	catch(std::exception){
		m_mutex.Unlock();
		throw;
	}
	m_mutex.Unlock();
	return item;
}

template <typename T>
bool WaitableQueue<T>::IsEmpty()
{
	m_mutex.Lock();
	bool res = m_queue.empty();
	m_mutex.Unlock();
	return res;
}


template <typename T>
size_t WaitableQueue<T>::Size()
{
	m_mutex.Lock();
	size_t size = m_queue.size();
	m_mutex.Unlock();
	return size;
}

template <typename T>
bool WaitableQueue<T>::isempty() const
{
	return m_queue.empty();
}

}

#endif /*WAITABLEQUEUE_H*/ 

