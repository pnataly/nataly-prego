#ifndef INDEXBY_H
#define INDEXBY_H

#include "Book.h"
#include <string>
#include <tr1/memory>
#include <tr1/unordered_map>

namespace advcpp{
using std::tr1::shared_ptr;
using std::tr1::unordered_multimap;
using std::string;


class IndexBy
{
typedef unordered_multimap<string, shared_ptr<Book> >::iterator IIter; 

public:
	IndexBy();
	
	void Add(shared_ptr<Book> book, const string& word);
	shared_ptr<Book> Get(const string& word);
	
private:
	IndexBy(const IndexBy& c);
	IndexBy& operator= (const IndexBy& c);
	
private:
	unordered_multimap<string, shared_ptr<Book> > m_map;
};


}
#endif /*INDEXBY_H*/ 

