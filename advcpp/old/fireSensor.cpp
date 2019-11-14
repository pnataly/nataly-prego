#include "fireSensor.h"
#include "IEnqueue.h"
#include "Event.h"


namespace smarthome{

FireSensor::FireSensor(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq)
: ISensor(id, type, loc, enq)
{}

FireSensor::~FireSensor()
{}

void FireSensor::Send()
{
	m_enq->Enqueue(shared_ptr<Event>(new Event(m_type, m_location)));
}

void FireSensor::Run()
{
	Send();
}

extern "C" ISensor* create(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq) 
{
    return new FireSensor(id, type, loc, enq);
}

extern "C" void destroy(ISensor* s) 
{
    delete s;

} 

}
