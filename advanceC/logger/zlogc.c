#include <stdio.h>
#include <string.h>
#include <stdarg.h> 
#include <pthread.h>
#include "zlogc.h"


#define LINE_LENGTH 64
#define NUM_OF_LEVELS 9
#define TRUE 1
#define FALSE 0



typedef struct ZLog 
{
	int m_level;
	FILE* m_file;
}ZLog;

static ZLog zLog;




/*translate the log level string to an int, to match the LOG_LEVEL enum*/
static int GetLogLevel(char* _level);

/*get first letter of user's log level*/
static char GetUserLevel(int _level);

/*check if the message 
int IsAboveLevel(int _userLevel);


/*extract message level and log file name from the config file and open lof file*/
void zlog_init(const char* _configFile)
{
	char line[LINE_LENGTH]; 
	char* level;
	char* path;
	char* filePath;
	FILE* fp;

	fp=fopen(_configFile, "r");
	if(!fp)
	{
		return;
	}

	/*get line#1 from the config file*/
	fgets(line,LINE_LENGTH,fp);
	/*extract LOG_X*/
	level=strchr(line,'=');
	level++;
	level++;
	strtok(level,"\n");
	zLog.m_level=GetLogLevel(level);

	/*get line#2 from the config file*/
	fgets(line,LINE_LENGTH,fp);
	/*extract path*/
	path=strchr(line,'/');
	strtok(path,"\n");

	/*open log file for writing*/ 
	zLog.m_file=fopen(path,"a");
	if(!zLog.m_file)
	{
		return;
	}

	fclose(fp);
}

/*translate the log level string to an int, to match the LOG_LEVEL enum*/
static int GetLogLevel(char* _level)
{
	int i;
	char* levelsArr[NUM_OF_LEVELS]={"LOG_TRACE","LOG_DEBUG","LOG_INFO","LOG_WARNING","LOG_ERROR","LOG_CRITICAL","LOG_SEVERE","LOG_FATAL","LOG_NONE"};
	
	for(i=0; i <NUM_OF_LEVELS; i++)
	{
		if(strcmp(_level,levelsArr[i]) == 0)
		{
			return i;
		}
	}
}



/*determine if the user's log level is above the log level configured*/
int IsAboveLevel(int _userLevel)
{
	if(_userLevel >= zLog.m_level)
	{
		return TRUE;
	}

	return FALSE;
}



/*print log entry*/
void PrintLogEntry(char* _fileName, char* _funcName , int _line, int _userLevel,char _mode,const char* _message,...)
{
	va_list args;
	va_start (args,_message);

	/*debug mode*/
	if(_mode=='D')
	{	
		fprintf(zLog.m_file,"%s %s %d %lu %c %s@%s:%d ",__DATE__,__TIME__
	   ,getpid(),pthread_self(),GetUserLevel(_userLevel),_funcName,_fileName,_line);
		vfprintf(zLog.m_file,_message,args);
		fprintf(zLog.m_file,"\n");
	}
	/*release mode*/
	else
	{
		fprintf(zLog.m_file,"%s %s %d %lu %c ",__DATE__,__TIME__
	   ,getpid(),pthread_self(),GetUserLevel(_userLevel));
		vfprintf(zLog.m_file,_message,args);
		fprintf(zLog.m_file,"\n");
	}
	
	va_end(args);
}



/*get first letter of user's log level*/
static char GetUserLevel(int _level)
{
	switch (_level)
	{	
		case LOG_TRACE: return 'T';
		case LOG_DEBUG: return 'D';
		case LOG_INFO: return 'I';
		case LOG_WARNING: return 'W';
		case LOG_CRITICAL: return 'C';
		case LOG_SEVERE: return 'S';
		case LOG_FATAL: return 'F';
		case LOG_NONE: return 'N';
	}
}





