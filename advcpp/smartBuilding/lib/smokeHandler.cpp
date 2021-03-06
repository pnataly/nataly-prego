#include "smokeHandler.h"
#include "Event.h"

#include <iostream>

namespace smarthome{ 

SmokeHandler::SmokeHandler(const ID& id, const Type& type, const Location& location)
:	m_id(id)
,	m_type(type)
,	m_location(location)
{}


SmokeHandler::~SmokeHandler()
{}

void SmokeHandler::EventHandler(shared_ptr<Event> event)
{
	std::cout << m_type.GetType()<<" controller id: " << m_id.GetId() << " handle event of " << event->GetType().GetType() << '\n';
}

}
