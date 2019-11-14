#ifndef ALLOPTIONS_H
#define ALLOPTIONS_H

#include "commons.h"

namespace smarthome{
class Event;
class Type;
class Location;

class AllOptions
{
public:
	AllOptions(shared_ptr<Event> event);
	
	void MakeOptions();
	const vector<string>& GetOptions() const;
	
private:
	shared_ptr<Event> m_event;
	vector<string> m_options;
	string m_type;
	string m_room;
	string m_floor;
};

}
#endif /*ALLOPTIONS_H*/
