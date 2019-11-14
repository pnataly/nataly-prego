#ifndef EVENTCRITERIA_H
#define EVENTCRITERIA_H

#include "commons.h"

namespace smarthome{
class Type;
class Location;

class EventC
{
public:
	EventC(const Type& type, const Location& loc);
	
	const string& GetEventC() const;

private:
	string m_type;
	string m_room;
	string m_floor;
	string m_eventc;
};

}

#endif /*EVENTCRITERIA_H*/ 
