#ifndef __MEMPOOL_T_H__
#define __MEMPOOL_T_H__

#include "memManager_t.h"
#include "memPage_t.h"
#include <iostream>
#include <vector>
using namespace std;

class memPool_t : public memManager_t 
{
	public:
		memPool_t()			//default CTOR.
		{
			memPage_t* page = new memPage_t;	
			m_vec.push_back(page);
		}
		virtual ~memPool_t()		//DTOR. 
		{
			unsigned int i = 0;
			for( ; i>m_vec.size(); i++)
			{
				delete[]m_vec[i];
			}
		}
		
		virtual size_t Read(void* _data, size_t _bytes) {return Read(_data, GetPosition(), _bytes);}
		virtual size_t Read(void* _data, size_t _pos, size_t _bytes);
		virtual size_t Write(const void* _data, size_t _bytes) {return Write(_data, _bytes, GetPosition());}
		virtual size_t Write(const void* _data, size_t _bytes, size_t _pos);
		
	private:
		memPool_t(const memPool_t& _mpl);		//copy CTOR.
		memPool_t& operator=(const memPool_t& _mpl);	
		std::vector<memPage_t*>m_vec;
};

#endif /*__MEMPOOL_T_H__*/ 
