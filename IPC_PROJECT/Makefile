#IPC Project Makefile

CFLAGS = -g -pedantic -Wall -I$(INCLUDE_PATH) -I$(INCLUDE_HASH_PATH) -I$(INCLUDE_LOCKER_PATH)

TARGET := ipc
CC=gcc -pthread
OBJS= genericDoubleList.o listItr.o hashMap.o listFunction.o safeHash.o CDR.o subAgr.o subscriber.o locker.o aggregator.o operator.o oprAgr.o MSQ.o QM.o insight.o
INCLUDE_PATH= ./include/
SAFE_PATH= ./safeHash/
INCLUDE_HASH_PATH= ../advanceC/include/
HASH_PATH= ../advanceC/hashMap/
LOCKER_PATH= ../IPC/Locker/
INCLUDE_LOCKER_PATH= ../IPC/include/

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

genericDoubleList.o: $(INCLUDE_HASH_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -c $(HASH_PATH)genericDoubleList.c

listItr.o: $(INCLUDE_HASH_PATH)list_itr.h $(INCLUDE_HASH_PATH)listStruct.h $(INCLUDE_HASH_PATH)genericDoubleList.h
	$(CC) $(CFLAGS) -c $(HASH_PATH)listItr.c $(HASH_PATH)genericDoubleList.c

listFunction.o: $(INCLUDE_HASH_PATH)listFunction.h $(INCLUDE_HASH_PATH)list_itr.h
	$(CC) $(CFLAGS) -c $(HASH_PATH)listItr.c $(HASH_PATH)listFunction.c

hashMap.o: $(INCLUDE_HASH_PATH)hashMap.h $(INCLUDE_HASH_PATH)listStruct.h $(INCLUDE_HASH_PATH)genericDoubleList.h $(INCLUDE_HASH_PATH)list_itr.h 
	$(CC) $(CFLAGS) -c $(HASH_PATH)listItr.c $(HASH_PATH)genericDoubleList.c $(HASH_PATH)hashMap.c 

locker.o: $(INCLUDE_LOCKER_PATH)locker.h
	$(CC) $(CFLAGS) -c $(LOCKER_PATH)locker.c

safeHash.o: $(INCLUDE_PATH)safeHash.h $(INCLUDE_HASH_PATH)hashMap.h $(INCLUDE_LOCKER_PATH)locker.h
		$(CC) $(CFLAGS) -c $(SAFE_PATH)safeHash.c $(HASH_PATH)hashMap.c $(LOCKER_PATH)locker.c

CDR.o: $(INCLUDE_PATH)CDR.h
		$(CC) $(CFLAGS) -c CDR.c

MSQ.o: $(INCLUDE_PATH)MSQ.h $(INCLUDE_PATH)CDR.h
	$(CC) $(CFLAGS) -c MSQ.c 

subscriber.o: $(INCLUDE_PATH)subscriber.h $(INCLUDE_PATH)CDR.h
		$(CC) $(CFLAGS) -c subscriber.c CDR.c

operator.o: $(INCLUDE_PATH)operator.h $(INCLUDE_PATH)CDR.h
		$(CC) $(CFLAGS) -c operator.c CDR.c

subAgr.o: $(INCLUDE_PATH)subAgr.h $(INCLUDE_PATH)safeHash.h $(INCLUDE_PATH)CDR.h $(INCLUDE_PATH)subscriber.h
		$(CC) $(CFLAGS) -c subAgr.c CDR.c $(SAFE_PATH)safeHash.c subscriber.c

oprAgr.o: $(INCLUDE_PATH)oprAgr.h $(INCLUDE_PATH)safeHash.h $(INCLUDE_PATH)CDR.h $(INCLUDE_PATH)operator.h
		$(CC) $(CFLAGS) -c oprAgr.c CDR.c $(SAFE_PATH)safeHash.c operator.c

QM.o: $(INCLUDE_PATH)QM.h $(INCLUDE_PATH)subAgr.h 
		$(CC) $(CFLAGS) -c QM.c subAgr.c 

aggregator.o: $(INCLUDE_PATH)aggregator.h $(INCLUDE_PATH)subAgr.h $(INCLUDE_PATH)CDR.h $(INCLUDE_PATH)oprAgr.h 
		$(CC) $(CFLAGS) -c subAgr.c aggregator.c CDR.c oprAgr.c 

insight.o: $(INCLUDE_PATH)aggregator.h $(INCLUDE_PATH)subAgr.h $(INCLUDE_PATH)CDR.h $(INCLUDE_PATH)oprAgr.h $(INCLUDE_PATH)MSQ.h
		$(CC) $(CFLAGS) -c subAgr.c aggregator.c CDR.c oprAgr.c MSQ.c QM.c insight.c 

clean:
	rm -f $(TARGET) $(OBJS)


.PHONY : clan

