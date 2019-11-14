#ifndef ISENSOR_H
#define ISENSOR_H


#include "IRunnable.h"
#include "commons.h"
#include "ID.h"
#include "Type.h"
#include "Location.h"
#include "Event.h"

namespace smarthome
{
template <typename T> class IEnqueue;


class ISensor: public advcpp::IRunnable 
{
public:		
	
	ISensor(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq);
	
	virtual ~ISensor(){}
	virtual void Run() = 0;

protected:
	virtual void Send() = 0;

protected:
	ID m_id;
	Type m_type;
	Location m_location;
	shared_ptr<IEnqueue<shared_ptr<Event> > > m_enq;
};

inline ISensor::ISensor(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq)
:	m_id(id)	
,	m_type(type)
,	m_location(loc)
,	m_enq(enq)
{} 

typedef ISensor* Create_t(const ID& id, const Type& type, const Location& loc, shared_ptr<IEnqueue<shared_ptr<Event> > >enq);
typedef void Destroy_t(ISensor*);

}

#endif /*ISENSOR_H*/

