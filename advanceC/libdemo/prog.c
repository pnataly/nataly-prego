#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
	char result;
	void* handle;
    void (*func)(void);
	printf("Hello- which library you want: A or B?\n");	
	scanf("%c", &result);

	if(result =='A')
	{
		handle = dlopen("libdemoA.so", RTLD_LAZY);
		if(!handle)
		{
			printf("Error\n");
			return 0;
		}
		*(void**)(&func) = dlsym(handle, "funcA");
		func();
		dlclose(handle);
	}

	else if(result == 'B')
	{
		handle = dlopen("libdemoB.so", RTLD_LAZY);
		if(!handle)
		{
			printf("Error\n");
			return 0;
		}
		*(void**)(&func) = dlsym(handle, "funcB");
		func();
		dlclose(handle);
	}
	return 0;
}
