#Makefile -dynamic library

TARGET= libDDS.so
TEST= vectorTests
CC= gcc
CFLAGS= -c -ansi -pedantic -Wall -I../include/
OBJS= genericVector.o genericQueue.o genericDoubleList.o listItr.o listFunction.o genericBst.o genericHeap.o hashMap.o

INCLUDE_PATH= ../include/
INCLUDE_VECTOR= ../genericVector/
INCLUDE_QUEUE= ../genericQueue/
INCLUDE_LIST= ../genericDoublelist/
INCLUDE_BST= ../genericTree/
INCLUDE_HEAP= ../genericHeap/
INCLUDE_HASH= ../hashMap/

.PHONY: clean all


$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) -shared $(OBJS)

genericVector.o: $(INCLUDE_VECTOR)genericVector.c $(INCLUDE_PATH)genericVector.h $(INCLUDE_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_VECTOR)genericVector.c

genericQueue.o: $(INCLUDE_QUEUE)genericQueue.c $(INCLUDE_PATH)genericQueue.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_QUEUE)genericQueue.c

genericDoubleList.o: $(INCLUDE_LIST)genericDoubleList.c $(INCLUDE_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_LIST)genericDoubleList.c

listItr.o: $(INCLUDE_LIST)listItr.c $(INCLUDE_PATH)list_itr.h $(INCLUDE_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_LIST)listItr.c

listFunction.o: $(INCLUDE_LIST)listFunction.c $(INCLUDE_PATH)listFunction.h $(INCLUDE_PATH)list_itr.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_LIST)listFunction.c

genericBst.o: $(INCLUDE_BST)genericBst.c $(INCLUDE_PATH)genericBst.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_BST)genericBst.c

genericHeap.o: $(INCLUDE_HEAP)genericHeap.c $(INCLUDE_PATH)genericHeap.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_HEAP)genericHeap.c


hashMap.o: $(INCLUDE_HASH)hashMap.c $(INCLUDE_PATH)hashMap.h
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_HASH)hashMap.c

clean:
	rm -f $(TARGET) $(OBJS)
