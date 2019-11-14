#include "Server.h"
#include "Thread.h"
#include "IAgent.h"

namespace smarthome{

Server::Server()
{
	try{
		m_evq = shared_ptr<EventQueue<shared_ptr<Event> > >(new EventQueue<shared_ptr<Event> >);
		m_ser = shared_ptr<SerialPub>(new SerialPub);
		m_reg = shared_ptr<SubRegister> (new SubRegister);
		m_dis = shared_ptr<DispEvent>(new DispEvent(m_evq, m_reg, m_ser));
	}catch(const std::bad_alloc&)
	{
		return;
	}
}

void Server::Start(const string& file)
{
	m_reader.Read(file.c_str());
	map<string, vector<string> > rmap = m_reader.GetMap();
	map<string, vector<string> >::iterator mit;

	for(mit = rmap.begin(); mit != rmap.end(); ++mit)
	{
		vector<string> vec = mit->second;
		m_vec.push_back(m_agentfactory.AgentCreate(vec[0], vec[1], vec[2], vec[3], vec[4]));
	}
}

void Server::Run()
{
	vector<shared_ptr<IAgent> > ::iterator vit;
	for(vit = m_vec.begin(); vit != m_vec.end(); ++vit)
	{
		(*vit)->Init(m_reg, m_evq);
	}	
	
	advcpp::Thread dispatcher(m_dis);
	dispatcher.Join();
}

}
