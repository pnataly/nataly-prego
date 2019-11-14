#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CDR.h"
#include "MSQ.h"

#define BUF_LEN 128

int fileHandler(const char* _fname, int _id, long _msgType)
{
	FILE* fp;
	char* line;
	CDR cdr;

	if(_fname == NULL)
	{ 
		return 0;
	}
	fp = fopen(_fname , "r");
	if(!fp) 
	{
		return 0;
	}
	line = (char*)malloc(sizeof(char)*BUF_LEN);
	if (line == NULL)
	{
		return 0;
	}
	
	/* read line from the file - create cdr and send to the MSQ	*/
	while (fgets(line, BUF_LEN, fp) != NULL)
	{
		cdr = CreateCDR(line);
	
		SendMessage(_id, &cdr, (sizeof(CDR)+sizeof(long)), _msgType);
	} 
	fclose(fp);
	return 0;
}



int main(int argc, char* argv[])
{
	char name[BUF_LEN];	
	int id = atoi(argv[2]);
	long type = (long)atoi(argv[3]);
	strcpy(name, argv[1]);	
	
	fileHandler(argv[1], id, type);
	return 0;
}


