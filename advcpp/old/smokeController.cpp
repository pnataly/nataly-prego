#include "smokeController.h"
#include "ID.h"
#include "Event.h"
#include "ISubsribe.h"
#include "eventCriteria.h"

namespace smarthome{

SmokeController::SmokeController(const ID& id, const Type& type, const Location& location, shared_ptr<ISubsribe> sub)
:	m_type(type)
,	m_location(location)
,	m_sh(shared_ptr<SmokeHandler>(new SmokeHandler(id, type, location)))
,	m_sub(sub)
{
	Register();
}

SmokeController::~SmokeController()
{
	DeRegister();
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
