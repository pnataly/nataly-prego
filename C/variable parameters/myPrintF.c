#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int Myprintf(const char* format, ... )
{
	int i;
	int j=0;
	char str[128];
	char* pch;
	char temp[128];
	int lentgh;
	int len;

	va_list list;

	if(format == NULL)
	{
		return 0;
	}

	va_start(list, format);

	strcpy(temp, format);
	len = strlen(temp);
	
	for(i=0; i<len; i++)
	{
		pch = strchr(temp, '%'); 

		while(pch!= NULL)
	  	{
			while(j<*pch)
			{
				strcat(str, (format+j));
				j++;
			}
			if(*(pch+1) == 'd')
			{
				sprintf(str, "%d", va_arg(list,int));
			}
			else if(*(pch+1) == 'f')
			{
				sprintf(str, "%f",va_arg(list,double));
			}
			else if(*(pch+1) == 's')
			{
				sprintf(str, "%s", va_arg(list,char*));
			}
			else if(*(pch+1) == 'c')
			{
				sprintf(str, "%c", va_arg(list,int));
			}
			else
			{
				return 0;
			}

    		pch=strchr(pch+1,'%');
	  	}
	}
	
	lentgh = strlen(str);
	puts(str);
	va_end(list);
	
	return lentgh;
}

int main()
{
	int result;
	char name[] = {"nataly"};
	int age = 26;
	result = Myprintf("my name is: %s and my age is: %d\n", name, age);
	if(result == 0)
	{
		printf("error\n");
	}
	
	return 0;
}
