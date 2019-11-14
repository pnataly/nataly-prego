#include "isbn.h"
#include "Year.h"
#include "Author.h"
#include "Publisher.h"
#include "Book.h"

using namespace advcpp;

Book::Book(const ISBN& id, const string& title, shared_ptr<Author> author, const Year& year, shared_ptr<Publisher> publisher)
:	m_isbn(id)
,	m_year(year)
,	m_title(title)
,	m_author(author)
,	m_publisher(publisher)
{}

const string& Book::Get() const
{
	return m_isbn.GetISBN();
}

const ISBN& Book::GetISBN() const
{
	return m_isbn;
}

const string& Book::GetTitle() const
{
	return m_title;
}

shared_ptr<advcpp::Author> Book::GetAuthor() const
{
	return m_author;
}

const Year& Book::GetYear() const
{
	return m_year;
}

shared_ptr<advcpp::Publisher> Book::GetPublisher() const
{
	return m_publisher;
}
