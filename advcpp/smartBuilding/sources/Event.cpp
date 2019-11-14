#include "Event.h"

namespace smarthome{

Event::Event(const Type& type, const Location& location)
:	m_type(type)
,	m_location(location)
{}

const Type& Event::GetType() const
{
	return m_type;
}

const Location& Event::GetLocation() const
{
	return m_location;
}

}
