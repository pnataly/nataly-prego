#include "smokeController.h"
#include "ID.h"
#include "Event.h"
#include "ISubsribe.h"
#include "eventCriteria.h"

namespace smarthome{

SmokeController::SmokeController(const ID& id, const Type& type, const Location& location)
:	m_type(type)
,	m_location(location)
,	m_sh(shared_ptr<SmokeHandler>(new SmokeHandler(id, type, location)))
{}

SmokeController::~SmokeController()
{
	DeRegister();
}

void SmokeController::Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq)
{
	m_sub=sub;
	(void)enq;
	Register();
}

void SmokeController::Register()
{
	shared_ptr<EventC> evc(new EventC(m_type, m_location));
	m_sub->Add(evc->GetEventC() ,shared_ptr<IEventHandler>(m_sh));
}

void SmokeController::DeRegister()
{
	shared_ptr<EventC> evc(new EventC(m_type, m_location));
	m_sub->Remove(evc->GetEventC(), m_sh);
}

}
