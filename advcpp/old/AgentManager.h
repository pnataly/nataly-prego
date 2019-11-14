#ifndef AGENTMANAGER_H
#define AGENTMANAGER_H

#include "smokeController.h"
#include "smokeHandler.h"
#include "fireController.h"
#include "fireHandler.h"
//#include "ISensor.h"
//#include "IController.h"
#include "IAgent.h"
#include "IEnqueue.h"
#include "ISubsribe.h"
#include "commons.h"
#include "Thread.h"


namespace smarthome{

class AgentManager
{
public:
	AgentManager(shared_ptr<ISubsribe> sub, shared_ptr<IEnqueue<shared_ptr<Event> > > enq);
	void Start(); //will call to LoadLibraries function - and the sensors and the controlles upload to the application.
	
private:
	void LoadLibraries();
	void Run();
	void CreateSensor(const string& id, const string& type, const string& floor, const string& room);
	void CreateController(const string& id, const string& type, const string& floor, const string& room);
//	void ShutDown() //close the library and ditach the threads
	
private:
	vector<create_t*> m_sensFunc;
	vector<create_t*> m_contFunc;
	vector<shared_ptr<advcpp::Thread> > m_thsensors;		//pool of senors threads
	shared_ptr<IEnqueue<shared_ptr<Event> > > m_enq; 		//for sensor
	shared_ptr<ISubsribe> m_sub;							//for controller
//	vector<shared_ptr<IAgent> > m_controllers; 				//vector that contain all the controllers
};

}

#endif /*AGENTMANAGER_H*/
