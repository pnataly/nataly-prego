#ifndef __BOOK_T_H__
#define __BOOK_T_H__

#include <string>
using namespace std;

class Book_t
{
	public:
		Book_t(const string _name, const string _author):Id();
		Book_t(const Book_t&bk);
		virtual ~Book_t();
		
		Book_t& operator= (const Book_t&bk);
		
		const string& GetName() const;
		const string& GetAuthor() const;
		const size_t& GetISBN() const;

	private:
		const string m_name;
		const string m_author;
		const size_t m_ISBN;
};




#endif /*__BOOK_T_H__*/ 
