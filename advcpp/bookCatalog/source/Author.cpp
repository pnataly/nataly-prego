#include "Author.h"
#include "Book.h"
#include <algorithm>
#include <vector>

using namespace advcpp;

Author::Author(const string& name)
:	m_name(name)
{}


const string& Author::Get() const
{
	return m_name;
}

void Author::AddBook(shared_ptr<Book> book)
{
	if(std::find(m_vec.begin(), m_vec.end(), book) == m_vec.end())
	{
		m_vec.push_back(book);
	}
}

bool Author::IsFound(shared_ptr<Book> book)
{
	return (std::find(m_vec.begin(), m_vec.end(), book) == m_vec.end()) ? false : true; 
}
