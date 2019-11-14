#ifndef AGENTFACTORY_H
#define AGENTFACTORY_H

#include "commons.h"
#include "ID.h"
#include "Type.h"
#include "Location.h"


namespace smarthome{
class room;
class floor;
class IAgent;

class AgentFactory
{
public:
	
	shared_ptr<IAgent> AgentCreate(const string& lib, const string& id, const string& type, const string& room, const string& floor);
	
};

}

#endif /*AGENTFACTORY_H*/ 

