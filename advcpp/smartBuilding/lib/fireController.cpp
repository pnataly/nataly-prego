#include "fireController.h"
#include "ID.h"
#include "Event.h"
#include "ISubsribe.h"
#include "eventCriteria.h"


namespace smarthome{

FireController::FireController(const ID& id, const Type& type, const Location& location)
:	m_type(type)
,	m_location(location)
,	m_fh(shared_ptr<FireHandler>(new FireHandler(id, type, location)))
{}

FireController::~FireController()
{
	DeRegister();
}

void FireController::Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq)
{
	m_sub=sub;
	Register();
	(void)enq;
}

void FireController::Register()
{
	shared_ptr<EventC> evc(new EventC(m_type, m_location));
	m_sub->Add(evc->GetEventC() ,shared_ptr<IEventHandler>(m_fh));
}

void FireController::DeRegister()
{
	shared_ptr<EventC> evc(new EventC(m_type, m_location));
	m_sub->Remove(evc->GetEventC(), m_fh);
}

extern "C" IAgent* create(const ID& id, const Type& type, const Location& location) 
{
    return new FireController(id, type, location);
}

extern "C" void destroy(IAgent* c) 
{
    delete c;
}

}
