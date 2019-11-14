#include "smokeSensor.h"
#include "IEnqueue.h"
#include "Event.h"


namespace smarthome{

SmokeSensor::SmokeSensor(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq)
: ISensor(id, type, loc, enq)
{}

SmokeSensor::~SmokeSensor()
{}

void SmokeSensor::Send()
{
	m_enq->Enqueue(shared_ptr<Event>(new Event(m_type, m_location)));
}

void SmokeSensor::Run()
{
	Send();
}

extern "C" ISensor* create(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq) 
{
    return new SmokeSensor(id, type, loc, enq);
}

extern "C" void destroy(ISensor* s) 
{
    delete s;
}

}
