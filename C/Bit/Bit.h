#ifndef _BIT_H
#define _BIT_H

typedef struct BitMap BitMap;

typedef int(*BitFunction)(unsigned char*, size_t);

BitMap* CreateBitMap(size_t _NumOfFeatures);

void DestroyBitMap(BitMap* _bitMap);

int BitOn(BitMap* _bitMap, size_t _bitNum);

void DecimalToBinary(int _decimal, char* _binary);

#endif /*_STRINGS_H*/ 
