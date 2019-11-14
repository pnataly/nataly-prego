#include "mu_test.h"
#include "Thread.h"
#include "commons.h"
#include "IRunnable.h"
#include "Counter.h"
#include <iostream>
#include <unistd.h> //sleep

using namespace advcpp;

UNIT(thread) 	
	Counter *p = new Counter(1000);
	shared_ptr<Counter> c(p);
	Thread t(c);
	t.Join();

	ASSERT_EQUAL_INT(p->GetCount(), 1000);
END_UNIT


UNIT(threads) 	
	shared_ptr<Counter> c1 (new Counter(1000));
	shared_ptr<Counter> c2 (new Counter(5000));
	shared_ptr<Counter> c3 (new Counter(900));
	
	Thread t1(c1);
	Thread t2(c2);
	Thread t3(c3);
	
	t1.Join();
	t2.Join();
	t3.Join();

	ASSERT_EQUAL_INT(c1->GetCount(), 1000);
	ASSERT_EQUAL_INT(c2->GetCount(), 5000);
	ASSERT_EQUAL_INT(c3->GetCount(), 900);
END_UNIT 

TEST_SUITE(C Unit Test Demo for mu_test!) 	
	TEST(thread) 	
	TEST(threads) 	
END_SUITE

