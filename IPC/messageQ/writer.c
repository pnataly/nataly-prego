#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /*usleep*/

#define OPTIONS "cvedf:n:s:"
#define MESSAGE_SIZE 1024
#define FILE_PATH "./messageQ.txt"
#define SIZE 1024 
#define WRITER_TYPE_MSG 1
#define WRITER_TYPE_MSG_END 2
#define WRITER_MSG "message from writer to reader"
#define WRITER_MSG_END "@END!"

typedef struct msgbuf
{
    long mtype;       
    char mtext[1];    
}msgbuf;

typedef struct paramter
{
	int m_isCreate; 			/* -c */
	int m_isVerbos; 			/* -v */
	int m_isEof; 				/* -e */
	int m_isDelete;				/* -d */
	char m_queuePath[SIZE];		/* -f */
	int m_numberOfMessage;		/* -n */
	int m_sleep; 				/* -s */
}Paramter;

static int CreateMessageQ(Paramter* par)
{
	int id;
	key_t key;
	if (par == NULL)
	{
		perror("getopt");
		return 0;
	}
	key = ftok(par->m_queuePath, 1);
	if (key < 0)
	{
		perror ("key");
		return 0;
	}
	if (par->m_isCreate == 1)
	{
		id = msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);
	}
	else
	{
		id = msgget(key, 0);
	}
	if (id < 0)
	{
		perror ("msgget");
		return 0;
	}
	return id;
}


static Paramter* GetParmeters(int argc, char* argv[])
{
	Paramter* par;
	int opt = 0;
	if (argv == NULL)
	{
		return NULL;
	}
	par = (Paramter*) calloc(sizeof(Paramter),1);
	if (par == NULL)
	{
		return NULL;
	}
	strcpy(par->m_queuePath, FILE_PATH);
	while (opt != -1)
	{
		opt = getopt(argc, argv, OPTIONS);
		switch (opt)
		{
			case 'c':
				par->m_isCreate = 1;
				break;

			case 'v':
				par->m_isVerbos = 1;
				break;
		
			case 'e':
				par->m_isEof = 1;
				break;

			case 'd':
				par->m_isDelete = 1;
				break;

			case 'f':
				strcpy(par->m_queuePath, optarg);
				break;

			case 'n':
				par->m_numberOfMessage = atoi(optarg);
				break;

			case 's':
				par->m_sleep = atoi(optarg);
				break;
		}
	}
	return par;
}

static void MessageQDestroy(Paramter* par, int id)
{
	if (par == NULL)
	{
		return;
	}
	free(par);
	msgctl(id, IPC_RMID, NULL); 
}

static void messages(int msgid, Paramter* par)
{
	int i = 1;
	msgbuf* writer_message;
	char message[MESSAGE_SIZE];
	writer_message = (msgbuf*)message;
	if (par == NULL)
	{
		return;
	}
	writer_message->mtype = WRITER_TYPE_MSG; 

	while(par->m_numberOfMessage > 0)
	{
		strcpy(writer_message->mtext, WRITER_MSG);
		if (msgsnd(msgid, (void*)writer_message, sizeof(long)+strlen(writer_message->mtext), IPC_NOWAIT) < 0)
		{
			perror("msgsnd\n");
			return;
		}
		printf("Writer send message: %d.%s \n", i, writer_message->mtext);
		i++;
		if (msgrcv(msgid, message, SIZE, 3, MSG_NOERROR) < 0) 
		{
			perror("msgrcv");
			return;
		}
		printf("message recieve: %d.%s \n", i, writer_message->mtext);
		i++;
		par->m_numberOfMessage--; 
		usleep((par->m_sleep)*1000);
	}
	writer_message->mtype = WRITER_TYPE_MSG_END;
	strcpy(writer_message->mtext, WRITER_MSG_END);
	if (msgsnd(msgid, (void*)writer_message, sizeof(long)+strlen(writer_message->mtext), IPC_NOWAIT) < 0)
	{
		perror("msgsnd\n");
		return;
	}
	if (par->m_isDelete == 1)
	{
		MessageQDestroy(par, msgid);
	}
}

int main(int argc, char* argv[])
{
	Paramter* par;
	int id;
	printf("Writer ready to send messages!\n");
	par = GetParmeters(argc, argv);
	if (par == NULL)
	{
		perror ("getopt\n");
	}
	id = CreateMessageQ(par);
	messages(id, par);
	return 0;
}

