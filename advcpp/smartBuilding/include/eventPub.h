#ifndef EVENTPUB_H
#define EVENTPUB_H

#include "commons.h"

namespace smarthome{
class IPubMech;
class ISubLookUp;
class Event;

class EventPub
{
public:
	EventPub(shared_ptr<ISubLookUp> look, shared_ptr<IPubMech> pub);
	void Publish(shared_ptr<Event> event); 
	
private:
	shared_ptr<ISubLookUp> m_look;
	shared_ptr<IPubMech> m_pub;
};

}

#endif /*EVENTPUB_H*/ 

