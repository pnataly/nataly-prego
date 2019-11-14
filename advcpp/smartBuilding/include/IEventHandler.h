#ifndef IEVENTHANDLER_H
#define IEVENTHANDLER_H

#include "commons.h"

namespace smarthome{
class Event;

class IEventHandler
{
public:
	virtual ~IEventHandler(){}
	
	virtual void EventHandler(shared_ptr<Event> event) = 0;
};

}


#endif /*IEVENTHANDLER_H*/ 
