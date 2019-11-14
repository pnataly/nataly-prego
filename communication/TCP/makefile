CFLAGS = -ansi -g -pedantic -Wall -I$(INCLUDE_PATH)

TARGET := server
CC=gcc
OBJS= nonBlockServer.o genericVector.o 
INCLUDE_PATH= ../../advanceC/include/
VECTOR_PATH=../../advanceC/genericVector/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

genericVector.o: $(INCLUDE_PATH)genericVector.h
	$(CC) $(CFLAGS) -c $(VECTOR_PATH)genericVector.c


nonBlockServer.o: client_server.h $(INCLUDE_PATH)genericVector.h
	$(CC) $(CFLAGS) -c $(VECTOR_PATH)genericVector.c nonBlockServer.c
	
clean:
	@rm -f ./$(TARGET) $(OBJS)


.PHONY : clan

