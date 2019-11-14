#include <string>
#include <iostream>
#include "car_t.h"
#include "bus_t.h"
using namespace std;

bus_t:: bus_t()
{
	SetGearType(standard);
	SetName("bus");
	m_numOfSeats = 50;
	m_line = 11;
}

bus_t:: bus_t(size_t _capacity, size_t _numOfSeats, size_t _numOfLine):car_t(_capacity)
{
	SetGearType(standard);
	SetName("bus");
	m_numOfSeats = _numOfSeats;
	m_line = _numOfLine;
}

bus_t:: bus_t(const bus_t& _bus):car_t(_bus)
{
	SetGearType(standard);
	SetName("bus");
	m_numOfSeats = _bus.m_numOfSeats;
	m_line = _bus.m_line;
}

