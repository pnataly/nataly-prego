#ifndef ISBN_H
#define ISBN_H

#include <string>

namespace advcpp{

class ISBN
{
public:
	ISBN(const std::string& id);
	const std::string& GetISBN() const;
		
private:
	std::string m_isbn;
};

}
#endif /*ISBN_H*/ 
