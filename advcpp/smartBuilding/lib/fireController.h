#ifndef FIRECONTROLLER_H
#define FIRECONTROLLER_H

#include "commons.h"
#include "IAgent.h"
#include "fireHandler.h"
#include "Type.h"
#include "Location.h"

namespace smarthome{
class ID;
class Event;
class ISubsribe;

class FireController : public IAgent
{
public:
	FireController(const ID& id, const Type& type, const Location& location);
	virtual ~FireController();
	
	virtual void Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq);
	
private:
	void Register();
	void DeRegister();
	
private:
	Type m_type;
	Location m_location;
	shared_ptr<IEventHandler> m_fh;
	shared_ptr<ISubsribe> m_sub;
};

}

#endif /*FIRECONTROLLER_H*/ 

