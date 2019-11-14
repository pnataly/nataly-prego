#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int main()
{
	sem_t semEmpty;
	int i = 10000;
	if (sem_init(&semEmpty, 0, 0) < 0)
	{
		perror ("sem_init");
	}
	printf("%d\n", i);
	while (i)
	{
		sem_wait(&semEmpty);
		sem_post(&semEmpty);
		i--;
	}
}


