#ifndef IQUERY_H
#define IQUERY_H

#include <tr1/memory>
#include <string>
#include "Book.h"
#include "Author.h"

namespace advcpp{
using std::tr1::shared_ptr;
using std::string;

class IQuery
{
	virtual shared_ptr<Book> SearchByISBN(const string& isbn) = 0;
//	virtual shared_ptr<Book> SearchByTitle(const string& title) = 0;
//	virtual shared_ptr<Author> SearchByAuthor(const string& author) = 0;
};

}

#endif /*IQUERY_H*/ 
