#include "eventPub.h"
#include "ISubLookUp.h"
#include "IPubMech.h"
#include "Event.h"
#include "eventCriteria.h"

#include <iostream>

namespace smarthome{

EventPub::EventPub(shared_ptr<ISubLookUp> look, shared_ptr<IPubMech> pub)
:	m_look(look)
,	m_pub(pub)
{}

void EventPub::Publish(shared_ptr<Event> event) 
{
	set<shared_ptr<IEventHandler> > mset;
	vector<string> ::iterator Iter;				
	try{
		shared_ptr<EventC> evc(new EventC(event->GetType(), event->GetLocation()));
		mset = m_look->LookUp(evc->GetEventC());
		
	}catch(std::exception)
	{
		std::cout<< "the type not found in the map" << '\n';
	}
	m_pub->Pub(mset, event);
}

}
