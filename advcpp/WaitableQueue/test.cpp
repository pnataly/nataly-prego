#include "mu_test.h"
#include "Mutex.h"
#include "ConditionVariable.h"
#include "WaitableQueue.h"
#include "Thread.h"
#include "Producer.h"
#include "Consumer.h"
#include "commons.h"

using namespace advcpp;


const static int SIZE = 10;
UNIT(fifo_test)

	WaitableQueue<shared_ptr<Cat> > wq;
	ASSERT_THAT(wq.IsEmpty());
	
	for(int i= 1; i<=SIZE; ++i)
	{
		shared_ptr<Cat> cat(new Cat(i));
		wq.Enqueue(cat);
	}

	ASSERT_EQUAL_INT(wq.Size(), SIZE);
	
	for(int i =1; i <= SIZE; ++i)
	{
		shared_ptr<Cat> cat = wq.Dequeue();
		ASSERT_EQUAL_INT(cat->m_id, i);
	}
	ASSERT_THAT(wq.IsEmpty());
	
END_UNIT


UNIT(prod_test)

	WaitableQueue<shared_ptr<Cat> > *q = new WaitableQueue<shared_ptr<Cat> >;
	shared_ptr<WaitableQueue<shared_ptr<Cat> > > wq(q);
	
	Producer<shared_ptr<Cat> > *p = new Producer<shared_ptr<Cat> >(wq ,SIZE);
	shared_ptr<Producer<shared_ptr<Cat> > > producer(p);
	Thread prod(producer);
	
	prod.Join();
	
	ASSERT_EQUAL_INT(wq->Size(), SIZE);
	
	for(int i =1; i <= SIZE; ++i)
	{
		shared_ptr<Cat> cat = wq->Dequeue();
		ASSERT_EQUAL_INT(cat->m_id, i);
	}
	
	ASSERT_THAT(wq->IsEmpty());
	ASSERT_EQUAL_INT(wq->Size(), 0);
	
END_UNIT 

UNIT(cons_test)

	WaitableQueue<shared_ptr<Cat> > *q = new WaitableQueue<shared_ptr<Cat> >();
	shared_ptr<WaitableQueue<shared_ptr<Cat> > > wq(q);

	for(int i= 1 ; i<=SIZE; ++i)
	{
		shared_ptr<Cat> cat(new Cat(i));
		wq->Enqueue(cat);
	}
	
	ASSERT_EQUAL_INT(wq->Size(), SIZE);
	
	Consumer<shared_ptr<Cat> > *p = new Consumer<shared_ptr<Cat> >(wq, SIZE);
	shared_ptr<Consumer<shared_ptr<Cat> > > consumer(p);
	Thread con(consumer);
	
	con.Join();
	
	ASSERT_THAT(wq->IsEmpty());
	
END_UNIT 


UNIT(cons1_prod1)
	WaitableQueue<shared_ptr<Cat> > *q = new WaitableQueue<shared_ptr<Cat> >();
	shared_ptr<WaitableQueue<shared_ptr<Cat> > > wq(q);
	
	ASSERT_THAT(wq->IsEmpty());
	
	Consumer<shared_ptr<Cat> > *c = new Consumer<shared_ptr<Cat> >(wq, SIZE);
	shared_ptr<Consumer<shared_ptr<Cat> > > consumer(c);
	
	Producer<shared_ptr<Cat> > *p = new Producer<shared_ptr<Cat> >(wq ,SIZE);
	shared_ptr<Producer<shared_ptr<Cat> > > producer(p);
	
	Thread prod1(producer);
	Thread cons(consumer);

	prod1.Join();
	cons.Join();
	
	ASSERT_THAT(wq->IsEmpty());
END_UNIT 

UNIT(prod2_cons1_test)

	WaitableQueue<shared_ptr<Cat> > *q = new WaitableQueue<shared_ptr<Cat> >();
	shared_ptr<WaitableQueue<shared_ptr<Cat> > > wq(q);

	Producer<shared_ptr<Cat> > *p = new Producer<shared_ptr<Cat> >(wq ,SIZE);
	shared_ptr<Producer<shared_ptr<Cat> > > producer(p);
	
	Thread prod1(producer);
	Thread prod2(producer);
	
	prod1.Join();
	prod2.Join();
	
	ASSERT_EQUAL_INT(wq->Size(), SIZE*2);
	
	Consumer<shared_ptr<Cat> > *c = new Consumer<shared_ptr<Cat> >(wq, SIZE);
	shared_ptr<Consumer<shared_ptr<Cat> > > consumer(c);
	Thread cons(consumer);
	
	cons.Join();
	
	ASSERT_EQUAL_INT(wq->Size(), SIZE);
	
END_UNIT	

UNIT(prod1_cons2_test)
	WaitableQueue<shared_ptr<Cat> > *q = new WaitableQueue<shared_ptr<Cat> >();
	shared_ptr<WaitableQueue<shared_ptr<Cat> > > wq(q);

	Producer<shared_ptr<Cat> > *p = new Producer<shared_ptr<Cat> >(wq ,SIZE*2);
	shared_ptr<Producer<shared_ptr<Cat> > > producer(p);
	
	Thread prod1(producer);
	prod1.Join();

	ASSERT_EQUAL_INT(wq->Size(), SIZE*2);
	
	Consumer<shared_ptr<Cat> > *c = new Consumer<shared_ptr<Cat> >(wq, SIZE);
	shared_ptr<Consumer<shared_ptr<Cat> > > consumer(c);
	Thread cons1(consumer);
	Thread cons2(consumer);
	
	cons1.Join();
	cons2.Join();
	
	ASSERT_THAT(wq->IsEmpty());
END_UNIT 

const static int PRODUCER = 20;
const static int CONSUMER = 10;
UNIT(consN_prodM)
	WaitableQueue<shared_ptr<Cat> > *q = new WaitableQueue<shared_ptr<Cat> >();
	shared_ptr<WaitableQueue<shared_ptr<Cat> > > wq(q);
	
	ASSERT_THAT(wq->IsEmpty());
	
	for(int i = 1; i <=PRODUCER; ++i)
	{
		Producer<shared_ptr<Cat> > *p = new Producer<shared_ptr<Cat> >(wq ,SIZE/2);
		shared_ptr<Producer<shared_ptr<Cat> > > producer(p);
		Thread prod(producer);
		prod.Join();
	}
	ASSERT_EQUAL_INT(wq->Size(), SIZE*SIZE);
	
	for(int i = 1; i <=CONSUMER; ++i)
	{
		Consumer<shared_ptr<Cat> > *c = new Consumer<shared_ptr<Cat> >(wq, SIZE);
		shared_ptr<Consumer<shared_ptr<Cat> > > consumer(c);
		Thread cons(consumer);
		cons.Join();
	}
	ASSERT_THAT(wq->IsEmpty());
END_UNIT 


TEST_SUITE(C Unit Test Demo for mu_test!) 	
	TEST(fifo_test)
	TEST(prod_test)
	TEST(cons_test)
	TEST(cons1_prod1)
	TEST(prod2_cons1_test)
	TEST(prod1_cons2_test)
	TEST(consN_prodM)
END_SUITE


