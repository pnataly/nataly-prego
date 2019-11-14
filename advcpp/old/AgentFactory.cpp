#include "AgentFactory.h"
#include "Type.h"
#include "ID.h"
#include "Location.h"

#include <dlfcn.h>
#include <iostream>

namespace smarthome{

AgentFactory::AgentFactory(const string& lib, const string& id, const string& type, const string& room, const string& floor)
:	m_id(id)
,	m_type(type)
,	m_location(Room(room), Floor(floor))
,	m_lib(lib)
{}

shared_ptr<IAgent> AgentFactory::AgentCreate()
{
	void* agent = dlopen(m_lib, RTLD_LAZY);
	if(!agent)
	{
		std::cerr<<"Failed to open library: "<< dlerror()<<'\n';				
	}
	dlerror();	
	create_t* agentFunc=(create_t*) dlsym(agent,"create"); 		
	const char* dlErr=dlerror();
	if(dlErr) 
	{
		std::cerr<<"Failed to load the symbol: "<<dlErr<<'\n';
	}
	shared_ptr<IAgent> agent(agentFunc(m_id, m_type ,m_location);
	return agent;
}

}
