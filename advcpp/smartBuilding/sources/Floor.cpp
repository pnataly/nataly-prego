#include "Floor.h"

namespace smarthome{

Floor::Floor(const string& floorNum)
:	m_floor(floorNum)
{}

const string& Floor::GetFloor() const
{
	return m_floor;
}

}
