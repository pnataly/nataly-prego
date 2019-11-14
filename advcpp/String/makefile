#makefile

CPPFLAGS = -g -pedantic -std=c++03 -Wall -Werror -Wconversion -I$(INCLUDE_PATH)

TARGET := test
CC=g++ 
OBJS= test.o
INCLUDE_PATH= ../include/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

test.o: $(INCLUDE_PATH)String.h  $(INCLUDE_PATH)mu_test.h $(INCLUDE_PATH)Buffer.h $(INCLUDE_PATH)Flag.h $(INCLUDE_PATH)Util.h
	$(CC) $(CPPFLAGS) -c test.cpp

clean:
	rm -f $(TARGET) $(OBJS)
