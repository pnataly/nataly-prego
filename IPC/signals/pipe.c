#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <string.h>

#define PARENT_MESSAGE "I'm your father."
#define CHILD_MESSAGE "I'm your son."
#define READER_BUFFER_SIZE 512

static int PipeCreate(int* pipe1, int* pipe2)
{
	int status;

	if ((status = pipe(pipe1)) < 0)
	{
		return status;
	}
	if ((status = pipe(pipe2)) < 0)
	{
		return status;
	}
	return 0;
}

static void ParentProcess(int* PtoCpipe, int* CtoPpipe)
{
	char output[READER_BUFFER_SIZE];
	close(PtoCpipe[0]);
	write(PtoCpipe[1], PARENT_MESSAGE, sizeof(PARENT_MESSAGE));
	printf("parent send: I'm your father.\n");
    close(PtoCpipe[1]);

	close(CtoPpipe[1]);
	read(CtoPpipe[0], output, READER_BUFFER_SIZE);	
	printf("parent receive: %s\n", output);
	close(CtoPpipe[0]);

}

static void ChildProcess(int* PtoCpipe, int* CtoPpipe)
{
	char output[READER_BUFFER_SIZE];
	close(PtoCpipe[1]);
	read(PtoCpipe[0], output, READER_BUFFER_SIZE); 
	printf("child receive: %s\n", output);
	close(PtoCpipe[0]);

	close(CtoPpipe[0]);
	write(CtoPpipe[1], CHILD_MESSAGE, sizeof(CHILD_MESSAGE)); 
	printf("child send: I'm your son.\n");
    close(CtoPpipe[1]);
}

void PipeMessaging()
{
	int PtoCpipe[2];
	int CtoPpipe[2];
	int status;
	pid_t p;

	status = PipeCreate(PtoCpipe, CtoPpipe);
	if (status < 0)
	{
		return;
	}

	p = fork();
	if(p < 0)
	{
		perror ("fork fail\n");
		return;
	}

	if (p > 0)
	{
		ParentProcess(PtoCpipe, CtoPpipe);
	}

	else
	{
		ChildProcess(PtoCpipe, CtoPpipe);
	}
	return;
}

int main ()
{
	PipeMessaging();
	return 0;
}
