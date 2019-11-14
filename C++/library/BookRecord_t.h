#ifndef __BOOKRECORD_T_H__
#define __BOOKRECORD_T_H__

#include "Book_t.h"
#include "Borrower_t.h"
#include <map>
using namespace std;

class BookRecord_t
{
	friend class BookAdmin_t;
	 
	public:
		BookRecord_t();
		BookRecord_t(const Book_t& bk);
		~BookRecord_t();	
		
		BookRecord_t& operator= (const BookRecord_t&bk);
		
		const size_t& GetNumOfCopies() const;

	private:
		size_t m_numOfCopies;
		Book_t* bk;	
		std::map<Borrower_t*>m_borrow;		//container of pointers to the borrow's' of this book- search by id of the borrow.
};




#endif /*__BOOKRECORD_T_H__*/ 
