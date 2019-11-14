#ifndef LOCATION_H
#define LOCATION_H

#include "commons.h"
#include "Room.h"
#include "Floor.h"

namespace smarthome{

class Location
{
public:
	Location(const Room& room, const Floor& floor);
	
	const string& GetRoom() const;
	const string& GetFloor() const;
	
private:
	Room m_room;
	Floor m_floor;
};

}

#endif /*LOCATION_H*/ 
