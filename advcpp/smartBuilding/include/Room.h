#ifndef ROOM_H
#define ROOM_H

#include "commons.h"

namespace smarthome{

class Room
{
public:
	Room(const string& roomNum);
	
	const string& GetRoom() const;

private:
	string m_room;
};

}

#endif /*ROOM_H*/ 
