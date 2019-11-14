#ifndef COMMONS_H
#define COMMONS_H

#include <set>
#include <map>
#include <string>
#include <vector>
#include <exception>
#include <tr1/memory>
#include <tr1/unordered_map>

#define NOEXCEPT throw()

using std::map;
using std::set;
using std::pair;
using std::vector;
using std::string;
using std::exception;
using std::tr1::shared_ptr;
using std::tr1::unordered_map;

class LookUp_NotFound_Exception : public exception 
{
public:
	LookUp_NotFound_Exception(const string& err) 
	:	m_err(err) 
	{}
	
	virtual ~LookUp_NotFound_Exception() NOEXCEPT{}
	
	const string& What() const
	{
		return m_err;
	}
private:
	string m_err;
};


#endif /*COMMONS_H*/ 
