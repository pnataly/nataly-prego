#ifndef CONSUMER_H
#define CONSUMER_H

#include "IRunnable.h"
#include "commons.h"
#include "WaitableQueue.h"

#include <iostream>

namespace advcpp{

template<typename T>
class Consumer : public IRunnable
{
public:
	Consumer(shared_ptr<WaitableQueue<T> > wq, int m_num);
	virtual ~Consumer();
	
	virtual void Run();
	
private:
	shared_ptr<WaitableQueue<T> > m_wq;
	int m_num;
};




template<typename T>
Consumer<T>::Consumer(shared_ptr<WaitableQueue<T> > wq, int num)
:	m_wq(wq)
,	m_num(num)
{}


template<typename T>
Consumer<T>::~Consumer()
{}

template<typename T>
void Consumer<T>::Run()
{
	shared_ptr<Cat> cat(new Cat(0));
	for(int i = 1; i <= m_num; ++i)
	{
		cat = m_wq->Dequeue(); 
		std::cout << cat->m_id << ", ";
	}
	std::cout<<'\n';
}


}

#endif /*CONSUMER_H*/ 

