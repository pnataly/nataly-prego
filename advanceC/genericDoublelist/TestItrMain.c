#include <stdio.h>
#include <stdlib.h>
#include "list_itr.h"
#include "TestItr.h"

int main()
{

	PrintResult(CreateTest1(), "CreateTest1");
 
	PrintResult(DestroyTest1(), "DestroyTest1");

	PrintResult(BeginTest1(), "BeginTest1");

	PrintResult(BeginTest2(), "BeginTest2");

	PrintResult(EndTest1(), "EndTest1");

	PrintResult(EndTest2(), "EndTest2");

	PrintResult(EqualTest1(), "EqualTest1");

	PrintResult(EqualTest2(), "EqualTest2");

	PrintResult(NextTest1(), "NextTest1");

	PrintResult(NextTest2(), "NextTest2");

	PrintResult(PrevTest1(), "PrevTest1");

	PrintResult(PrevTest2(), "PrevTest2");

	PrintResult(GetTest1(), "GetTest1");

	PrintResult(GetTest2(), "GetTest2");

	PrintResult(SetTest1(), "SetTest1");

	PrintResult(SetTest2(), "SetTest2");

	PrintResult(SetTest3(), "SetTest3");

	PrintResult(InsertTest1(), "InsertTest1");

	PrintResult(InsertTest2(), "InsertTest2");

	PrintResult(InsertTest3(), "InsertTest3");

	PrintResult(InsertTest4(), "InsertTest4");

	PrintResult(RemoveTest1(), "RemoveTest1");

	PrintResult(RemoveTest2(), "RemoveTest2");

	PrintResult(RemoveTest3(), "RemoveTest3");

	return 0;
}
