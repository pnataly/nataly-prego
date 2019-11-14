#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include "IEventHandler.h"
#include "ISubsribe.h"

namespace smarthome{
class ID;
class Type;
class Location;
class Event;
class ISubsribe;

class IController
{
public:
	virtual ~IController(){}
	virtual void Register()= 0;
	virtual void DeRegister() = 0;
};

typedef IController* create_t(const ID& id, const Type& type, const Location& location, shared_ptr<ISubsribe> sub);
typedef void destroy_t(IController*);

}

#endif /*ICONTROLLER_H*/ 

