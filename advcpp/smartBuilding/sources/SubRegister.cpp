#include "SubRegister.h"
#include "IEventHandler.h"

namespace smarthome{

SubRegister::~SubRegister()
{}


void SubRegister:: Add(const string& type, shared_ptr<IEventHandler> control)
{
	map<string, set<shared_ptr<IEventHandler> > >::iterator itr = m_map.find(type);
	if (itr != m_map.end())
	{
		itr->second.insert(control);
	}
	else
	{
		set<shared_ptr<IEventHandler> > temp;
		temp.insert(control);
		m_map.insert(make_pair(type, temp));
	}
}


const set<shared_ptr<IEventHandler> >& SubRegister::LookUp(const string& type) throw(LookUp_NotFound_Exception)
{
	map<string, set<shared_ptr<IEventHandler> > >::iterator it = m_map.find(type);
	if (it != m_map.end())
	{
		return it->second;
	}
	throw LookUp_NotFound_Exception("The type not found");
}

void SubRegister::Remove(const string& type, shared_ptr<IEventHandler> control)
{
	map<string, set<shared_ptr<IEventHandler> > >::iterator it = m_map.find(type);
	if (it != m_map.end())
	{
		it->second.erase(control);
	}
}

}
