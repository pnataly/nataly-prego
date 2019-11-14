#makefile for locker

LIB = libLocker.so
CC = gcc
CFLAGS = -pedantic -Wall -pthread -g -c -I../include
LIB_FLAGS = -fPIC
OBJS = locker.o 
INC_PATH = ../include/
SRC_PATH = ./


$(LIB): $(OBJS)
	$(CC) -o $(LIB) -shared $(OBJS)

locker.o: $(SRC_PATH)locker.c $(INC_PATH)locker.h 
	$(CC) $(CFLAGS) $(LIB_FLAGS) $(SRC_PATH)locker.c

clean:
	rm -f $(OBJS) 
