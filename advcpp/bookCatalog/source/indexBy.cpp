#include "indexBy.h"
#include "Book.h"
#include <string>
#include <tr1/memory>
#include <tr1/unordered_map>

using namespace advcpp;
using std::tr1::shared_ptr;
using std::string;

IndexBy::IndexBy()
{}


void IndexBy::Add(shared_ptr<Book> book,const string& word)
{
	m_map.insert(std::make_pair<string,shared_ptr<Book> > (word ,book));
}


shared_ptr<Book> IndexBy::Get(const string& word)
{
	return m_map.find(word)->second;
}
