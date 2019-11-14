#include "dispEvent.h"
#include "Event.h"
#include "IDequeue.h"
#include "IPubMech.h"

namespace smarthome{

DispEvent::DispEvent(shared_ptr<IDequeue<shared_ptr<Event> > > deq, shared_ptr<ISubLookUp> look, shared_ptr<IPubMech> pub)
:	m_deq(deq)
,	m_pub(look, pub)	
{}

DispEvent::~DispEvent()
{}

void DispEvent::Dispatch()
{
	while(1)
	{
		m_pub.Publish(m_deq->Dequeue()); 	
	}
}

void DispEvent::Run()
{
	Dispatch();
}

}
