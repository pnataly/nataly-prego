#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

#define FILE_PATH "./semaphore.txt"
#define SM_BUF 1024
#define MSG_LENGTH 1024
#define NUM_OF_SEM 3
#define PONG 2
#define PONG_MSG "Pong >> Ping"

typedef struct msgGlasses
{
	int m_msgLen;
	char* m_text[1];
} msgGlasses;

typedef struct MailBox
{
	int m_shmId;	/*shared memory id*/
	int m_semId;	/*semaphores id*/
	void* m_shmp;	/*pointer to the SM*/
	msgGlasses* m_glass;
}MailBox;

static MailBox* CreateMailBox(int semId, int shmId, void* shmp)
{
	MailBox* mail;
	mail = (MailBox*)malloc (sizeof(MailBox));
	if (mail == NULL)
	{
		return NULL;
	}
	mail->m_shmId = shmId;
	mail->m_semId = semId;
	mail->m_shmp = shmp;
	return mail;
}


static void MB_Send(MailBox* mail, void* message)
{
    struct sembuf sops[2];
	if (mail == NULL || message == NULL)
	{
		return;
	}
    sops[0].sem_num = SEM_EMPTY;
    sops[0].sem_op = 0;
    sops[0].sem_flg = 0;
    sops[1].sem_num = SEM_FULL;
    sops[1].sem_op = 1;
    sops[1].sem_flg = 0;
    sops[2].sem_num = SEM_LOCK;
    sops[2].sem_op = 1;
    sops[2].sem_flg = 0;
	mail->m_glass->m_msgLen = sizeof(message);
	memcpy(mail->m_glass->m_text, message,mail->m_glass->m_msgLen);

	printf("Ping writing to shared memory region: %s\n", (char*)message);
	if (semop(mail->m_semId, sops, 2) < 0)
	{
		perror ("semop");
		return;
	}
	sops[0].sem_num = SEM_FULL;    
	sops[0].sem_op = 1;	       
	sops[0].sem_flg = 0;

	sops[1].sem_num = SEM_LOCK;   
	sops[1].sem_op = 1;	       
	sops[1].sem_flg = 0;
	
	if (semop(mail->m_semId, sops, 2) < 0)
	{
		perror ("semop");
		return;
	}
}

static void MB_Recieve(MailBox* mail, int len)
{
	char* msgP;
	msgGlasses* bufP;
	struct sembuf sops[2];
	
	if (mail == NULL)
	{
		perror("Mail box recieve");
		return;
	}
	bufP = (msgGlasses*)msgP;
	bufP->m_msgLen = sizeof(MSG_LENGTH);

	sops[0].sem_num = SEM_FULL;    
	sops[0].sem_op = 1;	       
	sops[0].sem_flg = 0;
	
	sops[1].sem_num = SEM_LOCK;   
	sops[1].sem_op = 1;	       
	sops[1].sem_flg = 0;
	
	if (semop(mail->m_semId, sops, 2) < 0)
	{
		perror ("semop");
		return;
	}
	memcpy(bufP->m_text, mail->m_glass->m_text, len);
	printf("Ping receive message to shared memory : %s\n", (char*)bufP->m_text);
	
	sops[0].sem_num = SEM_EMPTY;       
	sops[0].sem_op = -1;	       
	sops[0].sem_flg = 0;
	
	sops[1].sem_num = SEM_LOCK;  
	sops[1].sem_op = -1;	       
	sops[1].sem_flg = 0;
		
	if (semop(mail->m_semId, sops, 2) < 0)
	{
		perror ("semop");
		return;
	}	
}

MailBox* MboxGet(char* name, int num)
{
	MailBox* mail;
	int semId,shmId;
	void* shmp;
	key_t key;

	key = ftok(name, num);
	if (key < 0)
	{
		perror ("key");
		return NULL;
	}
	semId = semget(key, NUM_OF_SEM, S_IRUSR | S_IWUSR);
	if (semId < 0)
	{
		perror ("semget");
		return NULL;
	}
	shmId = shmget(key, SM_BUF, S_IRUSR | S_IWUSR);
	if (shmId < 0)
	{
		perror("shmget");
		return NULL;
	}
	shmp = shmat(shmId, NULL, 0);
	if (shmp < (void*)0)
	{
		perror ("shmat");
		return NULL;
	}
	mail = CreateMailBox(semId, shmId,shmp);
	return mail;
}



int main()
{
	MailBox* mail;
	mail = MboxGet(FILE_PATH, PONG);
	if (mail == NULL)
	{
		perror ("mail box get");
		return 0;
	} 
	MB_Recieve(mail,MSG_LENGTH);
	MB_Send(mail, PONG_MSG);
	return 0;
}

