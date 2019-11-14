#ifndef FIRESENSOR_H
#define FIRESENSOR_H

#include "IAgent.h"
#include "commons.h"
#include "ID.h"
#include "Type.h"
#include "Location.h"
#include "Task.h"

namespace smarthome{
class Event;
template <typename T> class IEnqueue;

class FireSensor : public IAgent  
{
public:
	FireSensor(const ID& id, const Type& type, const Location& loc);
	virtual ~FireSensor();
	
	virtual void Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq);

private:
	ID m_id;
	Type m_type;
	Location m_location;
	shared_ptr<IEnqueue<shared_ptr<Event> > > m_enq;
	shared_ptr<Task> m_task;
};

}
#endif /*FIRESENSOR_H*/ 

