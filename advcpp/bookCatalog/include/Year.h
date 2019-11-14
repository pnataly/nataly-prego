#ifndef YEAR_H
#define YEAR_H

#include <string>

namespace advcpp{
class Year
{
public:
	Year(const std::string& year);
	const std::string& GetYear() const;

private:
	std::string m_year;
};

}

#endif /*YEAR_H*/ 
