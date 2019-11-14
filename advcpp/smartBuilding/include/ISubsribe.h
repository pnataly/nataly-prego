#ifndef ISUBSCRIBE_H
#define ISUBSCRIBE_H

#include "commons.h"

namespace smarthome{
class IEventHandler;

class ISubsribe
{
public:
	virtual ~ISubsribe(){}

	virtual void Add(const string& type, shared_ptr<IEventHandler> control) = 0;
	virtual void Remove(const string& type, shared_ptr<IEventHandler> control) = 0;
};

}

#endif /*ISUBSCRIBE_H*/ 
