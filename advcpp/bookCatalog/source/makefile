#makefile for books catalog

CPPFLAGS = -g -pedantic -std=c++03 -Wall -Werror -Wconversion -I$(INCLUDE_PATH)

TARGET := test
CC=g++ 
OBJS= test.o Book.o Author.o Publisher.o isbn.o Year.o indexBy.o Aggregator.o
INCLUDE_PATH= ../include/


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

Book.o: $(INCLUDE_PATH)Book.h $(INCLUDE_PATH)isbn.h $(INCLUDE_PATH)Year.h $(INCLUDE_PATH)Author.h $(INCLUDE_PATH)Publisher.h
		$(CC) $(CPPFLAGS) -c Book.cpp
		
Author.o: $(INCLUDE_PATH)Book.h $(INCLUDE_PATH)Author.h
	$(CC) $(CPPFLAGS) -c Author.cpp
	
Publisher: $(INCLUDE_PATH)Book.h $(INCLUDE_PATH)Publisher.h
	$(CC) $(CPPFLAGS) -c Publisher.cpp
	
isbn.o: $(INCLUDE_PATH)isbn.h
	$(CC) $(CPPFLAGS) -c isbn.cpp
	
Year.o: $(INCLUDE_PATH)Year.h
	$(CC) $(CPPFLAGS) -c Year.cpp
	
indexBy.o: $(INCLUDE_PATH)Book.h $(INCLUDE_PATH)indexBy.h
	$(CC) $(CPPFLAGS) -c indexBy.cpp
	
Aggregator.o: $(INCLUDE_PATH)Book.h $(INCLUDE_PATH)IUpdate.h $(INCLUDE_PATH)IQuery.h $(INCLUDE_PATH)Author.h $(INCLUDE_PATH)Publisher.h $(INCLUDE_PATH)Aggregator.h $(INCLUDE_PATH)indexBy.h $(INCLUDE_PATH)catalog.h
	$(CC) $(CPPFLAGS) -c indexBy.cpp Book.cpp Author.cpp Publisher.cpp Aggregator.cpp

test.o: $(INCLUDE_PATH)Book.h $(INCLUDE_PATH)isbn.h $(INCLUDE_PATH)Year.h $(INCLUDE_PATH)Author.h $(INCLUDE_PATH)Publisher.h $(INCLUDE_PATH)catalog.h $(INCLUDE_PATH)indexBy.h $(INCLUDE_PATH)IUpdate.h $(INCLUDE_PATH)IQuery.h $(INCLUDE_PATH)Aggregator.h
	$(CC) $(CPPFLAGS) -c test.cpp Book.cpp Author.cpp isbn.cpp Year.cpp Publisher.cpp indexBy.cpp Aggregator.cpp

clean:
	rm -f $(OBJS) 
