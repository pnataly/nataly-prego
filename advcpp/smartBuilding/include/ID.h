#ifndef ID_H
#define ID_H

#include "commons.h"

namespace smarthome{

class ID
{
public:
	ID(const string& id);
	
	const string& GetId() const;

private:
	string m_id;
};

}

#endif /*ID_H*/ 
