#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "WQueue.h"
#include "consumer.h"
#include "producer.h"

#define QUEUE_SIZE 7

void elemDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

int main()
{
	size_t num = 5;
	WQ* wq;
	Producer* prod;
	Consumer* cons;
	wq = WQueue_Create(QUEUE_SIZE);
	if (wq == NULL)
	{
		perror ("WQueue_Create");
		return 0;
	}
	prod = Create_Producers(wq, num);
	if (prod == NULL)
	{
		perror ("Create_Producers");
		return 0;
	}
	cons = Create_Consumers(wq, num);
	if (cons == NULL)
	{
		perror ("Create_Consumer");
		return 0;
	}
	Join_Producers(prod);
	Kill_Consumers(cons);
	Join_Consumers(cons);
	WQueue_Destroy(&wq,elemDestroy);
	return 0;
}
