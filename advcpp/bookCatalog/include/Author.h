#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <tr1/memory>
#include <vector>
#include <string>

namespace advcpp{
using std::tr1::shared_ptr;
using std::string;
using std::vector;
class Book;

class Author
{
public:
	Author(const string& name);
	
	void AddBook(shared_ptr<Book> book);
	const string& Get() const;
	bool IsFound(shared_ptr<Book> book);

	
private:
	Author(const Author& a);
	Author& operator= (const Author& a);

private:
	vector<shared_ptr<Book> > m_vec;
	string m_name;
};

}
#endif /*AUTHOR_H*/ 

