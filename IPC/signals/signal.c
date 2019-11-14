#include <signal.h>
#include <stdio.h>
#include <unistd.h>


static void handler (int signal, siginfo_t* siginfo, void *context);

int main ()
{
    char name[16];
    struct sigaction act;
    
    act.sa_handler = NULL;
    act.sa_sigaction = &handler;
    act.sa_flags = SA_SIGINFO;    

	if (sigaction(SIGINT, &act, NULL) < 0)
	{
		return 0;
	}
    
    printf("Enter you name:\n");
    scanf("%s", name);    
	return 0;
}

static void handler (int signal, siginfo_t* siginfo, void *context)
{
        perror ("\nDon't stop me now!");
}
