#include <stdio.h>
#include "files.h"

int main()
{
	char _name1[]= {"100west.txt"};

	printf("\n");
	ReadNLines(_name1,5);
	printf("\n");

	CountLetters(_name1);
	

return 0;
}
