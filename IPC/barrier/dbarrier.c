#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "dblBarr.h"

#define NUM_OF_THREADS 5
#define ARR_SIZE 4
#define NUM_OF_ROUNDS 3


struct Packet
{
	int* m_array;
	DB* m_db;
};

typedef struct Packet Packet;

void* ThreadFunction(void* arg)
{
	int i=0;
	int max = rand()%10;
	BarrWait(((Packet*)arg)->m_db, NULL, NULL);
	for (i=0; i<max; i++)
	{
		((Packet*)arg)->m_array[i]++;
	}
	return NULL;
}

void ThreadFunctionPrint(void* arg)
{
	int i;
	static int res = 0;

	for (i=0; i<4; i++)
    {
    	printf("%d ",(int)((int*)arg)[i]);
		res += (int)((int*)arg)[i];
    }
    printf("\n");
	printf("The sum: %d\n",res);
}

void* ThreadFunctionSum(void* arg)
{
	BarrWait(((Packet*)arg)->m_db, ThreadFunctionPrint, ((Packet*)arg)->m_array);
	return NULL;
}


void ThreadsRun(Packet* _packet, pthread_t* _threadsArray)
{
    int i;
    for (i=0; i<NUM_OF_THREADS-1; i++)
    {
    	if (pthread_create(&_threadsArray[i], NULL, ThreadFunction, _packet) != 0)
		{
			perror("pthread_create");
			break;
		}
		printf("Thread %d created\n",i);
    }
    i++;
    if (pthread_create(&_threadsArray[i], NULL, ThreadFunctionSum, _packet) != 0)
	{
		perror("pthread_create");
		return;
	}
    for (i=0; i<NUM_OF_THREADS; i++)
	{
		if(pthread_join(_threadsArray[i],NULL) != 0)
		{
			perror("pthread_join");
			return;
		}
	}
}

int main()
{
	DB* db;
	Packet* packet;
	int* array;
	int i;
	pthread_t* threadsArray;
	db = CreateDoubleBarrier(NUM_OF_THREADS);
	if (db == NULL)
	{
		return 0;
	}
	array = (int*)calloc(ARR_SIZE,sizeof(int));
	if (array == NULL)
	{
		return 0;
	}
	packet = (Packet*)malloc(sizeof(Packet));
	if (packet == NULL)
	{
		return 0;
	}
	packet->m_array = array;
	packet->m_db = db;
	threadsArray = (pthread_t*)malloc(NUM_OF_THREADS*sizeof(pthread_t));
	if (threadsArray == NULL)
	{
		return 0;
	}
	for (i=0; i<NUM_OF_ROUNDS; i++)
	{
		ThreadsRun(packet,threadsArray);
	}
	DestroyDoubleBarrier(&packet->m_db);
	free(packet->m_array);
	free(packet);
	return 0;
}

