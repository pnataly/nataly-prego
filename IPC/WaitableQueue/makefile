
TARGET=wq
CC=gcc
CFLAGS = -pthread -pedantic -Wall -Werror 
OBJS= WQueue.o producer.o consumer.o main.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

producer.o: producer.h WQueue.h
	$(CC) $(CFLAGS) -c producer.c 

consumer.o: consumer.h WQueue.h
	$(CC) $(CFLAGS) -c consumer.c

WQueue.o: WQueue.h
	$(CC) $(CFLAGS) -c WQueue.c

main.o: WQueue.h producer.h consumer.h
	$(CC) $(CFLAGS) -c main.c

clean:
	@rm -f ./$(TARGET) $(OBJS)


.PHONY : clan



