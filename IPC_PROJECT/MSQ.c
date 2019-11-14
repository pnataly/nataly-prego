#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MSQ.h"
#include "CDR.h"

typedef struct msgbuf
{
    long mtype;       
    char mtext[1];    
}msgbuf;

int CreateMessageQ(char* _filePath)
{
	int id;
	key_t key;

	key = ftok(_filePath, 1);
	if (key < 0)
	{
		perror ("key");
		return 0;
	}

	id = msgget(key, IPC_CREAT | S_IRUSR | S_IWUSR);
	if (id < 0)
	{
		perror ("msgget");
		return 0;
	}
	return id;
}

void MessageQDestroy(int _id)
{
	msgctl(_id, IPC_RMID, NULL); 
}

void* ReadMessage(int msgid, size_t _size, long _msgType)
{
	void* item;
	static int i = 1;
	msgbuf* reader;
	reader = (void*)malloc(sizeof(long) + _size);
	if (reader == NULL)
	{
		return NULL;
	}
	item = (void*)malloc(_size);
	if (item == NULL)
	{
		free(reader);
		return NULL;
	}	
	reader->mtype = _msgType;

	if (msgrcv(msgid, reader, (sizeof(long)+_size), _msgType, MSG_NOERROR) < 0) 
	{
		perror("msgrcv");
		return NULL;
	}
	memcpy(item, reader->mtext, _size);
	printf("item%d received.\n", i);
	i++;
	return item;
}

void SendMessage(int msgid, void* _item, size_t _size, long _msgType)
{
	static int i = 1;
	msgbuf* writer;
	writer = (void*)malloc(sizeof(long) + _size);
	if (writer == NULL)
	{
		return;
	}
	writer->mtype = _msgType;
	memcpy(writer->mtext, _item, _size);

	if (msgsnd(msgid, writer, (sizeof(long)+ _size), IPC_NOWAIT) < 0)
	{
		perror("msgsnd\n");
		return;
	}
	printf("item%d send.\n", i);
	i++;
}

