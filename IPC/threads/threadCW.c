#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

sem_t sem;

void* func(void* param)
{
	printf("Hi, I'm thread number: %d\n", *((int*)param));
	sem_post(&sem);
	return param;
}

int main()
{
	int i;
	void* res;
	pthread_t thread;
	if (sem_init(&sem, 0, 1) < 0)
	{
		perror ("sem_init");
		return 0;
	}
	for(i=1; i<=10; ++i)
	{
		if (pthread_create(&thread, NULL, func, (void*)&i) != 0)
		{
			perror ("create thread");
			return 0;
		}
		sem_wait(&sem);
	}
	pthread_join(thread, &res);
	return 0;
}
