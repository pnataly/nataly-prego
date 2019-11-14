#ifndef __MEMPAGE_T_H__
#define __MEMPAGE_T_H__
#include "memManager_t.h"
#include <iostream>
using namespace std;

class memPage_t: public memManager_t 
{
	public:
		memPage_t() {m_buffer = new char[s_defCapacity]; m_capacity = s_defCapacity;}	//default CTOR.
		memPage_t(size_t _cap) {m_buffer = new char[_cap]; m_capacity = _cap;}			//CTOR from size_t.
		virtual ~memPage_t() {delete[]m_buffer;}		//DTOR.
		
		virtual size_t Read(void* _data, size_t _bytes) {return Read(_data, GetPosition(), _bytes);}
		virtual size_t Read(void* _data, size_t _pos, size_t _bytes);
		virtual size_t Write(const void* _data, size_t _bytes) {return Write(_data, _bytes, GetPosition());}
		virtual size_t Write(const void* _data, size_t _bytes, size_t _pos);
		
		bool IsFull() const {return m_capacity == GetActualSize();}
		size_t GetCapacity() const {return m_capacity;}
		static size_t GetDefCapactiy() {return s_defCapacity;}	
		static void SetDefCapacity(size_t _num) {s_defCapacity = _num;}
		
	private:
		memPage_t(const memPage_t& _mp);	//copy CTOR.
		memPage_t& operator=(const memPage_t& _mp);	
		static size_t s_defCapacity;
		char* m_buffer;
		size_t m_capacity;
};


#endif /*__MEMPAGE_T_H__*/ 

