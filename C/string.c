#include <stdio.h>
#include <string.h>


size_t StrLen(const char* _str)
{
	int i = 0;
	size_t length = 0;		
	if(_str == NULL)
	{
		return 0;
	}
	while (_str[i] != '\0')
	{
		length++;	
		i++;
	}
	return length; 
}

size_t StrLenRec(const char* _str)
{
	if(_str == NULL)
	{
		return 0;
	}
	if(*_str == '\0')
	{
		return 0;
	}
	return StrLenRec(_str+1)+1;

}

int StrCompare(const char* _s1, const char* _s2)
{
	int index=0;
	int result;
	if(_s1 == NULL || _s2 == NULL)
	{
		return -1;
	}
	while(_s1[index] == _s2[index])
	{
		if(_s1[index] == '\0' && _s2[index] == '\0')
		{
			result = 0;
			break; 
		}
		index++;
	}

	if(_s1[index] > _s2[index])
	{
		result = (_s1[index] - _s2[index]); 
	}
	if(_s1[index] < _s2[index])
	{
		result = (_s1[index] - _s2[index]); 
	}
	return result;
}

int StrCompareRec(const char* _s1, const char* _s2)
{

	if(_s1 == NULL || _s2 == NULL)
	{
		return -1;
	}

	if(*_s1 == '\0' && *_s2 == '\0')
	{
		return 0;
	}

	if(*_s1 > *_s2)
	{
		return (*_s1 - *_s2); 
	}
	if(*_s1 < *_s2)
	{
		return (*_s1 - *_s2); 
	}
	return StrCompareRec(_s1+1, _s2+1);
}


char* StrCopy(char* _destination, const char* _source)
{
	int index = 0;

	if((_destination != NULL) && (_source!= NULL))
	{
		while(_source[index] != '\0')
		{
			_destination[index] = _source[index];
			index++;
		}

		_destination[index] = '\0';

		return _destination;
	}
	return NULL;
}

char* StrCopyRec(char* _destination, const char* _source)
{
	if((_destination == NULL) && (_source == NULL))
	{
		return NULL;
	}

	if(*_source == '\0')
	{
		*_destination =  *_source;
		return _destination;
	}

	*_destination =  *_source;
	StrCopyRec(_destination+1, _source+1);
	return _destination;
}


char* StrNCopy(char* _destination, const char* _source, size_t _num)
{
	if((_destination == NULL) && (_source == NULL))
	{
		return NULL;
	}
	while(*_source == '\0' || _num == 0)
	{
		*_destination = *_source;
		*_destination++;
		*_source++;
		_num--;
	}
	*_destination = '\0';
	return _destination;
}

char* StrNCopyRec(char* _destination, const char* _source, size_t _num)
{
	if((_destination == NULL) && (_source == NULL))
	{
		return NULL;
	}

	if(*_source == '\0' || _num == 0)
	{
		*_destination =  '\0';
		return _destination;
	}

	*_destination =  *_source;
	_num--;
	StrNCopyRec(_destination+1, _source+1, _num);
	return _destination;
}


char* StrConcat(char* _destination, const char* _source)
{
	if((NULL != _destination) && (NULL != _source))
	{
		while('\0' != *_destination)
		{
			_destination++;
		}

		*_destination = ' ';
		_destination++;

		while('\0' != *_source)
		{
			*_destination++ = *_source++;
		}
		*_destination = '\0';
		return _destination;
	}
	return NULL;
}



int main()
{
	char name[7]= {"nataly"};
	char _str1[128];
	char _str2[128];
	int result;
	printf("Please enter your first string:\n");
	scanf("%s", _str1);
	printf("Please enter your second string:\n");
	scanf("%s", _str2);
	
/*
	if(result == 0)
	{
		printf("The contents of both strings are equal\n");
	}
	
	else if(result>0)
	{
		printf("The contents of the first string is higher\n");
	}
	else
	{
		printf("The contents of the second string is higher\n");
	}

	if(result(_str2, _str1,) != NULL)
	{
		printf("After copy str1 to str2: %s\n\n", _str2);
	}
	else
	{
		printf("NULL ERROR");
	}
	printf("The length: %ld\n", StrLenRec(name));
*/

	return 0;
}
