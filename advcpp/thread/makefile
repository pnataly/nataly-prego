#makefile

CPPFLAGS = -g -pedantic -lpthread -std=c++03 -Wall -Werror -Wconversion -I$(INCLUDE_PATH)

TARGET := test
CC=g++ 
OBJS= test.o Thread.o Counter.o
INCLUDE_PATH= ../include/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lpthread

Counter.o: $(INCLUDE_PATH)Counter.h $(INCLUDE_PATH)IRunnable.h
		$(CC) $(CPPFLAGS) -c Counter.cpp
		
Thread.o: $(INCLUDE_PATH)Thread.h $(INCLUDE_PATH)IRunnable.h $(INCLUDE_PATH)Exception.h
		$(CC) $(CPPFLAGS) -c Thread.cpp

test.o: $(INCLUDE_PATH)IRunnable.h  $(INCLUDE_PATH)Thread.h  $(INCLUDE_PATH)mu_test.h $(INCLUDE_PATH)Counter.h
	$(CC) $(CPPFLAGS) -c test.cpp Thread.cpp Counter.cpp 

clean:
	rm -f $(TARGET) $(OBJS)
