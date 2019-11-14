#include <stdio.h>
#include <string.h>

int main()
{
	FILE* fp;
	int nByte;
	int _age, result;
	char name[128];
	printf("Enter your name:\n");
	printf("Enter your age:\n");
	scanf("%s%d", name, &_age);

	if((fp = fopen("files.c", "w")) == NULL)
	{
		printf("Cannot open the file.\n");
		return 0;
	}
	
	nByte=fwrite(&_age, 1, sizeof(int),fp);
	if(nByte != sizeof(int))
	{
		printf("Error\n");
		return 0;
	}
	nByte = fwrite(name, 1, strlen(name),fp);
	if(nByte != strlen(name))
	{
		printf("Error\n");
		return 0;
	}
	result = fclose(fp);
	if(result != 0)
	{
		printf("Cannot close the file.\n");
		return 0;
	}
	
	fp=fopen("files.c", "r");
	if(fp==NULL)
	{
		printf("Cannot open the file.\n");
		return 0;
	}
	
	nByte = fread(&_age,1, sizeof(int),fp);
	if(nByte != sizeof(int))
	{
		printf("Error\n");
		return 0;
	}
	nByte = fread(name, 1, strlen(name),fp);
	if(nByte != strlen(name))
	{
		printf("Error\n");
		return 0;
	}
	printf("Name: %s Age: %d\n", name, _age);
	fp=fopen("files.c", "r");
	if(fp==NULL)
	{
		printf("Cannot open the file.\n");
		return 0;
	}
	return 0;
}
