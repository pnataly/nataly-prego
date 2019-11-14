#ifndef EVENT_H
#define EVENT_H

#include "commons.h"
#include "Type.h"
#include "Location.h"

namespace smarthome{

class Event
{
public:
	Event(const Type& type, const Location& location);
	
	const Type& GetType() const;
	const Location& GetLocation() const;
	
private:
	Type m_type;
	Location m_location;
};

}

#endif /*EVENT_H*/ 
