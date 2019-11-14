#ifndef SERVER_H
#define SERVER_H

#include "commons.h"
#include "EventQueue.h"
#include "dispEvent.h"
#include "SubRegister.h"
#include "serialPub.h"
#include "AgentFactory.h"
#include "Reader.h"

namespace smarthome{

class Server
{
public:
	Server();
	
	void Start(const string& file);
	void Run();

private:
	shared_ptr<EventQueue<shared_ptr<Event> > > m_evq;
	shared_ptr<SerialPub> m_ser;
	shared_ptr<SubRegister> m_reg;
	shared_ptr<DispEvent> m_dis;
	AgentFactory m_agentfactory;
	vector<shared_ptr<IAgent> > m_vec;
	Reader m_reader;
};

}
#endif /*SERVER_H*/
