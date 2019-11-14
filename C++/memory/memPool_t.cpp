#include "memManager_t.h"
#include "memPage_t.h"
#include "memPool_t.h"
#include <vector>
#include <string.h> //memcpy
using namespace std;


size_t memPool_t:: Read(void* _data, size_t _pos, size_t _bytes)
{
	size_t result = 1;
	size_t readCount = 0;
	int i = 0;
	size_t size = GetActualSize();
	
	if(!_data || _pos > size)
	{
		return 0;
	}
	
	while(1)
	{
		if (_pos < m_vec[i]->GetCapacity())
		{
			while (result)
			{
				result = m_vec[i]->Read(_data, _pos, _bytes);
				readCount += result;
				if (result != _bytes)
				{
					result = _bytes - result;
					i++;
				}
				result = 0;
			}
			
			SetPosition(_pos+_bytes);
			break;
		} 
		_pos -= m_vec[i]->GetCapacity();
		i++;
	}
	return readCount;
}


size_t memPool_t:: Write(const void* _data, size_t _bytes, size_t _pos)
{
	size_t result = 1;
	int i = 0;
	size_t size = GetActualSize();
	
	if(!_data || _pos > size)
	{
		return 0;
	}
	
	while(1)
	{
		if (_pos < m_vec[i]->GetCapacity())
		{
			while (result) //_bytes
			{
				result = m_vec[i]->Write(_data, _bytes, _pos);
				if (result != _bytes)
				{
					result = _bytes - result;
					memPage_t* page = new memPage_t;	
					m_vec.push_back(page);
					i++;
				}
				result = 0;
			}
			
			if(_pos+_bytes > size)
			{
				SetActualSize(_pos+_bytes);	
			}
			SetPosition(_pos+_bytes);
			break;
		} 
		_pos -= m_vec[i]->GetCapacity();
		i++;
	}
	return _bytes;
}

