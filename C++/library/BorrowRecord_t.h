#ifndef __BORROWRECORD_T_H__
#define __BORROWRECORD_T_H__

#include "Borrower_t.h"
#include "Book_t.h"
#include <map>

class BorrowRecord_t
{
	friend class BorrowAdmin_t;
	
	public:
		BorrowRecord_t();
		BorrowRecord_t(const BookRecord_t& bt);
		~BorrowRecord_t();
		
		BorrowRecord_t& operator= (const BorrowRecord_t& bt);

	private:
		Borrower_t* br;
		std::map<Book_t*>m_book; 		//container of pointer to books that borrow by the borrower - search by ISBN of the book.
};



#endif /*__BORROWRECORD_T_H__*/ 
