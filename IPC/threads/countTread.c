#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* func1(void* param)
{
	sleep(1);
	return param;
}

int main()
{
	int i =1;
	void* res;
	while(1)
	{
		pthread_t thread;
		if (pthread_create(&thread, NULL, func1, NULL) != 0)
		{
			perror ("create thread");
			printf("Created: %d threads\n", i);
			return 0;
		}
		i++;
	}
	return 0;
}
