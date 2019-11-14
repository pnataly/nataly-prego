#include <stdio.h>
#include "vectorTests.h"

int main()
{
	PrintResult(CreateTest1(), "CreateTest1");
	
	PrintResult(CreateTest2(), "CreateTest2");

	PrintResult(CreateTest3(), "CreateTest3");

	PrintResult(AddTest1(), "AddTest1");

	PrintResult(AddTest2(), "AddTest2");

	PrintResult(AddTest3(), "AddTest3");

	PrintResult(RemoveTest1(), "RemoveTest1");

	PrintResult(RemoveTest2(), "RemoveTest2");

	return 0;
}
