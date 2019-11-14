#include "Room.h"

namespace smarthome{

Room::Room(const string& roomNum)
:	m_room(roomNum)
{}

const string& Room::GetRoom() const
{
	return m_room;
}

}
