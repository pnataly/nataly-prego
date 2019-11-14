#include <iostream>
#include <string.h> //memcpy
#include "memManager_t.h"
#include "memPage_t.h"
using namespace std;

#define CAPACITY 6
size_t memPage_t:: s_defCapacity = CAPACITY;


size_t memPage_t:: Write(const void* _data, size_t _bytes, size_t _pos)
{
	if(IsFull() || _pos > GetActualSize() || !_data)
	{
		return 0;
	}
	size_t freeSpace = GetCapacity()-_pos;
	size_t nBytes = freeSpace<_bytes ? freeSpace : _bytes;
	memcpy(m_buffer+_pos, _data, nBytes);
	if(_pos+nBytes > GetActualSize())
	{
		SetActualSize(_pos+nBytes);	
	}
	SetPosition(GetActualSize());
	return nBytes;
}

size_t memPage_t:: Read(void* _data, size_t _pos, size_t _bytes)
{
	size_t space = GetActualSize()-_pos;
	size_t nBytes = space < _bytes ? space : _bytes;
	
	if (_pos > GetActualSize() || IsEmpty() || !_data)
	{
		return 0;
	}
	memcpy(_data, m_buffer+_pos, nBytes);
	SetPosition(_pos+nBytes);
	return nBytes;
}

