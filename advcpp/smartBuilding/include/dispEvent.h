#ifndef DISPEVENT_H
#define DISPEVENT_H

#include "eventPub.h"
#include "commons.h"
#include "IRunnable.h"

namespace smarthome{
template <typename T> class IDequeue;
class Controller;
class IPubMech;

class DispEvent : public advcpp::IRunnable
{
public:
	DispEvent(shared_ptr<IDequeue<shared_ptr<Event> > > deq, shared_ptr<ISubLookUp> look, shared_ptr<IPubMech> pub);
	virtual ~DispEvent();
	
	virtual void Run();
	
private:
	void Dispatch();
	
private:
	shared_ptr<IDequeue<shared_ptr<Event> > > m_deq;
	EventPub m_pub;
};

}

#endif /*DISPEVENT_H*/ 
