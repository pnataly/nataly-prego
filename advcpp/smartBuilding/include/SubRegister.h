#ifndef SUBREGISTER_H
#define SUBREGISTER_H

#include "commons.h"
#include "ISubLookUp.h"
#include "ISubsribe.h"

namespace smarthome{
class IEventHandler;

class SubRegister: public ISubLookUp, public ISubsribe
{
public:
	virtual ~SubRegister();
	
	virtual void Add(const string& type, shared_ptr<IEventHandler> control);
	virtual void Remove(const string& type, shared_ptr<IEventHandler> control);
	virtual const set<shared_ptr<IEventHandler> >& LookUp(const string& type) throw(LookUp_NotFound_Exception); 
	
private:
	map<string, set<shared_ptr<IEventHandler> > >m_map;
};

}

#endif /*SUBREGISTER_H*/ 
