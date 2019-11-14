#include <stdio.h>
#include "executorTest.h"


int func1()
{
	static int count = 2;
	if(count>0)
	{
		printf("Hello Executor!\n");
		count--;
		return 1;
	}
	count = 2;
	return 0;
}

int func2()
{
	static int count = 4;
	if(count>0)
	{
		printf("Bye Executor!\n");
		count--;
		return 1;
	}
	count = 4;
	return 0;
}

int func3(void* _context) /*pause func */
{
	Pause(_context);
	return 0;
}

TEST_RESULT CreateTest1() /* create executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	ExecutorDestroy(&exe);
	return PASSED;
}

TEST_RESULT CreateTest2() /* create executor with size 0 */
{
	Executor* exe;
	exe = ExecutorCreate(0,0);
	if(exe == NULL)
	{
		return PASSED;
	}
	return FAILED;
}


TEST_RESULT DestroyTest1() /* destroy executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe != NULL)
	{
		ExecutorDestroy(&exe);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT DestroyTest2() /* double destroy */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe != NULL)
	{
		ExecutorDestroy(&exe);
		ExecutorDestroy(&exe);
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT AddTest1() /* add to NULL executor */
{
	Executor* exe = NULL;

	if(AddTask(exe, func1, 5 ,NULL) == EXECUTOR_UNINITIALIZED_ERROR)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT AddTest2() /* add NULL func to executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, NULL, 5 ,NULL) == EXECUTOR_INPUT_NULL)
	{
		ExecutorDestroy(&exe);
		return PASSED;	
	}
	ExecutorDestroy(&exe);
	return FAILED;
}

TEST_RESULT AddTest3() /* add to executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, func1, 5 ,NULL) == EXECUTOR_SUCCESS)
	{
		ExecutorDestroy(&exe);
		return PASSED;	
	}
	ExecutorDestroy(&exe);
	return FAILED;
}

TEST_RESULT AddTest4() /* add to executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, func1, 5 ,NULL) == EXECUTOR_SUCCESS)
	{
		if(AddTask(exe, func2, 3 ,NULL) == EXECUTOR_SUCCESS)
		{
			ExecutorDestroy(&exe);
			return PASSED;		
		}
	}
	ExecutorDestroy(&exe);
	return FAILED;
}

TEST_RESULT RunTest1() /* run NULL executor */
{
	Executor* exe = NULL;

	if(ExecutorRun(exe) == EXECUTOR_UNINITIALIZED_ERROR)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT RunTest2() /* run executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, func1, 200 ,NULL) == EXECUTOR_SUCCESS)
	{
		if(AddTask(exe, func2, 150 ,NULL) == EXECUTOR_SUCCESS)
		{
			if(ExecutorRun(exe) == EXECUTOR_SUCCESS)
			{
				ExecutorDestroy(&exe);
				return PASSED;	
			}
		}
	}
	ExecutorDestroy(&exe);
	return FAILED;
}

TEST_RESULT RunTest3() /* check the run executor not pause */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, func1, 500 ,NULL) == EXECUTOR_SUCCESS)
	{
		if(ExecutorRun(exe) == EXECUTOR_PAUSE)
		{
			ExecutorDestroy(&exe);
			return FAILED;	
		}
	}
	ExecutorDestroy(&exe);
	return PASSED;
}

TEST_RESULT RunTest4() /* run pause task */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, func3, 1 ,exe) == EXECUTOR_SUCCESS)
	{
		if(ExecutorRun(exe) == EXECUTOR_PAUSE)
		{
			ExecutorDestroy(&exe);
			return PASSED;	
		}
	}
	ExecutorDestroy(&exe);
	return FAILED;
}

TEST_RESULT PauseTest1() /*pause NULL executor */
{
	Executor* exe = NULL;
	if(ExecutorPause(exe) == EXECUTOR_UNINITIALIZED_ERROR)
	{
		return PASSED;	
	}
	return FAILED;
}

TEST_RESULT PauseTest2() /* pause executor */
{
	Executor* exe;
	exe = ExecutorCreate(5,0);
	if(exe == NULL)
	{
		return FAILED;
	}
	if(AddTask(exe, func3, 1 ,exe) == EXECUTOR_SUCCESS)
	{
		if(ExecutorPause(exe) == EXECUTOR_PAUSE)
		{
			ExecutorDestroy(&exe);
			return PASSED;	
		}
	}
	ExecutorDestroy(&exe);
	return FAILED;
}


void PrintResult(int _result, char _string[])
{
	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
	printf("\n");
}

int main()
{
	PrintResult(CreateTest1(), "CreateTest1");

	PrintResult(CreateTest2(), "CreateTest2");

	PrintResult(DestroyTest1(), "DestroyTest1");

	PrintResult(DestroyTest2(), "DestroyTest2");

	PrintResult(AddTest1(), "AddTest1");

	PrintResult(AddTest2(), "AddTest2");

	PrintResult(AddTest3(), "AddTest3");

	PrintResult(AddTest4(), "AddTest4");

	PrintResult(RunTest1(), "RunTest1");

	PrintResult(RunTest2(), "RunTest2");

	PrintResult(RunTest3(), "RunTest3");

	PrintResult(RunTest4(), "RunTest4");

	PrintResult(PauseTest1(), "PauseTest1");

	PrintResult(PauseTest2(), "PauseTest2");

	return 0;
}
