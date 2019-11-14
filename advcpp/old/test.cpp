#include "mu_test.h"
#include "Floor.h"
#include "Room.h"
#include "ID.h"
#include "Location.h"
#include "Type.h"
#include "Event.h"
#include "EventQueue.h"
#include "dispEvent.h"
#include "SubRegister.h"
#include "Thread.h"
#include "Mutex.h"
#include "ConditionVariable.h"
#include "WaitableQueue.h"
#include "serialPub.h"
//#include "AgentManager.h"
#include "AgentFactory.h"
#include "IAgent.h"

using namespace smarthome;
using namespace advcpp;

UNIT(eventQueue_test)
	Room room("1_a");
	Floor floor("2.5");
	Type type("fire");
	Location loc(room, floor);
	shared_ptr<Event> event(new Event(type, loc));
	
	ASSERT_THAT(event->GetType().GetType() == "fire");
	ASSERT_THAT((event->GetLocation().GetRoom()) == "1_a");
	ASSERT_THAT((event->GetLocation().GetFloor()) == "2.5");
	
	EventQueue<shared_ptr<Event> > eq;

	eq.Enqueue(event);
	ASSERT_EQUAL_INT(eq.Size() , 1);
	shared_ptr<Event> newevent = eq.Dequeue();
	ASSERT_THAT((newevent->GetLocation().GetFloor()) == "2.5");
	ASSERT_EQUAL_INT(eq.Size() , 0);
END_UNIT
/*
UNIT(sensor_test)
	Room room("1_a");
	Floor floor("2.5");
	Type ftype("fire");
	Type stype("smoke");
	Location loc(room, floor);
	ID id("1");
	EventQueue<shared_ptr<Event> > *q = new EventQueue<shared_ptr<Event> >;
	shared_ptr<EventQueue<shared_ptr<Event> > >evq(q);
	
	shared_ptr<SmokeSensor> ssensor(new SmokeSensor(id, stype, loc, evq));
	shared_ptr<FireSensor> fsensor(new FireSensor(id, ftype, loc, evq));
	Thread ssens(ssensor);
	Thread fsens(fsensor);
	ssens.Join();
	fsens.Join();
	
	ASSERT_EQUAL_INT(evq->Size() , 2);
	shared_ptr<Event> newevent1 = evq->Dequeue();
	shared_ptr<Event> newevent2 = evq->Dequeue();
	ASSERT_THAT((newevent1->GetLocation().GetFloor()) == "2.5");
	ASSERT_THAT((newevent1->GetType().GetType()) == "smoke");
	ASSERT_THAT((newevent2->GetType().GetType()) == "fire");
	ASSERT_EQUAL_INT(evq->Size() , 0);
END_UNIT	


UNIT(event_publish_test)
	Room room("1_a");	
	Floor floor("2.5");
	Type type("fire");
	Type type2("smoke");
	Location loc(room, floor);
	ID id("1");
	ID id2("2");
	ID id3("3");
		
	EventQueue<shared_ptr<Event> > *q = new EventQueue<shared_ptr<Event> >;
	shared_ptr<EventQueue<shared_ptr<Event> > >evq(q);
	
	shared_ptr<SmokeSensor> ssensor(new SmokeSensor(id, type2, loc, evq));
	shared_ptr<FireSensor> fsensor(new FireSensor(id, type, loc, evq));
	Thread ssens(ssensor);
	Thread fsens(fsensor);
	ssens.Join();
	fsens.Join();
	
	ASSERT_EQUAL_INT(evq->Size() , 2);
	
	shared_ptr<SubRegister> reg(new SubRegister);
	shared_ptr<SerialPub> ser(new SerialPub);
		
	shared_ptr<SmokeController> scontrol(new SmokeController(id2, type2, loc, reg));
	shared_ptr<SmokeController> scontrol2(new SmokeController(id, type2, loc, reg));
	shared_ptr<FireController> fcontrol(new FireController(id3, type, loc, reg)); 
		
	shared_ptr<DispEvent> dis(new DispEvent(evq, reg, ser));
	Thread dispatcher(dis);
	dispatcher.Join();
	
	ASSERT_EQUAL_INT(evq->Size() , 0); 
END_UNIT 	*/


