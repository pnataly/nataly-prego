#ifndef FLOOR_H
#define FLOOR_H

#include "commons.h"

namespace smarthome{

class Floor
{
public:
	Floor(const string& floorNum);
	
	const string& GetFloor() const;

private:
	string m_floor;
};

}

#endif /*FLOOR_H*/ 
