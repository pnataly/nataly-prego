#include "AgentManager.h"
#include "Type.h"
#include "ID.h"
#include "Room.h"
#include "Floor.h"
#include "Location.h"

#include <dlfcn.h>
#include <iostream>

namespace smarthome{

AgentManager::AgentManager(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq)
:	m_enq(enq)
,	m_sub(sub)
{}


void AgentManager::Start()
{
	LoadLibraries();
	CreateSensor("1", "smoke", "1_a", "2.5");
	CreateController("12", "smoke", "1_a", "2.5");
//	CreateSensor("2", "fire", "3_b", "8");
	Run();
}

void AgentManager::LoadLibraries()
{
	void* sensor = dlopen("../lib/libSS.so", RTLD_LAZY);
	if(!sensor)
	{
		std::cerr<<"Failed to open library: "<< dlerror()<<'\n';				
	}
	dlerror();	
	create_t* sensFunc=(create_t*) dlsym(sensor,"create"); 		
	const char* dlErr=dlerror();
	if(dlErr) 
	{
		std::cerr<<"Failed to load the symbol: "<<dlErr<<'\n';
	}
	m_sensFunc.push_back(sensFunc);

//	dlclose(sensor); //after join

	sensor = dlopen("../lib/libFS.so", RTLD_LAZY);
	if(!sensor)
	{
		std::cerr<<"Failed to open library: "<< dlerror()<<'\n';
	}
	dlerror();	

	sensFunc=(create_t*) dlsym(sensor,"create");
	dlErr=dlerror();
	if(dlErr) 
	{
		std::cerr<<"Failed to load the symbol: "<<dlErr<<'\n';
	}
	m_sensFunc.push_back(sensFunc);
//	dlclose(sensor);

	void* control=dlopen("../lib/libSC.so",RTLD_LAZY);
	if(!control)
	{
		std::cerr<<"Failed to open library: "<< dlerror()<<'\n';
	}
	dlerror();	

	create_t* contFunc=(create_t*) dlsym(control,"create"); 
	dlErr=dlerror();
	if(dlErr) 
	{
		std::cerr<<"Failed to load the symbol: "<<dlErr<<'\n';
	}
	m_contFunc.push_back(contFunc);
//	dlclose(control);

	control=dlopen("../lib/libFC.so",RTLD_LAZY);
	if(!control)
	{
		std::cerr<<"Failed to open library: "<< dlerror()<<'\n';
	}
	dlerror();	

	contFunc=(create_t*) dlsym(control,"create");
	dlErr=dlerror();
	if(dlErr) 
	{
		std::cerr<<"Failed to load the symbol: "<<dlErr<<'\n';
	}
	m_contFunc.push_back(contFunc);
//	dlclose(control);
}

void AgentManager::CreateSensor(const string& id, const string& type, const string& floor, const string& room)
{	
std::cout<<m_sensFunc.size()<<'\n';
	Room r(room);
	Floor f(floor);
	Location location(r,f);
	ID i(id);
	Type ty(type);

	vector<create_t*>::iterator it;		
	for(it = m_sensFunc.begin(); it != m_sensFunc.end() ; ++it)
	{
		shared_ptr<IAgent> sen((*it)(i, ty ,location); //m_enq));
		//sen->Send();
		shared_ptr<advcpp::Thread> st(new advcpp::Thread(sen));
		m_thsensors.push_back(st);
		std::cout << "sensor make" << '\n';
		//st->Join();
		//std::cout << "sensor thread run" << '\n';
	}
std::cout<<m_thsensors.size()<<'\n';
} 

void AgentManager::CreateController(const string& id, const string& type, const string& floor, const string& room)
{	
std::cout<<m_contFunc.size()<<'\n';
	Room r(room);
	Floor f(floor);
	Location location(r,f);
	ID i(id);
	Type ty(type);

	vector<create_t*>::iterator it;			
	for(it = m_contFunc.begin(); it != m_contFunc.end() ; ++it)
	{
		shared_ptr<IAgent> con((*it)(i, ty ,location); //m_sub));
		//m_controllers.push_back(con);
		std::cout << "controller make" << '\n';
	}
}

void AgentManager::Run() //loop on the sensors threads vector and run them
{
	vector<shared_ptr<advcpp::Thread> >::iterator it;				
	for(it = m_thsensors.begin(); it != m_thsensors.end(); ++it)
	{
		(*it)->Join();
	}
	std::cout<<"runn"<<'\n';
} 

}

