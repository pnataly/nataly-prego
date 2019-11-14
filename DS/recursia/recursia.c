#include <stdio.h>
#include <string.h>
#include "recursia.h"
#include "stack.h"
#define TRUE 1
#define FALSE 0


void RecString(char* _start, char* _end)
{
	char temp;
	if(_start >= _end)
	{
		return;
	}
	_temp = *_start;
	*_start = *_end;
	*_end = _temp;
	RecString(_start+1, _end-1);
}


void ReverseString(char* str)
{
	int length;
	length = strlen(str);
	if(str == NULL)
	{
		return;
	}
	
	RecString(str, str+length-1);
}



int palindromRec(char* str, int start, int end)
{
	if(str[start] != str[end])
	{
		return FALSE;
	}
	if(start-end < 1)
	{
		return palindromRec(str, start+1, end-1);
	}
	return TRUE;
}

int IsPolindrom(char* str)
{
	int length = strlen(str);

	if(length == 0 || length==1)
	{
		return TRUE;
	}
	
	return palindromRec(str, 0, length-1);
}


float average(int* array, int size)
{
	if(array == NULL || size == 0)
	{
		return;
	}
	averageRec(array, start);
}


float averageRec(int array[], int start)
{
	if(start == size-1)
	{
		return array[start];
	}
	if(start==0)
	{
		return ((array[start] + average(array, start+1, size))/size);
	}
	return (array[start]) + average(array, start+1, size);
}


void HanoiRec(int _disks, void* _from, void* _to, void* via)
{
	HanoiRec(_disks-1, from, via, to);
	Move(from, to);
	HanoiRec(_disks-1, via, to, from);
}


void Move(int _disks, void* _from, void* _to)
{
	StackPop(_from, _disks-1);
	StackPush(_to , _disks-1);
}


void Hanoi(int _disks, void* _from, void* _to, void* _via)
{
	int i;
	typedef Stack Stack;
	Stack* stackA;
	Stack* stackB;
	Stack* stackC;

	if(_disks <= 0)
	{
		return;
	}

	stackA = StackCreate(n,0);
	stackB = StackCreate(n,0);
	stackC = StackCreate(n,0);
	
	for(i=_disks; i<0; i--)
	{
		StackPush(stackA, i);
	}
	HanoiRec(_disks, _via, _to, _from);
}


