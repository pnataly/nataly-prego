CFLAGS = -ansi -pedantic -Wall -Werror -Wconversion -Wextra 

TARGET := test
CC=gcc
SOURCE := listTest.c mu_test.h listStruct.h
OBJS= listTest.o  genericDoubleList.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

genericDoubleList.o: genericDoubleList.h
	$(CC) $(CFLAGS) -c genericDoubleList.c


listTest.o: mu_test.h
	$(CC) $(CFLAGS) -c genericDoubleList.c listTest.c 

clean:
	@rm -f ./$(TARGET) $(OBJS)


.PHONY : clan

