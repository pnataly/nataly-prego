#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"



char* ToPostfix(char* _infix, char* _profix)
{
	Stack* stack;
	int length;

	int i;
	
	if(_infix == NULL)
	{
		return NULL;
	}

	if(StackCreate(10,0) == NULL)
	{
		return NULL;
	}

	stack = StackCreate(10,0);
	length = strlen(_infix);
	
	for(i=0; i<length; i++)
	{
		if(isdigit(_infix[i]) != 0)
		{
			_profix[i] = _infix[i];
		}
		
		else if((_infix[i] == '+') || (_infix[i] == '\') || (_infix[i] == '*') || (_infix[i] == '-') || (_infix[i] == '('))
		{
			if((StackPush(stack,(int)_infix[i])) != ERR_OK)
			{
				return NULL;
			}
		}

		else if(_infix[i] == ')')
		{
			while(StackTop(stack, (char)_infix[i]-'0') != '(')
			{
				StackPop(stack, (char)_profix[i]-'0');
			}
		}
	}

	i = strlen(_profix);
	while(!StackIsEmpty(stack))
	{
		StackPop(stack, (char) _profix[i]-'0');
		i++;
	}

	return _profix;
}	



int main()
{
	char _infix[64] = {"2+(4+3)*8"};
	char _profix[64];

	printf("%s", ToPostfix(_infix, _profix));

	return 0;
}
