#include <stdio.h>
#include <time.h>
#include "sort.h"
#include "sortTest.h"
#include "ADTErr.h"



TEST_RESULT BubbleTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(BubbleSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT BubbleTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(BubbleSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT BubbleTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(BubbleSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}


TEST_RESULT ShakeTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(ShakeSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT ShakeTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(ShakeSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT ShakeTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(ShakeSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT QuickTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(QuickSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT QuickTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(QuickSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT QuickTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(QuickSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT InsertionTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(InsertionSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT InsertionTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(InsertionSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT InsertionTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(InsertionSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}


TEST_RESULT ShellTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(ShellSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT ShellTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(ShellSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT ShellTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(ShellSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT SelctionTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(SelctionSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT SelctionTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(SelctionSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT SelctionTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%60)+1;
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(SelctionSort(newVector) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT CountingTest1()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(1000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=1000; i++)
		{
			data = (rand()%100);
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(CountingSort(newVector, 100) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 1000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT CountingTest2()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(10000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=10000; i++)
		{
			data = (rand()%1000);
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(CountingSort(newVector, 100) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 10000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

TEST_RESULT CountingTest3()
{
	time_t begin, end;
	double second;
	int result, data, i;
	Vector* newVector;
	newVector = VectorCreate(50000,0);
	if(newVector != NULL)
	{
		for(i=1; i<=50000; i++)
		{
			data = (rand()%100);
			result = VectorAdd(newVector, data);
			if(result != ERR_OK)
			{
				break;
			}
		}
		begin = time(NULL);
		if(CountingSort(newVector, 100) == ERR_OK)
		{
			VectorDestroy(newVector);
			end = time(NULL);
			second = (double)end - begin;
			printf("Time for 50000: %f\n", second);
			return PASSED;
		}
		
	}
	return FAILED;
}

void PrintResult(int _result, char _string[])
{

	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
	printf("\n");
}
