#ifndef SMOKEHANDLER_H
#define SMOKEHANDLER_H

#include "commons.h"
#include "IEventHandler.h"
#include "Type.h"
#include "ID.h"
#include "Location.h"

namespace smarthome
{
class Event;

class SmokeHandler : public IEventHandler
{
public:		
	SmokeHandler(const ID& id, const Type& type, const Location& location);
	virtual ~SmokeHandler();

	virtual void EventHandler(shared_ptr<Event> event);

private:
	ID m_id;
	Type m_type;
	Location m_location;
};

}
#endif /*SMOKEHANDLER_H*/
