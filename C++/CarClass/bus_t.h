#ifndef __BUS_T_H__
#define __BUS_T_H__

#include <string>
#include <iostream>
#include "car_t.h"
using namespace std;

class bus_t: public car_t
{
	public:
		bus_t();
		bus_t(size_t _capacity, size_t _numOfSeats, size_t _numOfLine);
		bus_t(const bus_t& _bus);
		~bus_t(){;}
		
		const size_t GetNumOfSeats() const {return m_numOfSeats;}
		const size_t GetLine() const {return m_line;}
		size_t SetNumOfSeats(size_t _num) {m_numOfSeats = _num;} 
		size_t SetLine(size_t _line) {m_line = _line;}

	private:
		size_t m_numOfSeats;
		size_t m_line;
};



#endif /*__BUS_T_H__*/ 
