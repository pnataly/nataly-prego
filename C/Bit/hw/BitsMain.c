#include <stdio.h>
#include <stdlib.h>
#include "Bits.h"


int main()
{
	
	unsigned char _binary[9];
	int _num;
	int _numShift;
	int result;
	unsigned char c;
	unsigned char ch;
	printf("Enter a number:\n");
	scanf("%d", &_num);
	printf("The number in binary is:");
	DecimalToBinary(_num, _binary);
	c = _num;
	ch=BitInvert(c);
	printf("After invert the number in binary is:");
	DecimalToBinary(ch, _binary);

	printf("Enter a number to shift:\n");
	scanf("%d", &_numShift);
	result=rightRotateCyclic(_num,_numShift);
	printf("After invert rotate the binary is:");
	DecimalToBinary(result, _binary);
	printf("\n");

	
	result=setbits(170, 6, 3, 167);
	DecimalToBinary(result, _binary);
	return 0;
}
