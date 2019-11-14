#ifndef IPUBMECH_H
#define IPUBMECH_H

#include "commons.h"

namespace smarthome{
class IEventHandler;
class Event;

class IPubMech
{
public:
	virtual ~IPubMech(){}
	
	virtual void Pub(const set<shared_ptr<IEventHandler> >& mset, shared_ptr<Event> event) = 0;
};

}
#endif /*IPUBMECH_H*/ 

