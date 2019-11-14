#include "smokeSensor.h"
#include "IEnqueue.h"
#include "Event.h"
#include "Thread.h"

namespace smarthome{

SmokeSensor::SmokeSensor(const ID& id, const Type& type, const Location& loc)
:	m_id(id)	
,	m_type(type)
,	m_location(loc)
{} 

SmokeSensor::~SmokeSensor()
{}

void SmokeSensor::Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq)
{
	m_enq=enq;
	(void)sub;
	shared_ptr<Event> event(new Event(m_type, m_location));
	try{
		m_task = shared_ptr<Task>(new Task(event, enq));
	}catch(const std::bad_alloc&)
	{
		delete event.get();
		return;
	}
	advcpp::Thread task(m_task);
	task.Join();
}


extern "C" IAgent* create(const ID& id, const Type& type, const Location& loc) 
{
    return new SmokeSensor(id, type, loc);
}

extern "C" void destroy(IAgent* s) 
{
    delete s;
}

}
