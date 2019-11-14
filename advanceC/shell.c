#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define STRLEN 1024

int main()
{
	char string[256];
	size_t len;
	pid_t pid;
	pid_t cpid;
	char* tok;
	while(1)
	{
		printf("--->");
		fgets(string,STRLEN,stdin);
		tok = strtok(string, "\n");
		if(tok == NULL)
		{
			continue;
		}
		else if(strcmp(string, "exit") == 0)
		{
			return 0;
		}
		else
		{
			pid = fork();
			if(pid > 0)
			{
				cpid = wait(NULL);
			}	
			else
			{
				char *newargv[] = { string };
				char *newenviron[] = { NULL };	
				printf("I am the son\n");
				execve(string, newargv, newenviron);
			}
		}
	}
	return 0;
}
