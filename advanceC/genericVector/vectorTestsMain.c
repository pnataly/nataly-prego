#include <stdio.h>
#include <stdlib.h>
#include "vectorTests.h"

void IntDestroy(void* _item)
{
	if(_item != NULL)
	{
		free(_item);
	}
}

int main()
{
	PrintResult(CreateTest1(), "CreateTest1");
	
	PrintResult(CreateTest2(), "CreateTest2");

	PrintResult(CreateTest3(), "CreateTest3");

	PrintResult(DestroyTest1(), "DestroyTest1");

	PrintResult(VectorSizeTest1(), "VectorSizeTest1");

	PrintResult(VectorSizeTest2(), "VectorSizeTest2");

	PrintResult(VectorCapacityTest1(), "VectorCapacityTest1");

	PrintResult(VectorCapacityTest2(), "VectorCapacityTest2");

	PrintResult(AddTest1(), "AddTest1");

	PrintResult(AddTest2(), "AddTest2");

	PrintResult(AddTest3(), "AddTest3");

	PrintResult(AddTest4(), "AddTest4");

	PrintResult(RemoveTest1(), "RemoveTest1");

	PrintResult(RemoveTest2(), "RemoveTest2"); 

	PrintResult(RemoveTest3(), "RemoveTest3"); 

	PrintResult(RemoveTest4(), "RemoveTest4"); 

	PrintResult(GetTest1(), "GetTest1"); 

	PrintResult(GetTest2(), "GetTest2"); 

	PrintResult(GetTest3(), "GetTest3"); 

	PrintResult(GetTest4(), "GetTest4"); 

	PrintResult(SetTest1(), "SetTest1"); 

	PrintResult(SetTest2(), "SetTest2"); 

	PrintResult(SetTest3(), "SetTest3"); 

	PrintResult(SetTest4(), "SetTest4"); 

	return 0;
}
