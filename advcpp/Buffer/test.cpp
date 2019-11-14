#include <iostream>
#include "Buffer.h"
#include "mu_test.h"

using namespace advcpp;

class Cat{
public:
	Cat() { ++n;}
	Cat(Cat const&) {++n; ++c;}
	Cat& operator=(Cat const&) {++n; return *this;}
	~Cat() {--n;}

	static size_t n;
	static size_t c;
};

size_t Cat::n = 0;
size_t Cat::c = 0;


template <class T>
void fillBuffer(size_t num, Buffer<T>& obj)
{
	while(num--)
	{
		obj.Put(num, T());
	}
}


UNIT(test)
	ASSERT_EQUAL_INT(Cat::n , 0);
	Cat Kat;
	Cat cat;
	Buffer<Cat> buf(10);
	buf.Put(0, Kat);
	buf.Put(1, cat);
	Buffer<Cat> buffer(buf);
	ASSERT_EQUAL_INT(Cat::n , 6);
END_UNIT


UNIT(test2)
	Cat::c=0;
	ASSERT_EQUAL_INT(Cat::n , 0);
	{
		Buffer<Cat> buf(10);
		Cat Kat;
		ASSERT_EQUAL_INT(Cat::n , 1);
		ASSERT_EQUAL_INT(Cat::c , 0);
		buf.Put(0, Kat);
		ASSERT_EQUAL_INT(Cat::n , 2);
		ASSERT_EQUAL_INT(Cat::c , 1);
	}
	ASSERT_EQUAL_INT(Cat::n , 0);
	Cat::c = 0;
END_UNIT


UNIT(put_test)
	ASSERT_THAT(Cat::n == 0);
	
	Cat kat;
	Buffer<Cat> buf(50);

	ASSERT_EQUAL_INT(Cat::n , 1);
	ASSERT_EQUAL_INT(Cat::c , 0);
	buf.Put(0, kat);

	ASSERT_EQUAL_INT(Cat::c , 1);
	ASSERT_EQUAL_INT(Cat::n , 2);

	Cat cat;
	ASSERT_EQUAL_INT(Cat::n , 3);
	buf.Put(0,cat);

	ASSERT_EQUAL_INT(Cat::n , 4);
	ASSERT_EQUAL_INT(Cat::c , 1);

	buf.Put(1, kat);
	ASSERT_EQUAL_INT(Cat::c , 2);
	ASSERT_EQUAL_INT(Cat::n ,5);
	Cat::c = 0;
END_UNIT


UNIT(grow_test)
	Cat::c = 0;
	Buffer<Cat> b(50);
	ASSERT_EQUAL_INT(Cat::c , 0);
	ASSERT_EQUAL_INT(Cat::n , 1); 
	
	fillBuffer<Cat>(50, b);
	ASSERT_EQUAL_INT(b.Capacity() , 50);
	ASSERT_EQUAL_INT(Cat::n , 51); 
	ASSERT_EQUAL_INT(Cat::c , 50);

	b.Grow(10);
	ASSERT_EQUAL_INT(Cat::n , 51); 
	ASSERT_EQUAL_INT(Cat::c , 50);
	ASSERT_EQUAL_INT(b.Capacity() , 50);

	b.Grow(100);
	ASSERT_EQUAL_INT(b.Capacity() , 100);
	ASSERT_EQUAL_INT(Cat::n , 51); 
	ASSERT_EQUAL_INT(Cat::c , 150); 
END_UNIT


UNIT(shrink_test)
	Cat::c = 0;
	Buffer<Cat> buf(50);
	ASSERT_EQUAL_INT(Cat::c , 0);
	ASSERT_EQUAL_INT(Cat::n , 1); 
	
	fillBuffer<Cat>(50, buf);
	ASSERT_EQUAL_INT(Cat::n , 51); 
	ASSERT_EQUAL_INT(Cat::c , 50);

	buf.Shrink(10);
	ASSERT_EQUAL_INT(buf.Capacity() , 10);

	ASSERT_EQUAL_INT(Cat::n , 10); 
	ASSERT_EQUAL_INT(Cat::c , 110); 

END_UNIT


UNIT(test3)
	Cat::c = 0;
	Buffer<Cat> buf(10);
	ASSERT_EQUAL_INT(Cat::c , 0);
	ASSERT_EQUAL_INT(Cat::n , 2); 
	
	fillBuffer<Cat>(10, buf);
	ASSERT_EQUAL_INT(Cat::n , 12); 
	ASSERT_EQUAL_INT(Cat::c , 10);
	ASSERT_EQUAL_INT(buf.Capacity() , 10);

	fillBuffer<Cat>(10, buf);

	ASSERT_EQUAL_INT(Cat::n , 22); 
	ASSERT_EQUAL_INT(Cat::c , 10); 
END_UNIT




TEST_SUITE(C Unit Test Demo for mu_test!)
	TEST(test)
	TEST(test2)
	TEST(put_test)
	TEST(grow_test)
	TEST(shrink_test)
	TEST(test3)
END_SUITE

