#include "Task.h"
#include "Event.h"
#include "IEnqueue.h"

namespace smarthome{

Task::Task(shared_ptr<Event> event, shared_ptr<IEnqueue<shared_ptr<Event> > > enq)
:	m_event(event)
,	m_enq(enq)
{}


Task::~Task()
{}

void Task::Run()
{
	m_enq->Enqueue(m_event);
}

}
