#include <stdio.h>
#include <stdlib.h>
#include "hashTest.h"


int main()
{

	PrintResult(CreateTest1(), "CreateTest1");

	PrintResult(CreateTest2(), "CreateTest2");

	PrintResult(CreateTest3(), "CreateTest3");

	PrintResult(DestroyTest1(), "DestroyTest1");

	PrintResult(InsertTest1(), "InsertTest1");

	PrintResult(InsertTest2(), "InsertTest2");

	PrintResult(InsertTest3(), "InsertTest3");

	PrintResult(IsDataFound1(), "IsDataFound1");

return 0;
}
