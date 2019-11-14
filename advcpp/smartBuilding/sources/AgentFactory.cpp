#include "AgentFactory.h"
#include "IAgent.h"
#include "Type.h"
#include "ID.h"
#include "Room.h"
#include "Floor.h"
#include "Location.h"

#include <dlfcn.h>
#include <iostream>

namespace smarthome{


shared_ptr<IAgent> AgentFactory::AgentCreate(const string& lib, const string& id, const string& type, const string& room, const string& floor)
{
	void* handle = dlopen(lib.c_str(), RTLD_LAZY);
	if(!handle)
	{
		std::cerr<<"Failed to open library: "<< dlerror()<<'\n';		
	}
	dlerror();	
	create_t* agentFunc=(create_t*) dlsym(handle,"create"); 		
	const char* dlErr=dlerror();
	if(dlErr) 
	{
		std::cerr<<"Failed to load the symbol: "<<dlErr<<'\n';
	}
	shared_ptr<IAgent> agent(agentFunc(ID(id), Type(type) ,Location(Room(room), Floor(floor))));
	return agent;
}

}
