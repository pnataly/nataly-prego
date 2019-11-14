#makefile for looger

LIB = libLooger.so
CC = gcc
CFLAGS = -pedantic -Wall -pthread -g -c -I../include
LIB_FLAGS = -fPIC
OBJS = zlogc.o 
INC_PATH = ../include/
SRC_PATH = ./


$(LIB): $(OBJS)
	$(CC) -o $(LIB) -shared $(OBJS)

zlogc.o: $(SRC_PATH)zlogc.o $(INC_PATH)zlogc.h 
	$(CC) $(CFLAGS) $(LIB_FLAGS) $(SRC_PATH)zlogc.c

clean:
	rm -f $(OBJS) 
