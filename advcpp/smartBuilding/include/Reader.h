#ifndef READER_H
#define READER_H

#include "commons.h"

namespace smarthome{

class Reader
{
public:
	void Read(const char* configFile);
	const map<string, vector<string> >& GetMap() const;
	
private:
	map<string, vector<string> > m_map;

};

}
#endif /*READER_H*/ 
