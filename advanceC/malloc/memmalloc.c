#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include "memmalloc.h"
#define FALSE 0
#define TRUE 1
#define BLOCK_NUM 4


#define END_BLOCK (INT_MAX) + 1 /*10000...*/

/****************************Statics-Functions*************************/

static void* Align(void* _mem)
{
	uintptr_t address;
	address = (uintptr_t)_mem;
	if (address % BLOCK_NUM == 0)
	{
		return _mem;
	}
	address += address % BLOCK_NUM;
	return (void*)address;
	
}

static size_t alignSize(size_t _size)
{
	size_t align;
	align = _size % BLOCK_NUM;
	return (align == 0) ? _size : _size+(BLOCK_NUM-align);
}

static void SetFree(void* _head)
{
	int* ptr;
	ptr = (int*)_head;
	*ptr &= (INT_MAX);
}

static void SetAllocated(void* _head)
{
	int* ptr;
	ptr = (int*)_head;
	*ptr |= (INT_MAX)+1;
}

static size_t GetSize(void* _head)
{
	int* ptr;
	size_t size;
	ptr = (int*)_head;
	size = *ptr & (INT_MAX); 
	return size;
}

static int IsFree(void* _head)
{
	size_t check;
	int* ptr ;
	ptr = (int*)_head;
	check = *ptr >> 31;
	return (check == 0) ? TRUE : FALSE;
}

static void printBinary(size_t _num)
{
	char binary[BLOCK_NUM*CHAR_BIT];
	size_t originalNum;
	int i;
	originalNum = _num & INT_MAX;
	for (i=(BLOCK_NUM*CHAR_BIT)-1; i>=0; i--)
	{
		binary[i] = _num%2;
		_num = _num/2;
	}
		for (i=0; i<(BLOCK_NUM*CHAR_BIT); i++)
	{
		
		printf("%d", binary[i]);
	}	
	printf(" %lu",originalNum);
	printf("\n ");	
}

static void split(void* _head,size_t _size)
{
	size_t first; 
	char* ptr;
	ptr = (char*)_head;
	first = GetSize(ptr);
	*(int*)ptr = _size;
	SetAllocated(ptr);
	ptr = ptr + _size;
	*(int*)ptr = first-_size;
	SetFree(ptr);
}

static void initHeader(void* _head,size_t _size)
{
	char* ptr;
	ptr = (char*)_head;
	*(size_t*)ptr = _size;
	SetFree(ptr);
	ptr += _size;
	*(int*)ptr = END_BLOCK;
}

/***************************Main-Functions******************************/
void* memInit(void* _mem, size_t _size)
{
	if (_mem == NULL || _size == 0 || _size >= INT_MAX/2)
	{
		return NULL;
	}
	_mem = Align(_mem);
	initHeader(_mem,_size);
	return _mem;
}


void* memMalloc(void* _buffStart, size_t _size)
{
	char* pointer;
	size_t blockSize;
	_size = alignSize(_size);
	pointer = (char*)_buffStart;
	if (NULL == _buffStart || _size == 0 || _size >= INT_MAX)
	{
		return NULL;
	}
	blockSize = GetSize(_buffStart);
	while (IsFree(pointer) == FALSE || blockSize < _size + sizeof(int))
	{
		pointer += blockSize;
		blockSize = GetSize((void*)pointer);
		if (*(int*)pointer == END_BLOCK)
		{
			return NULL;
		}
	}
	split((void*)pointer,_size);
	return (void*)pointer;
}
	
void memFree(void* _buff)
{
	if (_buff == NULL)
	{
		return;
	}
	char* ptr;
	size_t size;
	ptr = _buff;
	size = GetSize(ptr);
	ptr += size;
	if (IsFree(ptr) == TRUE)
	{
		size += GetSize(ptr);
	}
	*(int*)_buff = size;
	SetFree(_buff);
	return;

}
		
void mallocForEach(void* _buffStart)
{
	char* ptr;
	size_t size;
	ptr = (char*)_buffStart;
	if (_buffStart == NULL)
	{
		return;
	}
	size = GetSize(_buffStart);
	while (1)
	{
		 printBinary(*(int*)ptr);
		 if(IsFree(ptr) == TRUE)
		 {
		 	printf("Free\n");
		 }
		 else
		 {
		 	printf("Allocated\n");
		 }
		 ptr += size;
		 size = GetSize((void*)ptr);
		 if (*(int*)ptr == END_BLOCK)
		 {
		 	printf("End of the block\n");
		 	return;
		 } 
	}
}