UNIT(agentManager)
	EventQueue<shared_ptr<Event> > *q = new EventQueue<shared_ptr<Event> >;
	shared_ptr<EventQueue<shared_ptr<Event> > >evq(q);
	shared_ptr<SubRegister> reg(new SubRegister);
	
/*	Room room("2");
	Floor floor("1_b");
	Type ftype("fire");
	Type stype("smoke");
	Location loc(room, floor);
	ID id("1"); */
	
//	shared_ptr<SmokeSensor> ssensor(new SmokeSensor(id, stype, loc, evq));
//	shared_ptr<FireSensor> fsensor(new FireSensor(id, ftype, loc, evq));
//	Thread ssens(ssensor);
//	Thread fsens(fsensor);
//	ssens.Join();
//	fsens.Join();
//	ASSERT_EQUAL_INT(evq->Size(), 1);
	
	AgentManager agentm(reg, evq);
	agentm.Start();

/*	shared_ptr<SerialPub> ser(new SerialPub);
	shared_ptr<DispEvent> dis(new DispEvent(evq, reg, ser));
	Thread dispatcher(dis);
	dispatcher.Join();
	
	ASSERT_EQUAL_INT(evq->Size() , 0); */
END_UNIT 


TEST_SUITE(C Unit Test Demo for mu_test!) 	
	TEST(eventQueue_test)
//	TEST(sensor_test)
//	TEST(event_publish_test)
//	TEST(agentManager)
END_SUITE

#include "mu_test.h"
#include "Floor.h"
#include "Room.h"
#include "ID.h"
#include "Location.h"
#include "Type.h"
#include "Event.h"
#include "Thread.h"
#include "Mutex.h"
#include "ConditionVariable.h"
#include "WaitableQueue.h"
#include "Server.h"

using namespace smarthome;
using namespace advcpp;

/*
UNIT(agentFactory)
	EventQueue<shared_ptr<Event> > *q = new EventQueue<shared_ptr<Event> >;
	shared_ptr<EventQueue<shared_ptr<Event> > >evq(q);
	shared_ptr<SubRegister> reg(new SubRegister);
	
	AgentFactory agentfactory;
	AgentFactory agentfactory1("../lib/libSS.so", "1", "smoke", "1_a", "2.5");
	AgentFactory agentfactory2("../lib/libFS.so", "2", "fire", "2_a", "3");

	AgentFactory agentfactory3("../lib/libSC.so", "3", "smoke", "1_a", "2.5");
	AgentFactory agentfactory4("../lib/libFC.so", "4", "fire", "2_a", "3");	

	shared_ptr<IAgent> ssensor = agentfactory.AgentCreate("../lib/libSS.so", "1", "smoke", "1_a", "2.5");
	shared_ptr<IAgent> fsensor = agentfactory.AgentCreate("../lib/libFS.so", "2", "fire", "2_a", "3");
	shared_ptr<IAgent> scon = agentfactory.AgentCreate("../lib/libSC.so", "3", "smoke", "1_a", "2.5");
	shared_ptr<IAgent> fcon = agentfactory.AgentCreate("../lib/libFC.so", "4", "fire", "2_a", "3");

	ssensor->Init(reg ,evq);
	fsensor->Init(reg ,evq);

	scon->Init(reg ,evq);
	fcon->Init(reg, evq);
	ASSERT_EQUAL_INT(evq->Size(), 2);

	shared_ptr<SerialPub> ser(new SerialPub);
	shared_ptr<DispEvent> dis(new DispEvent(evq, reg, ser));
	Thread dispatcher(dis);
	dispatcher.Join();
	
	ASSERT_EQUAL_INT(evq->Size(), 0);
END_UNIT */

UNIT(agentFactory)
	Server server;
	server.Start();
	
END_UNIT 

TEST_SUITE(C Unit Test Demo for mu_test!) 
	TEST(agentFactory)
END_SUITE

