#include "Aggregator.h"
#include "Book.h"
#include "Author.h"
#include "Publisher.h"

using namespace advcpp;
using std::tr1::shared_ptr;

Aggregator::Aggregator()
{}


void Aggregator::Update(shared_ptr<Book> book)
{
	m_books.Add(book);
	m_authors.Add(book->GetAuthor());
	m_publishers.Add(book->GetPublisher());
}


shared_ptr<Book> Aggregator::SearchByISBN(const string& isbn)
{
	return m_books.Get(isbn);
}
