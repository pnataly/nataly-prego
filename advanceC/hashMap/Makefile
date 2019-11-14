CFLAGS = -ansi -g -pthread -pedantic -Wall -I../include 

TARGET := test
CC=gcc
OBJS= test.o genericDoubleList.o listItr.o hashMap.o listFunction.o
INCLUDE_PATH= ../include/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

genericDoubleList.o: $(INCLUDE_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -c $(HASH_PATH)genericDoubleList.c

listItr.o: $(INCLUDE_PATH)list_itr.h $(INCLUDE_PATH)listStruct.h $(INCLUDE_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -c listItr.c genericDoubleList.c

listFunction.o: $(INCLUDE_PATH)listFunction.h $(INCLUDE_PATH)list_itr.h
	$(CC) $(CFLAGS) -c listItr.c listFunction.c

hashMap.o: $(INCLUDE_PATH)hashMap.h $(INCLUDE_PATH)listStruct.h $(INCLUDE_PATH)genericDoubleList.h $(INCLUDE_PATH)list_itr.h 
	$(CC) $(CFLAGS) -c listItr.c genericDoubleList.c hashMap.c 

test.o: $(INCLUDE_PATH)mu_test.h 
	$(CC) $(CFLAGS) -c listItr.c genericDoubleList.c hashMap.c test.c listFunction.c

clean:
	@rm -f ./$(TARGET) $(OBJS)


.PHONY : clan

