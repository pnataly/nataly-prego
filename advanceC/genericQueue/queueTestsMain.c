#include <stdio.h>
#include <stdlib.h>
#include "queueTests.h"



int main()
{

	PrintResult(CreateTest1(), "CreateTest1");

	PrintResult(CreateTest2(), "CreateTest2"); 

	PrintResult(CreateTest3(), "CreateTest3"); 

	PrintResult(DestroyTest1(), "DestroyTest1"); 

	PrintResult(DestroyTest2(), "DestroyTest2"); 

	PrintResult(IsEmptyTest1(), "IsEmptyTest1");

	PrintResult(IsEmptyTest2(), "IsEmptyTest2"); 

	PrintResult(InsertTest1(), "InsertTest1"); 

	PrintResult(InsertTest2(), "InsertTest2"); 

	PrintResult(InsertTest3(), "InsertTest3"); 

	PrintResult(InsertTest4(), "InsertTest4"); 

	PrintResult(RemoveTest1(), "RemoveTest1"); 

	PrintResult(RemoveTest2(), "RemoveTest2"); 

	PrintResult(RemoveTest3(), "RemoveTest3"); 


	 

return 0;
}
