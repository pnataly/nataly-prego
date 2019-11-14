#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <tr1/memory>
#include "isbn.h"
#include "Year.h"

namespace advcpp{
using std::string;
using std::tr1::shared_ptr;
class Author;
class Publisher;

class Book
{
public:

	Book(const ISBN& id, const string& title, shared_ptr<Author> author, const Year& year, shared_ptr<Publisher> publisher);

	const string& Get() const;
	const ISBN& GetISBN() const;
	const Year& GetYear() const;
	const string& GetTitle() const;
	shared_ptr<Author> GetAuthor() const;
	shared_ptr<Publisher> GetPublisher() const;
	
private:
	Book(const Book& b);
	Book& operator= (const Book& b);

private:
	ISBN m_isbn;
	Year m_year;
	string m_title;
	shared_ptr<Author> m_author;
	shared_ptr<Publisher> m_publisher;
};

}
#endif /*BOOK_H*/ 

