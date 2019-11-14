#ifndef TASK_H
#define TASK_H

#include "commons.h"
#include "IRunnable.h"

namespace smarthome{
class Event;
template <typename T> class IEnqueue;

class Task : public advcpp::IRunnable
{
public:
	Task(shared_ptr<Event> event, shared_ptr<IEnqueue<shared_ptr<Event> > > enq);
	virtual ~Task();
	
	virtual void Run();

private:
	shared_ptr<Event> m_event;
	shared_ptr<IEnqueue<shared_ptr<Event> > > m_enq;
};
 
}

#endif /*TASK_H*/
