#include <string>
#include <iostream>
#include "car_t.h"
#include "private_t.h"
using namespace std;

private_t:: private_t()
{
	SetGearType(automatic);
	SetName("private");
	m_accelerate = 10;
	m_reduceSpeed = 10;
}

private_t:: private_t(size_t _capacity, size_t _accelerate, size_t _reduceSpeed):car_t(_capacity)
{
	SetGearType(automatic);
	SetName("private");
	m_accelerate = _accelerate;
	m_reduceSpeed = _reduceSpeed;
}

private_t:: private_t(const private_t& _pv):car_t(_pv)
{
	SetGearType(automatic);
	SetName("private");
	m_accelerate = _pv.m_accelerate;
	m_reduceSpeed = _pv.m_reduceSpeed;
}

