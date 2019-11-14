#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>


int main()
{
	int semId;
	key_t key;
    struct sembuf sops[1];
	int i = 10000;
	key = ftok("semaphore.txt", 1);
	if (key < 0)
	{
		perror ("key");
	}
	semId = semget(key, 1, IPC_CREAT);
	if (semId < 0)
	{
		perror ("semget");
	}
	if(semctl(semId, 0, SETVAL ,1) <0)
	{
		perror("semctl");
	}
	while (i)
	{
		sops[0].sem_num = 0;       
		sops[0].sem_op = -1;	       
		sops[0].sem_flg = 0;
		if (semop(semId, sops, 1) < 0)
		{
			perror ("semop");
		}
		sops[1].sem_num = 0;   
		sops[1].sem_op = 1;	       
		sops[1].sem_flg = 0;
		if (semop(semId, sops, 1) < 0)
		{
			perror ("semop");
		}
		i--;
	}
	return 0;
}
