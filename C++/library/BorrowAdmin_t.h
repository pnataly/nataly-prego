#ifndef __BORROWADMIN_T_H__
#define __BORROWADMIN_T_H__
#include "BorrowRecord_t.h"
#include <map>

class BorrowAdmin_t
{
	public:
		BorrowAdmin_t();
		BorrowAdmin_t(const BorrowAdmin_t& bt);
		~BorrowAdmin_t();
		
		BorrowAdmin_t& operator= (const BorrowAdmin_t& bt);
		
		BorrowRecord_t& SerachBorrow(size_t _id) const;					//exception if not found;
		BorrowRecord_t& SerachBorrow(string _name) const;				//exception if not found;
		BorrowRecord_t& SerachBorrow(long long _phoneNum) const;		//exception if not found;
		void AddBorrow(const Book_t& bk, size_t _numOfCopies);
		void RemoveBorrow(const Book_t& bk); 		//exception if not found/not return all the books;
		
	private:
		std::map<BorrowRecord_t*>m_bookRec;		//container of borrower's records - search by id of the borrower.
};



#endif /*__BORROWADMIN_T_H__*/ 
