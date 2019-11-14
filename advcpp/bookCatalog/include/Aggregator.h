#ifndef AGGREGATOR_H
#define AGGREGATOR_H

#include <tr1/memory>
#include "IQuery.h"
#include "IUpdate.h"
#include "catalog.h"
#include "indexBy.h"

namespace advcpp{
class Book;
class Author;
class Publisher;
using std::tr1::shared_ptr;


class Aggregator: public IUpdate, public IQuery
{
public:
	Aggregator();

	virtual void Update(shared_ptr<Book> book);
	virtual shared_ptr<Book> SearchByISBN(const string& isbn);
//	virtual shared_ptr<Book> SearchByTitle(const string& title);
	
private:
	Aggregator(const Aggregator& a);
	Aggregator& operator= (const Aggregator& a);
	
private:
	Catalog<Book> m_books;
	Catalog<Author> m_authors;
	Catalog<Publisher> m_publishers;
	IndexBy m_words;
};

}
#endif /*AGGREGATOR_H*/ 

