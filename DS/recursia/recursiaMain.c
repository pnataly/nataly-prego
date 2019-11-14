#include <stdio.h>
#include "recursia.h"


int main()
{
	int result;
	int n;
	char disk1, disk2. disk3;
	int _array[3] = {8,9,10};
	char str1[6] = {"Hello"};
	char str2[6] = {"bacab"};
	ReverseString(str1,0);
	printf("%s\n", str1);

	result = IsPolindrom(str2);
	if(result == 1)
	{
		printf("The string is a palindrom\n");
	}
	else
	{
		printf("The string isn't a palindrom\n");
	}

	printf("%.2f\n", average(_array, 0, 3));
	
	printf("Enter the numbers of disks:\n");
	scanf("%d", &n);
	Hanoi(n,);

return 0;
}
