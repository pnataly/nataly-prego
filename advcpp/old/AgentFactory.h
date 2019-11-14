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
	AgentFactory(const string& lib, const string& id, const string& type, const string& room, const string& floor);
	
	shared_ptr<IAgent> AgentCreate();
	
private:
	ID m_id;
	Type m_type;
	Location m_location;
	string m_lib;
	
};

}

#endif /*AGENTFACTORY_H*/ 

