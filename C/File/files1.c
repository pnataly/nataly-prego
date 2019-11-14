#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files.h"

void ReadNLines(char* _name, int _numOfNLines)
{
	FILE* _pFile;
	char _line[128];
	int* _array;
	int i=0;

	_array=(int*) malloc(sizeof(int)*_numOfNLines);
	if(_array == NULL)
	{
		return;
	}
	if((_pFile = fopen(_name, "r")) == NULL)
	{
		return;
	}

	while(fgets(_line,128,_pFile) != NULL)
	{
		_array[(i+1)%_numOfNLines] = ftell(_pFile);	
		i++;
	}

	if(fseek(_pFile, _array[(i+1)%_numOfNLines] ,0)!=0)
	{
		return; 
	}
		
	while(!feof(_pFile))
	{
		if(fseek(_pFile, _array[(i+1)%_numOfNLines] ,0) != 0)
		{

			return;
		}
		fgets(_line,128,_pFile);
		printf("%s", _line);
		i++;

	}

	if(fclose(_pFile) != 0)
	{
		return;
	}

	return;
}


void CountLetters(char* _name)
{
	int value;
	int count[256]= {0};
	FILE* _pFile;
	int c;
	if((_pFile = fopen(_name, "r")) == NULL)
	{
		return 0;
	}
	while((c = fgetc(_pFile)))
	{
		if(c==EOF)
		{
			break;
		}
		count[c]++;
	}
	for(value=65; value<123; value++)
	{
		if(count[value]>0)
		{
			printf("char %c: %d times\n\n", value, count[value]);
		}
	}

	if(fclose(_pFile) != 0)
	{
		return 0;
	}

	return 1;
}


void CountWords(char* _name)
{
	FILE* _pFile;
	char x[128]={0};
	char _line[128];
	char* _temp;
	if((_pFile = fopen(_name, "r")) == NULL)
	{
		return 0;
	}
	while(fgets(_line,128,_pFile) != NULL)
	{
		_temp = strtok(_line, " ,.-'");

		while(_temp != NULL)
		{
			printf("%s\n", _temp);
			_temp = strtok(NULL," ,.-'");
		}
	}
	return 1;
}


