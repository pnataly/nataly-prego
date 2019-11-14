#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

#include "IAgent.h"
#include "commons.h"
#include "ID.h"
#include "Type.h"
#include "Location.h"
#include "Task.h"

namespace smarthome{
class Event;
template <typename T> class IEnqueue;

class SmokeSensor : public IAgent 
{
public:
	SmokeSensor(const ID& id, const Type& type, const Location& loc);
	virtual ~SmokeSensor();
	
	virtual void Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq);

private:
	ID m_id;
	Type m_type;
	Location m_location;
	shared_ptr<IEnqueue<shared_ptr<Event> > > m_enq;
	shared_ptr<Task> m_task;
};

}
#endif /*SMOKESENSOR_H*/ 

