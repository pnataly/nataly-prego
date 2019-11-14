#makefile

CPPFLAGS = -g -pedantic -lpthread -std=c++03 -Wall -Werror -Wconversion -I$(PROJECT_INCLUDE_PATH) -I$(INCLUDE_PATH)

TARGET := test
CC=g++ 
OBJS= test.o Floor.o Room.o Location.o Event.o Type.o ID.o Thread.o Mutex.o ConditionVariable.o smokeController.o dispEvent.o SubRegister.o eventPub.o serialPub.o smokeHandler.o fireController.o fireHandler.o eventCriteria.o AllOptions.o smokeSensor.o fireSensor.o
PROJECT_INCLUDE_PATH= ../include/
INCLUDE_PATH= ../../include/
MUTEX_PATH=../../mutex/
THREAD_PATH= ../../thread/
COND_PATH= ../../conditionVariable/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lpthread
		
Type.o: 
		$(CC) $(CPPFLAGS) -c Type.cpp $<		
		
Room.o: 
		$(CC) $(CPPFLAGS) -c Room.cpp $<

Floor.o: 
		$(CC) $(CPPFLAGS) -c Floor.cpp $<
		
Location.o: 
		$(CC) $(CPPFLAGS) -c Location.cpp Room.cpp Floor.cpp $<

ID.o:
		$(CC) $(CPPFLAGS) -c ID.cpp $<
		
Event.o:
		$(CC) $(CPPFLAGS) -c Room.cpp Floor.cpp Location.cpp Type.cpp Event.cpp $<
		
Thread.o: 
		$(CC) $(CPPFLAGS) -c $(THREAD_PATH)Thread.cpp $<

Mutex.o: 
		$(CC) $(CPPFLAGS) -c $(MUTEX_PATH)Mutex.cpp $<
		
ConditionVariable.o: 
		$(CC) $(CPPFLAGS) -c $(COND_PATH)ConditionVariable.cpp $<
	
smokeSensor.o:
		$(CC) $(CPPFLAGS) -c smokeSensor.cpp $<
		
fireSensor.o:
		$(CC) $(CPPFLAGS) -c fireSensor.cpp $<

dispEvent.o:
		$(CC) $(CPPFLAGS) -c dispEvent.cpp $<
		
smokeController.o:
		$(CC) $(CPPFLAGS) -c smokeController.cpp smokeHandler.cpp eventCriteria.cpp $<
		
smokeHandler.o:
		$(CC) $(CPPFLAGS) -c smokeHandler.cpp $<

fireController.o:
		$(CC) $(CPPFLAGS) -c fireController.cpp fireHandler.cpp eventCriteria.cpp $<
		
fireHandler.o:
		$(CC) $(CPPFLAGS) -c fireHandler.cpp $<

SubRegister.o:
		$(CC) $(CPPFLAGS) -c SubRegister.cpp Controller.cpp Event.cpp Type.cpp $<
		
eventPub.o:
		$(CC) $(CPPFLAGS) -c eventPub.cpp $<

serialPub.o:
		$(CC) $(CPPFLAGS) -c serialPub.cpp $<
		
eventCriteria.o:
		$(CC) $(CPPFLAGS) -c eventCriteria.cpp $<
	
AllOptions.o:
		$(CC) $(CPPFLAGS) -c AllOptions.cpp $<

test.o: 
		$(CC) $(CPPFLAGS) -c test.cpp  Location.cpp Room.cpp ID.cpp Floor.cpp Type.cpp Event.cpp $(THREAD_PATH)Thread.cpp $(MUTEX_PATH)Mutex.cpp $(COND_PATH)ConditionVariable.cpp dispEvent.cpp SubRegister.cpp eventPub.cpp serialPub.cpp fireController.cpp fireHandler.cpp smokeController.cpp smokeHandler.cpp smokeSensor.cpp fireSensor.cpp $<

include depends
depends: ./test.cpp
	$(CC) -MM $(CPPFLAGS) $^ > depends

.PHONY: valgrind

valgrind: 
	valgrind -v --track-origins=yes --leak-check=full --show-reachable=yes ./test


.PHONY : clean

clean:
	rm -f $(TARGET) $(OBJS)
	
run:	${TARGET}
	./${TARGET} ${OBJS} 

