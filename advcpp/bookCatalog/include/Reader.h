#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <exception>
#include "Book.h"

namespace advcpp{
using std::string;

class Reader
{
public:
	void Run(const string& fileName); 

};




void Reader::Run(const string& fileName) 
{ 	
	std::ifstream file(fileName); 	
	if(!file) 	
	{ 		
		throw std::ios_base::failure("cannot open the file"); 	
	} 	
	string line; 	
	while(getline(file, line)) 	
	{ 		
		std::cout << line << '\n'; 			
	} 	
}

}
#endif /*READER_H*/ 

