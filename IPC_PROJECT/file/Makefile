#Makefile for fileHandler

CFLAGS =-g -pthread -pedantic -Wall -I$(INCLUDE_PATH)

TARGET := file
CC=gcc
OBJS= CDR.o MSQ.o fileMonitor.o main.o #fileHandler.o
INCLUDE_PATH= ../include/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

CDR.o: $(INCLUDE_PATH)CDR.h
	$(CC) $(CFLAGS) -c ../CDR.c

MSQ.o: $(INCLUDE_PATH)MSQ.h $(INCLUDE_PATH)CDR.h
	$(CC) $(CFLAGS) -c ../MSQ.c 

#fileHandler.o: $(INCLUDE_PATH)fileHandler.h $(INCLUDE_PATH)CDR.h $(INCLUDE_PATH)MSQ.h
#	$(CC) $(CFLAGS) -c fileHandler.c ../CDR.c ../MSQ.c

fileMonitor.o: $(INCLUDE_PATH)fileMonitor.h 
	$(CC) $(CFLAGS) -c fileMonitor.c 

main.o: $(INCLUDE_PATH)fileMonitor.h $(INCLUDE_PATH)CDR.h $(INCLUDE_PATH)MSQ.h
	$(CC) $(CFLAGS) -c fileMonitor.c ../MSQ.c ../CDR.c main.c

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY : clan

