#include <stdio.h>
#include <stdlib.h>  

#define ASSERT(exp) ((exp) != 0) ? 0 : (printf("%s %s %d\n", #exp , __FILE__ , __LINE__) , abort(),1)

int main()
{
	int x =4;
	int y = 2;
	ASSERT(x<y);
	return 0;
}
