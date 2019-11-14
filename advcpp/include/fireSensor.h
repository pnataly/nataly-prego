#ifndef FIRESENSOR_H
#define FIRESENSOR_H

#include "ISensor.h"
#include "commons.h"

namespace smarthome{

class FireSensor : public ISensor 
{
public:
	FireSensor(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq);
	virtual ~FireSensor();
	
	virtual void Run();
	
private:
	virtual void Send();

};

}
#endif /*FIRESENSOR_H*/ 

