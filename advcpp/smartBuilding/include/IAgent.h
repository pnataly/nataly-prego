#ifndef IAGENT_H
#define IAGENT_H

#include "commons.h"

namespace smarthome{
class ID;
class Type;
class Event;
class Location;
class ISubsribe;
template <typename T> class IEnqueue;

class IAgent
{
public:
	virtual ~IAgent(){}
	
	virtual void Init(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > evq) = 0;
};
 
typedef IAgent* create_t(const ID& id, const Type& type, const Location& loc);
typedef void Destroy_t(IAgent*); 

}

#endif /*IAGENT_H*/
