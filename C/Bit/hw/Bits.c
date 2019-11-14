#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void DecimalToBinary(unsigned char _decimal, unsigned char* _binary)
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

unsigned char BitInvert(unsigned char _num)
{
	unsigned char Z = 255;
	unsigned char C=0;
	C = _num ^ Z;
	
	return C;
}

int rightRotateCyclic(int _num, unsigned int N) 
{ 
   return (N >> _num)|(_num << (8 - N)); 
} 

unsigned int setbits(unsigned int x, int p, int n,unsigned int y)
{
	unsigned int ybits;
	unsigned int helper;
	unsigned int result;
	ybits = y & ~(~0 << n);
	helper = ~(~0 << n);
	result = (x | (helper << (p+1-n))) & ((ybits << (p+1-n)) | (~(helper << (p+1-n))));
    return result;
}




