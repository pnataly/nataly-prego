#include <stdio.h>


int factorial(int _n)
{
	if(_n <= 1)
	{
		return 1;
	}

	return factorial(_n-1)*_n;
}

int power(int _n, int _k)
{
	if(_k <= 0)
	{
		return 1;
	}
	return power(_n,_k-1)*_n;
}

int sumArray(int _array[], int n)
{

	if(n <= 0)
	{
		return 0;
	}	
	return sumArray(_array, n-1)+_array[n-1];
}

int bigNum(int _array[], int n)
{
	int max;

	if(n == 1)
	{
		return _array[0];
	}
	max = bigNum(_array, n-1);
	if(max > _array[n-1])
	{
		return max;
	}
		
	return _array[n-1];
}

int average(int _array[], int n)
{
	if(n <= 0)
	{
		return 0;
	}
	return (_array[n-1]/n) + average(_array, n-1);
}

int fibonaciRec(int n)
{
	
	if(n<=0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}

	return fibonaciRec(n-1)+fibonaciRec(n-2);
}

int fibonaci(int n)
{
	int i;
	int temp;
	int num1 = 0;
	int num2 = 1;
	for(i=2; i<=n; i++)
	{
		temp = num1+num2;
		num1 = num2;
		num2 = temp;
		
	}

	return num2;
}

int main()
{
	int _array[5] = {1,2,3,4,5};

	printf("%d\n" ,factorial(4));

	printf("%d\n" ,power(2,3));

	printf("%d\n" ,sumArray(_array,5));
	
	printf("%d\n" ,bigNum(_array,5));

	printf("%d\n" ,average(_array,5));

	printf("%d\n" ,fibonaciRec(10));

	printf("%d\n" ,fibonaciRec(20));

	printf("%d\n" ,fibonaciRec(40));

	printf("%d\n" ,fibonaci(10));

	printf("%d\n" ,fibonaci(20));

	printf("%d\n" ,fibonaci(40));


return 0;
}
