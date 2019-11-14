# makefile for game hearts

TARGET= hearts.out
CC=gcc
CFLAGS= -ansi -g -pedantic -Wall
OBJS= game.o round.o player.o deck.o main.o vector.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c game.h ADTErr.h
	$(CC) $(CFLAGS) -c main.c

deck.o: deck.c deck.h ADTErr.h
	$(CC) $(CFLAGS) -c deck.c

player.o: player.c player.h deck.h vector.h ADTErr.h
	$(CC) $(CFLAGS) -c player.c

round.o: round.c round.h deck.h player.h ADTErr.h
	$(CC) $(CFLAGS) -c round.c

game.o: game.c game.h deck.h player.h round.h ADTErr.h
	$(CC) $(CFLAGS) -c game.c

clean: 
	rm -f $(TARGET) $(OBJS)
