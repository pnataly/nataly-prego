#makefile for Smart Building project

CPPFLAGS = -g -export-dynamic -pedantic -lpthread -std=c++03 -Wall -Werror -Wconversion -I$(PROJECT_INCLUDE_PATH) -I$(INCLUDE_PATH)

TARGET := test
CC=g++ 
OBJS= test.o Floor.o Room.o Location.o Event.o Type.o ID.o Thread.o Mutex.o ConditionVariable.o dispEvent.o SubRegister.o eventPub.o serialPub.o eventCriteria.o AgentFactory.o Server.o Reader.o
LIB= -lpthread -ldl -export-dynamic -lconfig++
LIB_PATH= ../lib
PROJECT_INCLUDE_PATH= ../include/
INCLUDE_PATH= ../../include/
MUTEX_PATH=../../mutex/
THREAD_PATH= ../../thread/
COND_PATH= ../../conditionVariable/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -L$(LIB_PATH)libSC.so -L$(LIB_PATH)libFS.so -L$(LIB_PATH)libSS.so -L$(LIB_PATH)libFC.so $(LIB)
		
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
	
libSS.so: smokeSensor.cpp Event.h
	$(CC) $(CPPFLAGS) -shared -o libSS.so smokeSensor.cpp Event.cpp	
		
libFS.so: fireSensor.cpp Event.h
		$(CC) $(CPPFLAGS) -shared -o libFS.so fireSensor.cpp Event.cpp	

libSC.so: smokeController.cpp smokeHandler.h eventCriteria.h
	$(CC) $(CPPFLAGS) -shared -o libSC.so smokeController.cpp smokeHandler.cpp eventCriteria.cpp
		
libFC.so: fireController.cpp fireHandler.h eventCriteria.h
		$(CC) $(CPPFLAGS) -shared -o libFC.so fireController.cpp fireHandler.cpp eventCriteria.cpp

dispEvent.o:
		$(CC) $(CPPFLAGS) -c dispEvent.cpp $<

SubRegister.o:
		$(CC) $(CPPFLAGS) -c SubRegister.cpp Controller.cpp Event.cpp Type.cpp $<
		
eventPub.o:
		$(CC) $(CPPFLAGS) -c eventPub.cpp $<

serialPub.o:
		$(CC) $(CPPFLAGS) -c serialPub.cpp $<
		
eventCriteria.o:
		$(CC) $(CPPFLAGS) -c eventCriteria.cpp $<

AgentFactory.o:
		$(CC) $(CPPFLAGS) -c AgentFactory.cpp $<
		
Reader.o:
		$(CC) $(CPPFLAGS) -c Reader.cpp $<
				
Server.o:
		$(CC) $(CPPFLAGS) -c Server.cpp $<
		
test.o: 
		$(CC) $(CPPFLAGS) -c test.cpp  Location.cpp Room.cpp ID.cpp Floor.cpp Type.cpp Event.cpp $(THREAD_PATH)Thread.cpp $(MUTEX_PATH)Mutex.cpp $(COND_PATH)ConditionVariable.cpp dispEvent.cpp SubRegister.cpp eventPub.cpp serialPub.cpp AgentFactory.cpp Server.cpp Reader.cpp -l$(LIB_PATH) $<

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

