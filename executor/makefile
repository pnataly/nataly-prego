# makefile for executor

TARGET= executor.out
CC=gcc
CFLAGS= -ansi -g -pedantic -Wall
OBJS= executor.o Task.o Time.o executorTest.o genericHeap.o genericVector.o 


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

executorTest.o: executorTest.c executorTest.h executor.h
	$(CC) $(CFLAGS) -c executorTest.c

executor.o: executor.c executor.h Task.h Time.h genericHeap.h genericVector.h
	$(CC) $(CFLAGS) -c executor.c

Time.o: Time.c Time.h 
	$(CC) $(CFLAGS) -c Time.c

Task.o: Task.c Task.h 
	$(CC) $(CFLAGS) -c Task.c

genericVector.o: genericVector.c genericVector.h
		$(CC) $(CFLAGS) -c genericVector.c

genericHeapNew.o: genericHeap.c genericHeap.h genericVector.c genericVector.h
		$(CC) $(CFLAGS) -c genericHeap.c

clean: 
	rm -f $(TARGET) $(OBJS)
