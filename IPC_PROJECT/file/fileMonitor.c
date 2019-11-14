#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <sys/wait.h>
#include <stdio.h>
#include "fileMonitor.h"

#define SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * ( SIZE + 16 ))
#define STR_LEN	1024
#define NUM_OF_ARGS 5
#define DIR_PATH "./"
#define PROG_PATH "./a.out"

static void Fork(char* _fileName, int _id, long _msgType);

void RunMonitor(int _id, long _msgType)
{
	DIR* dirP;
	int length, i = 0;
	int fd = 0, wd = 0;
	char buffer[BUF_LEN];

	dirP = opendir(DIR_PATH);

	fd = inotify_init();
	if(fd < 0)
	{
		printf("Init Error.\n");
		return;
	}
	wd = inotify_add_watch(fd, DIR_PATH, IN_CREATE); 
	if(wd < 0)
	{
		perror("inotify_add_watch");
		return;
	}
	/* check if there is a new file */
	while(1)
	{
		i = 0;
		length = read(fd, buffer, BUF_LEN);
		if(length < 0)
		{
			perror("read");
			return;
		}
		while(i < length)
		{
			struct inotify_event *event = (struct inotify_event*) &buffer[i];
			if(event->len) 
			{
				if(event->mask & IN_CREATE)
				{

					Fork(event->name, _id, _msgType);
			  		printf("The file %s was created.\n", event->name);
					
			  	}
			}
			i += SIZE + event->len;		
		}
	}
	inotify_rm_watch(fd, wd);
	closedir(dirP);	
	close(fd);
}

static void Fork(char* _fileName, int _id, long _msgType)
{
	pid_t pid;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	if(pid == 0)
	{
		char id[STR_LEN] = {0};
		char type[STR_LEN] = {0};
		char* envp[] = {NULL};
		char* argv[] = {PROG_PATH, _fileName, id, type, NULL};
		sprintf(id,"%d", _id);
		sprintf(type,"%lu", _msgType);
		if((execve(argv[0], argv, envp)) == -1)
		{
			perror ("execve");
			return;
		}
	}
	else
	{
		pid = wait(NULL);
	}
	return;
}

