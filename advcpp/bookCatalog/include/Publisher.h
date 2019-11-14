#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <tr1/memory>
#include <vector>
#include <string>


namespace advcpp{
using std::tr1::shared_ptr;
using std::string;
using std::vector;
class Book;

class Publisher
{
public:

	Publisher(const string& name);

	void AddBook(shared_ptr<Book> book);
	const string& Get() const;
	bool IsFound(shared_ptr<Book> book);

private:
	Publisher(const Publisher& p);
	Publisher& operator= (const Publisher& p);
	
private:
	vector<shared_ptr<Book> > m_vec;
	string m_name;
};

}
#endif /*PUBLISHER_H*/ 

