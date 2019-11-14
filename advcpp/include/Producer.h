#ifndef PRODUCER_H
#define PRODUCER_H

#include "IRunnable.h"
#include "commons.h"
#include "WaitableQueue.h"

namespace advcpp{

class Cat{
public:
	Cat(size_t id) : m_id(id){}
	~Cat() {}
	
	size_t m_id;
};

template<typename T>
class Producer : public IRunnable
{
public:
	Producer(shared_ptr<WaitableQueue<T> > wq, int num);
	virtual ~Producer();
	
	virtual void Run();
	
private:
	int m_num;
	shared_ptr<WaitableQueue<T> > m_wq;
};




template<typename T>
Producer<T>::Producer(shared_ptr<WaitableQueue<T> > wq, int num)
:	m_num(num)
,	m_wq(wq)
{}


template<typename T>
Producer<T>::~Producer()
{}

template<typename T>
void Producer<T>::Run()
{
	for(int i =1; i <= m_num; ++i)
	{
		shared_ptr<Cat> cat(new Cat(i));
		m_wq->Enqueue(cat);

	}
}

}

#endif /*PRODUCER_H*/
 
