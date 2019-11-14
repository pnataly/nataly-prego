#ifndef FIREHANDLER_H
#define FIREHANDLER_H

#include "commons.h"
#include "IEventHandler.h"
#include "Type.h"
#include "ID.h"
#include "Location.h"

namespace smarthome
{
class Event;

class FireHandler : public IEventHandler
{
public:		
	FireHandler(const ID& id, const Type& type, const Location& location);
	virtual ~FireHandler();

	virtual void EventHandler(shared_ptr<Event> event);

private:
	ID m_id;
	Type m_type;
	Location m_location;
};

}

#endif /*FIREHANDLER_H*/
