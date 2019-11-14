#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "IDequeue.h"
#include "IEnqueue.h"
#include "WaitableQueue.h"

namespace smarthome{

template<typename T>
class EventQueue: public IDequeue<T>, public IEnqueue<T>
{
public:
	virtual ~EventQueue();
	virtual void Enqueue(T item);
	virtual T Dequeue();
	size_t Size();
private:
	advcpp::WaitableQueue<T> m_wq;
};




template<typename T>
EventQueue<T>::~EventQueue()
{}

template<typename T>
void EventQueue<T>::Enqueue(T item)
{
	m_wq.Enqueue(item);
}

template<typename T>
T EventQueue<T>::Dequeue()
{
	return m_wq.Dequeue();
}

template<typename T>
size_t EventQueue<T>::Size()
{
	return m_wq.Size();
}

}
#endif /*EVENTQUEUE_H*/ 
