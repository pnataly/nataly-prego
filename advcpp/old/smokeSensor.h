#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H

#include "ISensor.h"
#include "commons.h"

namespace smarthome{

class SmokeSensor : public ISensor 
{
public:
	SmokeSensor(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq);
	virtual ~SmokeSensor();
	
	virtual void Run();
	
private:
	virtual void Send();

};

}
#endif /*SMOKESENSOR_H*/ 

