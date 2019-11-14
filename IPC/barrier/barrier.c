#include <pthread.h>
#include <stdio.h> 
#include <stdlib.h> 

#define NUM_OF_THREADS 5
#define NUM_OF_ROUNDS 3
#define ARR_SIZE 4

pthread_barrier_t barrier; 

void* ThreadFunction(void* arg)
{
	int i=0;
	int max = rand()%10;
	for (i=0; i<max; i++)
	{
		(*(int*)arg)++;
	}
	pthread_barrier_wait(&barrier);
	pthread_barrier_wait(&barrier);
	return NULL;
}

void* ThreadFunctionSum(void* arg)
{
	int i;
	static int res = 0;
	pthread_barrier_wait(&barrier);
	for (i=0; i<4; i++)
    {
    	printf("%d ",(int)((int*)arg)[i]);
		res += (int)((int*)arg)[i];
    }
    printf("\n");
	printf("The sum: %d\n",res);
    pthread_barrier_wait(&barrier);
	return NULL;
}

void ThreadsRun(pthread_barrier_t _barrier, int* _array, pthread_t* _threadsArray)
{
    int i;
    for (i=0; i<NUM_OF_THREADS-1; i++)
    {
    	if (pthread_create(&_threadsArray[i], NULL, ThreadFunction, _array+i) != 0)
		{
			perror("pthread_create");
			break;
		}
		printf("Thread %d created\n",i);
    }
    i++;
    if (pthread_create(&_threadsArray[i], NULL, ThreadFunctionSum, _array) != 0)
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
	int* array;
	int i;
	pthread_t* threadsArray;
	array = (int*)calloc(ARR_SIZE,sizeof(int));
	if (array == NULL)
	{
		return 0;
	}
	threadsArray = (pthread_t*)malloc(NUM_OF_THREADS*sizeof(pthread_t));
	if (threadsArray == NULL)
	{
		return 0;
	}
	if (pthread_barrier_init(&barrier, NULL, NUM_OF_THREADS) != 0)
	{
		perror("barrier init");
		return 0;
	}
	for (i = 0; i< NUM_OF_ROUNDS; i++)
	{
		ThreadsRun(barrier,array,threadsArray);
	}
    if (pthread_barrier_destroy(&barrier) != 0)
    {	
    	perror("barrier_destroy");
		return 0;
	}
	return 0;
}

