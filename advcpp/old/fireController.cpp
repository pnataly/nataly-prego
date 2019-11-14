#include "fireController.h"
#include "ID.h"
#include "Event.h"
#include "ISubsribe.h"
#include "eventCriteria.h"


namespace smarthome{

FireController::FireController(const ID& id, const Type& type, const Location& location, shared_ptr<ISubsribe> sub)
:	m_type(type)
,	m_location(location)
,	m_fh(shared_ptr<FireHandler>(new FireHandler(id, type, location)))
,	m_sub(sub)
{
	Register();
}

FireController::~FireController()
{
	DeRegister();
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

extern "C" IController* create(const ID& id, const Type& type, const Location& location, shared_ptr<ISubsribe> sub) 
{
    return new FireController(id, type, location, sub);
}

extern "C" void destroy(IController* c) 
{
    delete c;
}

}
