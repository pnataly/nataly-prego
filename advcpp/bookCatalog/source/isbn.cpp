#include "isbn.h"

using namespace advcpp;

ISBN::ISBN(const std::string& id)
:	m_isbn(id)
{
}

const std::string& ISBN::GetISBN() const
{
	return m_isbn;
}


