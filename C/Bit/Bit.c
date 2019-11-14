#include <stdio.h>
#include <stdlib.h>
#include "Bit.h"



struct BitMap
{
	size_t _NumOfFeatures;
	 unsigned char* _array;
};



BitMap* CreateBitMap(size_t _NumOfFeatures)
{
	int _arraySize;
	BitMap* _bitMap;

	_bitMap = (BitMap*) malloc(sizeof(BitMap));
	if(_bitMap == NULL)
	{
		return NULL;
	}
	
	if(_NumOfFeatures % 8 == 0)
	{
		_arraySize = _NumOfFeatures/8;
	}
	else
	{
		_arraySize = (_NumOfFeatures/8)+1;
	}
	
	_bitMap->_array = (unsigned char*) calloc(sizeof(unsigned char),_arraySize);
	if(_bitMap->_array == NULL)
	{
		free(_bitMap);
		return NULL;
	}

	_bitMap->_NumOfFeatures = _NumOfFeatures;
	return _bitMap;

}

void DestroyBitMap(BitMap* _bitMap)
{
	if(_bitMap == NULL)
	{
		return;
	}

	free(_bitMap->_array);
	free(_bitMap);	

}

int BitOn(BitMap* _bitMap, size_t _bitNum)
{
	unsigned char ch=1;
	unsigned int arrIndex = _bitNum/8;
	unsigned int bitIndex = _bitNum%8;

	if(NULL == _bitMap || _bitNum > _bitMap->_NumOfFeatures)
	{
		return 0;	
	}
	
	ch<<= bitIndex;
	_bitMap->_array[arrIndex] |= ch;

	return 1;
	
}


int BitOff(BitMap* _bitMap, size_t _bitNum)
{
	unsigned char ch=0;
	unsigned int arrIndex = _bitNum/8;
	unsigned int bitIndex = _bitNum%8;

	if(NULL == _bitMap || _bitNum > _bitMap->_NumOfFeatures)
	{
		return 0;	
	}
	
	ch<<= bitIndex;
	_bitMap->_array[arrIndex] &= ch;

	return 1;
	
}


void DecimalToBinary(int _decimal, char* _binary)
{
	int index = 0;
	int i =0;
	for(i=0; i<8; i++)
	{
		_binary[i]=0;
	}

	printf("The number in Decimal: %d\n", _decimal);

	while(_decimal > 0)
	{
		_binary[index] = _decimal%2;
		_decimal = _decimal/2;
		index++;
	}
	
	printf("The number in Binary:");
	for(i = 7; i>=0; i--)
	{
		printf("%d", _binary[i]);
	}
	printf("\n");
	return;
}


