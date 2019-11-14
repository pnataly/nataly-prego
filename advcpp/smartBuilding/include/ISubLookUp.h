#ifndef ISUBLOOKUP_H
#define ISUBLOOKUP_H

#include "commons.h"

namespace smarthome{
class IEventHandler;

class ISubLookUp
{
public:
	virtual ~ISubLookUp(){}

	virtual const set<shared_ptr<IEventHandler> >& LookUp(const string& type) = 0;
};

}

#endif /*ISUBLOOKUP_H*/ 
