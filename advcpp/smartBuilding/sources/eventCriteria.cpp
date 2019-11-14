#include "eventCriteria.h"
#include "Type.h"
#include "Location.h"

namespace smarthome{

EventC::EventC(const Type& type, const Location& loc)
:	m_type(type.GetType())
,	m_room(loc.GetRoom())
,	m_floor(loc.GetFloor())
,	m_eventc(m_type + "," + m_room + "," + m_floor)
{}

const string& EventC::GetEventC() const
{
	return m_eventc;
}


}
