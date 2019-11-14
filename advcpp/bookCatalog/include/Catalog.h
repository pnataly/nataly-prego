//catalogs- contain all the containers of the catalogs- book,authors,publishers.
#ifndef CATALOGS_H
#define CATALOGS_H

#include <tr1/memory>
#include "Authors.h"
#include "Publishers.h"
#include "Books.h"
#include "Book.h"
#include "IAddBook.h"
#include "ILookUp.h"

namespace advcpp{
using std::tr1::shared_ptr;

class Catalog : public IAddBook, public ILookUp
{
public:
	Catalog(shared_ptr<Authors> a, shared_ptr<Publishers> p, shared_ptr<Books> b); 
	virtual void AddBook(const shared_ptr<Book> book);
	virtual shared_ptr<Book> GetBook(size_t ISBN); 

private:
	shared_ptr<Authors> m_authors;
	shared_ptr<Publishers> m_publishers;
	shared_ptr<Books> m_books;
};



Catalog::Catalog(shared_ptr<Authors> a, shared_ptr<Publishers> p, shared_ptr<Books> b)
:	m_authors(a)
,	m_publishers(p)
,	m_books(b)
{}

void Catalog::AddBook(const shared_ptr<Book> book)
{
	m_books->insertBook(book);
	
}

}

#endif /*CATALOGS_H*/
 
