#include <stdio.h>
#include <string.h>

int StringLength(const char* _str)
{
	int i = 0;
	int length = 0;		
	while (_str[i] != '\0')
	{
		length++;	
		i++;
	}
	return length; 
}

void PrintReverseString(const char* string, int length)
{
	int i;

	for (i=length-1; i>= 0; i--)
	{
		printf("%c", string[i]);
	}
	printf("\n"); 

	return;
}
void printToken(char* string)
{
	char* token;
	token = strtok(string, " ");
	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
return;
}

void BinaryOrDecimal()
{
	int choise;
	int binaryNum;
	int decimalNum;
	int binary[10];
	int i =0;
	int base =1;
	int j;
	int reminder;
	int decimal_val=0;
	printf("Enter your choise:\n ");
	printf("1.Binary number\n");
	printf("2.Decimal number\n");
	scanf("%d", &choise);
	switch (choise)
	{
		case 1:
			printf("Enter a binary number:\n");
			scanf("%d", &binaryNum);
			while(binaryNum>0)
			{
				reminder = binaryNum % 10;

        			decimal_val = decimal_val + reminder * base;

        			binaryNum = binaryNum / 10 ;

        			base = base * 2;
			}
			printf("The decimal value is:%d\n",decimal_val);
			break;

		case 2: 
			printf("Enter a decimal number:\n");
			scanf("%d",&decimalNum);
			while(decimalNum>0)
			{
				binary[i] = decimalNum % 2;
				decimalNum = decimalNum/ 2;
				i++;	
			}
			for(j=0; j<i; j++)
			{
				printf("%d,", binary[j]);
			}	
			printf("\n");
			break;
	}

}

/* two pointers- read and write.*/
char* Squeeze(char* string1, char* string2)
{
	int length;
	int i, j;

	length = StringLength(string1);
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length-1; j++)
		{		
			if (string1[i] != string1[j])
			{
				string2[i] = string1[i];
			}
		}
	}
	strcpy(string1, string2);
	return string1;
}





int main()
{
	char string[20];
	int length = 0;
	char string1[] = "ABCDEF";	
	char string2[] = "BKE";
	char* result;
	printf("Enter your string:\n");
	scanf("%20[^\n]s", string);	
	
	length = StringLength(string);

	printf("Reversed string: ");
	PrintReverseString(string, length);
	
	printToken(string);
	BinaryOrDecimal();
	/*result = Squeeze(string1, string2);
	printf("%s\n", result);*/
	
	
return 0;
}
