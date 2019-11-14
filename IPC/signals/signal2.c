#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define PARENT_HANDLER_MESSAGE "Parent- receive a signal\n"
#define CHILD_HANDLER_MESSAGE "Child- receive a signal\n"
#define PARENT_MESSAGE "Parent- send a signal\n"
#define CHILD_MESSAGE "Child- send a signal\n"


static void parent_handler (int signal, siginfo_t* siginfo, void *context)
{
	write (1, PARENT_HANDLER_MESSAGE, sizeof(PARENT_HANDLER_MESSAGE));
	sleep(1);
}

static void child_handler (int signal, siginfo_t* siginfo, void *context)
{
	write (1, CHILD_HANDLER_MESSAGE, sizeof(CHILD_HANDLER_MESSAGE));
	sleep(1);
}

void ParentProcess(int p)
{
    struct sigaction act_p;
    act_p.sa_handler = NULL;
    act_p.sa_sigaction = &parent_handler;
    act_p.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act_p, NULL);
	pause();
    if (kill(p, SIGINT) == 0)
	{
		write(1, PARENT_MESSAGE, sizeof(PARENT_MESSAGE));
	}
}

void ChildProcess()
{
    struct sigaction act_c;
    act_c.sa_handler = NULL;
    act_c.sa_sigaction = &child_handler;
    act_c.sa_flags = SA_SIGINFO; 
 	sigaction(SIGINT, &act_c, NULL);
	sleep(1);
	if (kill(getppid(), SIGINT) == 0)
	{
		write(1, CHILD_MESSAGE, sizeof(CHILD_MESSAGE));
	}
	pause();
}

void Signals()
{
	pid_t p;
	p = fork();
	if (p < 0)
	{
		perror ("fork error\n");
		return;
	}
    if (p > 0) 
	{
		ParentProcess(p);
    }
	else
	{
		ChildProcess();
	}
}

int main()
{
	Signals();
    return 0;
}

