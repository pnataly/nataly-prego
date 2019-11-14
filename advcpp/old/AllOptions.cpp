#include "AllOptions.h"
#include "Event.h"
#include "Type.h"
#include "Location.h"

namespace smarthome
{

AllOptions::AllOptions(shared_ptr<Event> event)
:	m_event(event)
,	m_type(event->GetType().GetType())
,	m_room(event->GetLocation().GetRoom())
,	m_floor(event->GetLocation().GetFloor())
{}

void AllOptions::MakeOptions()
{
	string all = m_type+","+m_room+","+m_floor;
	m_options.push_back(all);
	string type = m_type+", "+", ";
	m_options.push_back(type);
	string room = " ,"+m_room+", ";
	m_options.push_back(room);
	string floor = " , ,"+m_floor;
	m_options.push_back(floor);
	string tr = m_type+","+m_room+", ";
	m_options.push_back(tr);
	string tf = m_type+", ,"+m_floor;
	m_options.push_back(tf);
	string rf = " ,"+m_room+","+m_floor;
	m_options.push_back(rf);
}

const vector<string>& AllOptions::GetOptions() const
{
	return m_options;
}

}
