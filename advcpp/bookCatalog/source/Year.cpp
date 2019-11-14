#include "Year.h"

using namespace advcpp;

Year::Year(const std::string& year)
:	m_year(year)
{

}

const std::string& Year::GetYear() const
{
	return m_year;
}
