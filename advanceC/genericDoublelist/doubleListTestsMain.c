#include <stdio.h>
#include <stdlib.h>
#include "doubleListTests.h"



int main()
{

	PrintResult(CreateTest1(), "CreateTest1");
 
	PrintResult(DestroyTest1(), "DestroyTest1");

	PrintResult(DestroyTest2(), "DestroyTest2");

	PrintResult(PushHeadTest1(), "PushHeadTest1");

	PrintResult(PushHeadTest2(), "PushHeadTest2");

	PrintResult(PushHeadTest3(), "PushHeadTest3");

	PrintResult(PushTailTest1(), "PushTailTest1");

	PrintResult(PushTailTest2(), "PushTailTest2");

	PrintResult(PushTailTest3(), "PushTailTest3");

	PrintResult(PopHeadTest1(), "PopHeadTest1");

	PrintResult(PopHeadTest2(), "PopHeadTest2");

	PrintResult(PopHeadTest3(), "PopHeadTest3");

	PrintResult(PopHeadTest4(), "PopHeadTest4"); 

	PrintResult(PopTailTest1(), "PopTailTest1");

	PrintResult(PopTailTest2(), "PopTailTest2");

	PrintResult(PopTailTest3(), "PopTailTest3");

	PrintResult(PopTailTest4(), "PopTailTest4");  

	PrintResult(ListSizeTest1(), "ListSizeTest1");

	PrintResult(ListSizeTest2(), "ListSizeTest2");


return 0;
}
