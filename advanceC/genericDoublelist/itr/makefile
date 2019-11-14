CFLAGS = -ansi -pedantic -Wall -Werror -Wconversion -Wextra 

TARGET := test
CC=gcc
SOURCE := itrTest.c mu_test.h listStruct.h
OBJS= itrTest.o  genericDoubleList.o listItr.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

genericDoubleList.o: genericDoubleList.h
	$(CC) $(CFLAGS) -c genericDoubleList.c

listItr.o: genericDoubleList.h list_itr.h
	$(CC) $(CFLAGS) -c genericDoubleList.c listItr.c

itrTest.o: mu_test.h
	$(CC) $(CFLAGS) -c genericDoubleList.c itrTest.c listItr.c

clean:
	@rm -f ./$(TARGET) 


.PHONY : clan

