#ifndef __MEMMANAGER_T_H__
#define __MEMMANAGER_T_H__

#include <iostream>
using namespace std;

class memManager_t 
{
	public:
		memManager_t(){m_position = 0; m_actualSize = 0;}		//default CTOR.
		virtual ~memManager_t(){};								//DTOR.
		
		size_t GetActualSize() const {return m_actualSize;} 
		size_t GetPosition() const {return m_position;}
		bool IsEmpty() const {return m_actualSize == 0;}
		size_t SetPosition(size_t _pos) 
		{
			if(_pos > m_actualSize)
			{
				return 0;
			}
			size_t oldPos = m_position;
			m_position = _pos;
			return oldPos;
		}
		
		virtual size_t Read(void* _data, size_t _bytes) = 0;
		virtual size_t Read(void* _data, size_t _pos, size_t _bytes) = 0;
		virtual size_t Write(const void* _data, size_t _bytes) = 0;
		virtual size_t Write(const void* _data, size_t _bytes, size_t _pos) = 0;
		
	protected:
		void SetActualSize(size_t _num) {m_actualSize = _num;}
		
	private:
		memManager_t(const memManager_t& _mm);		//copy CTOR.
		memManager_t& operator= (const memManager_t& _mm);	
		size_t m_position;
		size_t m_actualSize;
};


#endif /*__MEMMANAGER_T_H__*/ 

