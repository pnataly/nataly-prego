#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "strings.h"

int main()
{

	char _str1[128];
	char _str2[128];
	char _str3[128];
	char _string[128];
	int result;

	printf("Please enter your first string:\n");
	scanf("%s", _str1);
	printf("Please enter your second string:\n");
	scanf("%s", _str2);

	result = MyStrcmp(_str1, _str2);
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



	if(MyStrcpy(_str2, _str1) != NULL)
	{
		printf("After copy str1 to str2: %s\n\n", _str2);
	}
	else
	{
		printf("NULL ERROR");
	}


	printf("Enter anothe string to concatenate:\n");
	scanf("%s", _str3);
	
	if(MyStrcat(_str2, _str3) != NULL)
	{
		printf("After concatenate str3 to str2: %s\n", _str2);
	}
	else
	{
		printf("NULL ERROR");
	}


	printf("Enter a string:\n");
	scanf("%s", _string);
	result = MyAtoi(_string);


	if(result == -1)
	{
		printf("NULL ERROR\n");
	}

	else
	{
		printf("The integer value of the string: %d\n", result);
	}


	return 0;
}
