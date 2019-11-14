#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <MSQ.h>
#include "subscriber.h"

#define MSQ_FILE_PATH "messageQ.txt"
#define MSG_TYPE 2
#define BUF_LEN 1024

int main()
{
	int id;
	void* res;
	pid_t pid;
	size_t array[]={1,16, 42503};
	void* item;
	
	id = CreateMessageQ(MSQ_FILE_PATH);
	pid = getpid();
	
printf("process id: %d\n", pid);

	/* HandShake message to insight */
	SendMessage(id, &pid, sizeof(size_t), MSG_TYPE);
	
	/* send query request */
	SendMessage(id, &array[0], sizeof(size_t), ((pid*2)+1));
	sleep(1);
	res =  ReadMessage(id, BUF_LEN, ((pid*2)+1)); 
	printf("the read message: %s\n", (char*)res);
	return 0;
}
