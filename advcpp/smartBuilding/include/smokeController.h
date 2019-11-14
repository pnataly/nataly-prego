#ifndef SMOKECONTROLLER_H
#define SMOKECONTROLLER_H

#include "commons.h"
#include "smokeHandler.h"
//#include "IController.h"
#include "IAgent.h"
#include "Type.h"
#include "Location.h"

namespace smarthome{
class Event;
class ISubsribe;

class SmokeController : public IAgent
{
public:
	SmokeController(const ID& id, const Type& type, const Location& location);
	virtual ~SmokeController();
	
	virtual void Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq);

private:
	void Register();
	void DeRegister();
	
private:
	Type m_type;
	Location m_location;
	shared_ptr<IEventHandler> m_sh;
	shared_ptr<ISubsribe> m_sub;
};

extern "C" IAgent* create(const ID& id, const Type& type, const Location& location) 
{
    return new SmokeController(id, type, location);
}

extern "C" void destroy(IAgent* c) 
{
    delete c;
}

}

#endif /*SMOKECONTROLLER_H*/ 

