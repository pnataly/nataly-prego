#include <stdio.h>
#include <stdlib.h>
#include "genericVector.h"
#include "vectorTests.h"

void IntDestroy(void* _item);

TEST_RESULT CreateTest1()
{
	Vector* newVector;
	newVector = VectorCreate(0,0);
	if(newVector == NULL)
	{
		return PASSED;
	}
	free(newVector);
	return FAILED;
}

TEST_RESULT CreateTest2()
{
	Vector* newVector;
	newVector = VectorCreate(10000000000000, 100);
	if(newVector == NULL)
	{
		return PASSED;
	}
	free(newVector);
	return FAILED;
}

TEST_RESULT CreateTest3()
{
	Vector* newVector;
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		free(newVector);
		return PASSED;
	}
	return FAILED;
}


TEST_RESULT DestroyTest1()
{
	Vector* newVector;
	newVector = VectorCreate(10,10);
	VectorDestroy(&newVector, IntDestroy);
	VectorDestroy(&newVector, IntDestroy);
	VectorDestroy(&newVector, IntDestroy);
	return PASSED;
}

TEST_RESULT VectorSizeTest1()
{
	Vector* newVector;
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Size(newVector) == 0)
		{
			VectorDestroy(&newVector, IntDestroy);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT VectorSizeTest2()
{
	Vector* newVector;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS && Vector_Size(newVector) == 1)
		{
			VectorDestroy(&newVector, NULL);
			return PASSED;
		}
	}
	VectorDestroy(&newVector, IntDestroy);
	return FAILED;
}

TEST_RESULT VectorCapacityTest1()
{
	Vector* newVector;
	newVector = VectorCreate(10,0);
	if(newVector != NULL)
	{
		if(Vector_Capacity(newVector) == 10)
		{
			VectorDestroy(&newVector, IntDestroy);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT VectorCapacityTest2()
{
	Vector* newVector;
	newVector = VectorCreate(0,10);
	if(newVector != NULL)
	{
		if(Vector_Capacity(newVector) == 0)
		{
			VectorDestroy(&newVector, IntDestroy);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT AddTest1()
{
	Vector* newVector;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			VectorDestroy(&newVector, NULL);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT AddTest2()
{
	int array[2] = {1,2};
	Vector* newVector = NULL;
	if(Vector_Append(newVector, &array[0]) == VECTOR_UNITIALIZED_ERROR)
	{
		VectorDestroy(&newVector, NULL);
		return PASSED;
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT AddTest3()
{
	int array[2] = {1,2};
	Vector* newVector;
	newVector = VectorCreate(1,0);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Append(newVector, &array[0]) == VECTOR_OVERFLOW_ERROR)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT AddTest4()
{
	Vector* newVector;
	newVector = VectorCreate(1,0);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, NULL) == VECTOR_WRONG_DATA)
		{
			VectorDestroy(&newVector, NULL);
			return PASSED;
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT RemoveTest1()
{
	Vector* newVector;
	void* Pvalue;
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Remove(newVector, &Pvalue) == VECTOR_UNDERFLOW_ERROR)
		{
			VectorDestroy(&newVector, NULL);
			return PASSED;
		}
	}
	return FAILED;
}

TEST_RESULT RemoveTest2()
{
	void* Pvalue;
	Vector* newVector = NULL;
	if(Vector_Remove(newVector, &Pvalue) == VECTOR_UNITIALIZED_ERROR)
	{
		return PASSED;
	}
	return FAILED;
}

TEST_RESULT RemoveTest3()
{
	Vector* newVector;
	void* Pvalue = NULL;
	newVector = VectorCreate(1,0);
	if(newVector != NULL)
	{
		if(Vector_Remove(newVector, NULL) == VECTOR_WRONG_DATA)
		{
			VectorDestroy(&newVector, NULL);
			return PASSED;
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT RemoveTest4()
{
	Vector* newVector;
	void* Pvalue;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Remove(newVector, &Pvalue) == VECTOR_SUCCESS)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT GetTest1()
{
	Vector* newVector;
	void* Pvalue;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Get(newVector, 5, &Pvalue) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT GetTest2()
{
	Vector* newVector;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Get(newVector, 0, NULL) == VECTOR_WRONG_DATA)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT GetTest3()
{
	Vector* newVector;
	void* Pvalue;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Get(NULL, 0, &Pvalue) == VECTOR_UNITIALIZED_ERROR)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT GetTest4()
{
	Vector* newVector;
	void* Pvalue;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Get(newVector, 0, &Pvalue) == VECTOR_SUCCESS && Pvalue == &array[0])
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT SetTest1()
{
	Vector* newVector;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Set(newVector, 5, &array[1]) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT SetTest2()
{
	Vector* newVector;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Set(newVector, 0, NULL) == VECTOR_WRONG_DATA)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT SetTest3()
{
	Vector* newVector;
	void* Pvalue;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Set(NULL, 0, &Pvalue) == VECTOR_UNITIALIZED_ERROR)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

TEST_RESULT SetTest4()
{
	Vector* newVector;
	void* Pvalue;
	int array[2] = {1,2};
	newVector = VectorCreate(10,10);
	if(newVector != NULL)
	{
		if(Vector_Append(newVector, &array[0]) == VECTOR_SUCCESS)
		{
			if(Vector_Set(newVector, 0, &array[1]) == VECTOR_SUCCESS)
			{
				VectorDestroy(&newVector, NULL);
				return PASSED;
			}
		}
	}
	VectorDestroy(&newVector, NULL);
	return FAILED;
}

void PrintResult(int _result, char _string[])
{

	printf("The result of %s:\t%s\n", _string, (_result == PASSED) ?"PASSED":"FAILED");
}

