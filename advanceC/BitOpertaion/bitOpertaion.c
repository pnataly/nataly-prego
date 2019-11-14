#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

void swap1(int* _a, int* _b)
{
	*_a = *_a * *_b;
	*_b = *_a / *_b;
	*_a = *_a / *_b;
}

void swap2(int* _a, int* _b)
{
	*_a = *_a + *_b;
	*_b = *_a - *_b;
	*_a = *_a - *_b;
}

void swap3(int* _a, int* _b)
{
	*_a = *_a ^ *_b;
	*_b = *_a ^ *_b;
	*_a = *_a ^ *_b;
}

void intSign(int x)
{
	printf("%d\n", x>>31);
}

int absValue1(int x)
{
	int y;
	y = x>>31;
	return (x^y)-y;
}

int isTwoPower(int x)
{
	return !(x&(x-1));
}

int Add(int x, int y)
{
	int c;
	while(y != 0)
	{
		c = x&y;
		x = x^y;
		y = c<<1;
	}
	return x;
}

void DecimalToBinary(unsigned int _decimal, char* _binary)
{
	int index = 0;
	int i =0;
	for(i=0; i<8; i++)
	{
		_binary[i]=0;
	}

	while(_decimal > 0)
	{
		_binary[index] = _decimal%2;
		_decimal = _decimal/2;
		index++;
	}
	
	for(i = 7; i>=0; i--)
	{
		printf("%d", _binary[i]);
	}
	printf("\n");
	return;
}

unsigned int countBits(unsigned int x)
{
	int count;
	while(x != 0)
	{
 		count += x & 1; 
    	x = x>>1; 
	}
	return count;
}

unsigned int invertBits(unsigned int n, unsigned int start, unsigned int end) 
{ 
	int num;
    num = ((1 << end)-1)^((1<<(start-1))-1); 
   return (n ^ num); 
} 

int replaceBit(int n, int k) 
{ 
    return (n ^ (1 << (k))); 
} 

unsigned int MirrorBits(unsigned int _v)
{
	int i;
	unsigned int r=0;
	for(i=0; i<sizeof(int); ++i)
	{
		r<<=1;
		r |= (_v&1);
		_v >>=1;
	}
	return r;
}


int rightRotateCyclic(int _num, unsigned int N) 
{ 
 	int size;
    int result;
 	size = sizeof(int) * 8;
    N = N % size;
    result = _num >> N | _num << (size - N);
    return result;
} 

int leftRotateCyclic(int _num, unsigned int N)
{
 	int size;
    int result;
 	size = sizeof(int) * 8;
    N = N % size;
   
    result = _num << N | _num >> (size - N);
    return result;
} 

int main()
{
	int x = -2;
	int y =9;
	char binary [256];
	intSign(x);
	intSign(y);
	printf("The absolute value: %d\n", absValue1(x));
	DecimalToBinary(y, binary);
	isTwoPower(12) ? printf("is power of two\n") : printf("not powert of two\n");
	printf("The result: %d\n", Add(5,2));
	printf("The number of ones: %d\n", countBits(7));

	DecimalToBinary(invertBits(6, 0, 32), binary);
	DecimalToBinary(replaceBit(15, 0), binary);
	DecimalToBinary(170, binary);
	DecimalToBinary(rightRotateCyclic(170, 4), binary);
	DecimalToBinary(leftRotateCyclic(170, 4), binary);
	DecimalToBinary(MirrorBits(170), binary);

	printf("Before swap 1: x: %d, y: %d\n", x,y);
	swap1(&x, &y);
	printf("After swap 1: x: %d, y: %d\n", x,y);
	printf("\n");

	printf("Before swap 2: x: %d, y: %d\n", x,y);
	swap2(&x, &y);
	printf("After swap 2: x: %d, y: %d\n", x,y);
	printf("\n");

	printf("Before swap 3: x: %d, y: %d\n", x,y);
	swap3(&x, &y);
	printf("After swap 3: x: %d, y: %d\n", x,y);


}
