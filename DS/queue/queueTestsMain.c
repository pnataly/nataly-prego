#include <stdio.h>
#include <stdlib.h>
#include "queueTests.h"



int main()
{

	PrintResult(CreateLimTest1(), "CreateLimTest1");

	PrintResult(CreateLimTest2(), "CreateLimTest2"); 

	PrintResult(CreateLimTest3(), "CreateLimTest3"); 

	PrintResult(InsertPosTest3(), "InsertPosTest3"); 

	PrintResult(InsertNegTest4(), "InsertNegTest4"); 

	PrintResult(InsertNegTest5(), "InsertNegTest5"); 

	PrintResult(RemovePosTest6(), "RemovePosTest6"); 

	PrintResult(RemoveNegTest7(), "RemoveNegTest7"); 

	PrintResult(IsEmptyPosTest8(), "IsEmptyPosTest8"); 

	PrintResult(IsEmptyNegTest9(), "IsEmptyNegTest9"); 

return 0;
}
