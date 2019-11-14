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
#define MESSAGE_SIZE 108
#define SIZE 1024
#define READER_TYPE_MSG 3
#define READER_MSG "message from reader to writer"
#define FILE_PATH "./messageQ.txt"

typedef struct msgbuf
{
    long mtype;       
    char mtext[1];    
}msgbuf;

typedef struct paramter
{
	int m_isVerbos; 		/* -v */
	int m_isEof; 			/* -e */
	char m_queuePath[SIZE];	/* -f */
	int m_sleep; 			/* -s */
}Paramter;

static int CreateMessageQ(Paramter* par)
{
	int id;
	key_t key;
	key = ftok(par->m_queuePath, 1);
	if (key < 0)
	{
		perror ("key");
		return 0;
	}
	id = msgget (key, 0);
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
			case 'v':
				par->m_isVerbos = 1;
				break;
		
			case 'e':
				par->m_isEof = 1;
				break;

			case 's':
				par->m_sleep = atoi(optarg);
				break;

			case 'f':
				strcpy(par->m_queuePath, optarg);
				break;
		}
	}
	return par;
}

static void messages(int msgid, Paramter* par)
{
	msgbuf* reader_message;
	int i = 1;
	char message[MESSAGE_SIZE];
	reader_message = (msgbuf*)message;
	if (par == NULL)
	{
		return;
	}
	reader_message->mtype = READER_TYPE_MSG; 
	while(1)
	{
		usleep((par->m_sleep)*1000);
		if (msgrcv(msgid, message, SIZE, -2, 0) < 0) 
		{
			perror("msgrcv");
			return;
		}
		if (strcmp(reader_message->mtext, "@END!") == 0)
		{
			printf("Reader exit\n");
			return;
		}
		printf("message recieve: %d.%s \n", i, reader_message->mtext);
		i++;

		strcpy(reader_message->mtext, READER_MSG);
		if (msgsnd(msgid, (void*)reader_message, sizeof(long)+strlen(reader_message->mtext), IPC_NOWAIT) < 0) 
		{
			perror("msgsnd\n");
			return;
		}
		printf("message send: %d.%s \n", i, reader_message->mtext);
		i++; 
	}
}

int main(int argc, char* argv[])
{
	Paramter* par;
	int id;
	par = GetParmeters(argc, argv);
	if (par == NULL)
	{
		perror ("getopt\n");
	}
	printf("Reader ready to recieve messages!\n");
	id = CreateMessageQ(par);
	messages(id, par);
	return 0;
}

