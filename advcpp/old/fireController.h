#ifndef FIRECONTROLLER_H
#define FIRECONTROLLER_H

#include "commons.h"
#include "IController.h"
#include "fireHandler.h"
#include "Type.h"
#include "Location.h"

namespace smarthome{
class ID;
class Event;
class ISubsribe;

class FireController : public IController
{
public:
	FireController(const ID& id, const Type& type, const Location& location, shared_ptr<ISubsribe> sub);
	virtual ~FireController();
	
private:
	virtual void Register();
	virtual void DeRegister();
	
private:
	Type m_type;
	Location m_location;
	shared_ptr<IEventHandler> m_fh;
	shared_ptr<ISubsribe> m_sub;
};

}

#endif /*FIRECONTROLLER_H*/ 

