#makefile

CPPFLAGS = -g -pedantic -lpthread -std=c++03 -Wall -Werror -Wconversion -I$(INCLUDE_PATH)

TARGET := test
CC=g++ 
OBJS= test.o Thread.o Mutex.o ConditionVariable.o
INCLUDE_PATH= ../include/
MUTEX_PATH=../mutex/
THREAD_PATH= ../thread/
COND_PATH= ../conditionVariable/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lpthread
		
Thread.o: 
		$(CC) $(CPPFLAGS) -c $(THREAD_PATH)Thread.cpp $<

Mutex.o: 
		$(CC) $(CPPFLAGS) -c $(MUTEX_PATH)Mutex.cpp $<
		
ConditionVariable.o: 
		$(CC) $(CPPFLAGS) -c $(COND_PATH)ConditionVariable.cpp $<

test.o: 
	$(CC) $(CPPFLAGS) -c test.cpp $(THREAD_PATH)Thread.cpp $(COND_PATH)ConditionVariable.cpp $(MUTEX_PATH)Mutex.cpp $<

include depends
depends: ./test.cpp
	$(CC) -MM $(CPPFLAGS) $^ > depends

.PHONY : clean

clean:
	rm -f $(TARGET) $(OBJS)
	
run:	${TARGET}
	./${TARGET} ${OBJS} 

