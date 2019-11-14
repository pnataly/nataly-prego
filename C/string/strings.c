#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "strings.h"


int MyStrcmp(const char* _str1, const char* _str2)
{
	int index=0;
	int result;

	while(_str1[index] == _str2[index])
	{
		if(_str1[index] == '\0' && _str2[index] == '\0')
		{
			result = 0;
			break; 
		}
		index++;
	}

	if(_str1[index] > _str2[index])
	{
		result = (_str1[index] - _str2[index]); 
	}
	if(_str1[index] < _str2[index])
	{
		result = (_str1[index] - _str2[index]); 
	}
	return result;
}


char* MyStrcpy(char* destination, const char* source)
{
	int index = 0;

	if((NULL != destination) && (NULL != source))
	{
		while(source[index] != '\0')
		{
			destination[index] = source[index];
			index++;
		}

		destination[index] = '\0';

		return destination;
	}
	return NULL;
}



char* MyStrcat(char* destination, const char* source)
{
	
	if((NULL != destination) && (NULL != source))
	{
		while('\0' != *destination)
		{
			destination++;
		}

		*destination = ' ';
		destination++;

		while('\0' != *source)
		{
			*destination++ = *source++;
		}
		*destination = '\0';
		return destination;
	}
	return NULL;
}


int MyAtoi(char* string)
{
	int _result = 0;
	int sign = 1;
	int index = 0;

	if(string != NULL)
	{
		while(string[index] != '\0')
		{	
	
			if(isspace(string[index])!= 0 || (string[index]) == '+')
			{
				index++;
				continue;
			}

			if(isalpha(string[0]) != 0)
			{
				return 0;
			}

			if((string[index]) == '-')
			{
				sign = -1;
				index++;
			}
	
			else if(isalpha(string[index]) != 0)
			{
				break;
			}

			else if(isdigit(string[index]) != 0)
			{
				_result = _result * 10 + string[index] - '0'; 
				index++;
			}
		}
		return (_result*sign);
	}
	return -1;
}

