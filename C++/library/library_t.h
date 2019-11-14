#ifndef __LIBRARY_T_H__
#define __LIBRARY_T_H__

#include "BorrowAdmin_t.h"
#include "BookAdmin_t.h"

class Library_t
{
	public:
		Library_t();
		
		Add();		
		Remove();	
		Search();	
		Report();	

	private:
		Library_t(const Library_t& lb);
		Library_t& operator= (Library_t& lb);
		~Library_t();
};



#endif /*__LIBRARY_T_H__*/ 
