#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "WQueue.h"
#include "consumer.h"
#include "producer.h"

#define ITEM_NUM 5

void elemDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

int main()
{
	WQ* wq;
	Producer* prod;
	Consumer* cons;
	wq = WQueue_Create(ITEM_NUM);
	if (wq == NULL)
	{
		perror ("WQueue_Create");
		return 0;
	}
	prod = Create_Producers(wq, ITEM_NUM);
	if (prod == NULL)
	{
		perror ("Create_Producers");
		return 0;
	}
	cons = Create_Consumers(wq, ITEM_NUM);
	if (cons == NULL)
	{
		perror ("Create_Consumer");
		return 0;
	}
	RunProd(wq, prod);
	RunCons(wq, cons);
	Join_Producers(prod);
	Kill_Consumers(cons);
	Join_Consumers(cons);
	WQueue_Destroy(&wq, elemDestroy);
	Destroy_Prod(prod);
	Destroy_Cons(cons);
	return 0;
}

