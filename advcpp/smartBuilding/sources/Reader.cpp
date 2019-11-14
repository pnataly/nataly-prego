#include "Reader.h"

#include <libconfig.h++>
#include <iostream>

namespace smarthome{
using namespace libconfig;

void Reader::Read(const char* configFile)
{
	Config cfg;
	try
	{
		cfg.readFile(configFile);	
	}
	catch(const FileIOException& fioex)
	{
		std::cerr<<"I/O error while reading file."<<'\n';
		return;
	}
 	catch(const ParseException &pex)
 	{
  		  std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
			<< " - " << pex.getError() << '\n';
			return;
	}
	string lib,id,type,room,floor;
	const Setting& root=cfg.getRoot();	
	try{
		const Setting& agent= root["agents"]["agent"];
		int count=agent.getLength();
	
		for(int i=0; i<count; ++i)
		{	
			const Setting& ag=agent[i];
			try
			{
				ag.lookupValue("lib",lib);
			}
			catch(const SettingNotFoundException& nfex)
			{
				std::cerr << "No 'lib' setting in configuration file." << '\n';
				return;
			}
			try
			{
				ag.lookupValue("id",id);
			}
			catch(const SettingNotFoundException& nfex)
			{
				std::cerr << "No 'id' setting in configuration file." << '\n';
				return;
			}
			
			try
			{
				ag.lookupValue("type",type);
			}
			catch(const SettingNotFoundException& nfex)
			{
				std::cerr << "No 'type' setting in configuration file." << '\n';
				return;
			}

			try
			{
				ag.lookupValue("room",room);
			}
			catch(const SettingNotFoundException& nfex)
			{
				std::cerr << "No 'room' setting in configuration file." << '\n';
				return;
			}	
			try
			{
				ag.lookupValue("floor",floor);
			}
			catch(const SettingNotFoundException& nfex)
			{
				std::cerr << "No 'floor' setting in configuration file." << '\n';
				return;
			}
			
			vector<string> vec;
			vec.push_back(lib);
			vec.push_back(id);
			vec.push_back(type);
			vec.push_back(room);
			vec.push_back(floor);
			m_map.insert(std::pair<string,vector<string> >(id,vec));
		}
	}
	catch(const SettingNotFoundException& nfex)
	{
		return;
	}
}


const map<string, vector<string> >& Reader::GetMap() const
{
	return m_map;
}

}

