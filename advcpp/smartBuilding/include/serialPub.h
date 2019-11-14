#ifndef SERIALPUB_H
#define SERIALPUB_H

#include "IPubMech.h"

namespace smarthome{

class SerialPub : public IPubMech
{
public:
	virtual ~SerialPub();
	
	virtual void Pub(const set<shared_ptr<IEventHandler> >& mset, shared_ptr<Event> event);
};

}

#endif /*SERIALPUB_H*/ 
