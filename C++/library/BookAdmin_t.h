#ifndef __BOOKADMIN_T_H__
#define __BOOKADMIN_T_H__

#include "BookRecord_t.h"
#include <map>

class BookAdmin_t
{
	public:
		BookAdmin_t();
		BookAdmin_t(const BookAdmin_t& ba);
		~BookAdmin_t();
		
		BookAdmin_t& operator= (const BookAdmin_t& ba);
		
		BookRecord_t& SerachBook(string _name) const;		//exception if not found;
		BookRecord_t& SerachBook(string _author) const;		//exception if not found;
		BookRecord_t& SerachBook(size_t _ISBN) const;		//exception if not found;
		void AddBook(const Book_t& bk, size_t _numOfCopies);
		void RemoveBook(const Book_t& bk); 		//exception if not found/not all the copies are in the library;
	
	private:
		std::map<BookRecord_t*>m_bookRec;		//container of book's records - search by ISBN of the book.
};


#endif /*__BOOKADMIN_T_H__*/ 
