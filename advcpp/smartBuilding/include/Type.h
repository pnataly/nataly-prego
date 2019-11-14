#ifndef TYPE_H
#define TYPE_H

#include "commons.h"

namespace smarthome{

class Type
{
public:
	Type(const string& type);
	
	const string& GetType() const;

private:
	string m_type;
};

}

#endif /*TYPE_H*/ 
