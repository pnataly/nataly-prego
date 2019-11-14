#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* func1(void* param)
{
	int i = 10;
	if (param == NULL)
	{
		return NULL;
	}
	while(i>0)
	{
		printf("I'm %s\n", (char*)param);
		i--;
		sleep(1);
	}
	return param;
}

void* func2(void* param)
{
	int i = 5;
	if (param == NULL)
	{
		return NULL;
	}
	while(i>0)
	{
		printf("I'm %s\n", (char*)param);
		i--;
		sleep(2);
	}
	return param;
}

int main()
{
	pthread_t thread1, thread2;
	void* res;
	if (pthread_create(&thread1, NULL, func1, "thread 1") != 0)
	{
		perror ("create thread1");
		return 0;
	}
	if (pthread_create(&thread2, NULL, func2, "thread 2") != 0)
	{
		perror ("create thread2");
		return 0;
	}	
	if (pthread_join(thread1, &res) != 0)
	{
		perror ("pthread_join");
		return 0;
	}
	return 0;
}
