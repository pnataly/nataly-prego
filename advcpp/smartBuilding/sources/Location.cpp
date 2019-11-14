#include "Location.h"

namespace smarthome{

Location::Location(const Room& room, const Floor& floor)
:	m_room(room)
,	m_floor(floor)
{}

const string& Location::GetRoom() const
{
	return m_room.GetRoom();
}

const string& Location::GetFloor() const
{
	return m_floor.GetFloor();
}

}
