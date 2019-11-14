#include "serialPub.h"
#include "IEventHandler.h"
#include "Event.h"

namespace smarthome{

SerialPub::~SerialPub()
{}

void SerialPub::Pub(const set<shared_ptr<IEventHandler> >& mset, shared_ptr<Event> event)
{
	set<shared_ptr<IEventHandler> >::iterator it;
	for(it=mset.begin(); it != mset.end(); ++it)
	{
		(*it)->EventHandler(event);
	} 
}


}
