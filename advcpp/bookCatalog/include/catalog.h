#ifndef CATALOG_H
#define CATALOG_H

#include "Book.h"
#include "Publisher.h"
#include "Author.h"
#include <string>
#include <tr1/memory>
#include <tr1/unordered_map>

namespace advcpp{
using std::tr1::shared_ptr;
using std::tr1::unordered_map;
using std::string;

template <typename T>
class Catalog
{
typedef typename unordered_map<string, shared_ptr<T> >::iterator Iter;

public:
	Catalog();
	
	bool Add(shared_ptr<T> item);
	shared_ptr<T> Get(const string& id);
	
private:
	Catalog(const Catalog& c);
	Catalog& operator= (const Catalog& c);
	
private:
	unordered_map<string, shared_ptr<T> > m_map;
};




template <typename T>
Catalog<T>::Catalog()
{}


template <typename T>
bool Catalog<T>::Add(shared_ptr<T> item)
{
	std::pair<Iter, bool> iter = m_map.insert(std::pair<string,shared_ptr<T> > (item->Get() ,item));
	return iter.second == false? false : true;

}


template <typename T>
shared_ptr<T> Catalog<T>::Get(const string& id)
{
	return m_map.find(id)->second;
}

}
#endif /*CATALOG_H*/ 

