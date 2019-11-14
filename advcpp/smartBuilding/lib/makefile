#makefile for .so libraries

TARGET1= libSS.so
TARGET2= libFS.so
TARGET3= libFC.so
TARGET4= libSC.so

CC= g++ 
CPPFLAGS= -fPIC -ansi -g -pedantic -std=c++03 -Wall -Werror -Wconversion -I$(PRJ_INC_PATH) -I$(OTHER_INC_PATH) 
LFLAGS= -shared

PRJ_INC_PATH=../include/
OTHER_INC_PATH=../../include/
SRC_PATH=../sources/

OBJS1=smokeSensor.o
OBJS2=fireSensor.o
OBJS3=fireController.o
OBJS4=smokeController.o
OBJS5=fireHandler.o
OBJS6=smokeHandler.o
OBJS7=Task.o

all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

$(TARGET1) : $(OBJS1)
	$(CC) $(CPPFLAGS) $(OBJS1) $(OBJS7) -o $@ $(LFLAGS)

$(TARGET2) : $(OBJS2)
	$(CC) $(CPPFLAGS) $(OBJS2) $(OBJS7) -o $@ $(LFLAGS)

$(TARGET3) : $(OBJS3)
	$(CC) $(CPPFLAGS) $(OBJS3) $(OBJS5) -o $@ $(LFLAGS)

$(TARGET4) : $(OBJS4)
	$(CC) $(CPPFLAGS) $(OBJS4) $(OBJS6) -o $@ $(LFLAGS)
	
smokeSensor.o: smokeSensor.cpp smokeSensor.h $(PRJ_INC_PATH)IAgent.h $(OTHER_INC_PATH)Thread.h Task.h
	$(CC) $(CPPFLAGS) -c smokeSensor.cpp Task.cpp

fireSensor.o: fireSensor.cpp fireSensor.h $(PRJ_INC_PATH)IAgent.h $(OTHER_INC_PATH)Thread.h Task.h
	$(CC) $(CPPFLAGS) -c fireSensor.cpp Task.cpp
	
fireController.o: fireController.cpp fireController.h fireHandler.h $(PRJ_INC_PATH)ISubsribe.h $(PRJ_INC_PATH)eventCriteria.h 
	$(CC) $(CPPFLAGS) -c fireController.cpp $(SRC_PATH)eventCriteria.cpp fireHandler.cpp 

fireHandler.o: fireHandler.cpp fireHandler.h $(PRJ_INC_PATH)Type.h $(PRJ_INC_PATH)Event.h $(PRJ_INC_PATH)Type.h $(PRJ_INC_PATH)Location.h
	$(CC) $(CPPFLAGS) -c fireHandler.cpp $(SRC_PATH)Event.cpp $(SRC_PATH)ID.cpp $(SRC_PATH)Type.cpp $(SRC_PATH)Location.cpp

smokeController.o: smokeController.cpp smokeController.h smokeHandler.h $(PRJ_INC_PATH)ISubsribe.h $(PRJ_INC_PATH)eventCriteria.h
	$(CC) $(CPPFLAGS) -c smokeController.cpp $(SRC_PATH)eventCriteria.cpp smokeHandler.cpp 

smokeHandler.o: smokeHandler.cpp smokeHandler.h $(PRJ_INC_PATH)Type.h $(PRJ_INC_PATH)Event.h $(PRJ_INC_PATH)Type.h $(PRJ_INC_PATH)Location.h
	$(CC) $(CPPFLAGS) -c smokeHandler.cpp $(SRC_PATH)Event.cpp $(SRC_PATH)ID.cpp $(SRC_PATH)Type.cpp $(SRC_PATH)Location.cpp
	
Task.o: Task.cpp Task.h $(PRJ_INC_PATH)Event.h
	$(CC) $(CPPFLAGS) -c Task.cpp $(SRC_PATH)Event.cpp
	
clean:
	rm -f *.o $(OBJS) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)


