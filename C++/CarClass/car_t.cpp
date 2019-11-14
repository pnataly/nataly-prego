#include <string>
#include <iostream>
#include "car_t.h"
using namespace std;

size_t car_t:: s_id = 0;
size_t car_t:: s_capacity = 1000;


bool car_t::Compare(const car_t& _car) const
{
	return ((m_name == _car.m_name)== 0)? true:false;
}

