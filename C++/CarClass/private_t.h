#ifndef __PRIVATE_T_H__
#define __PRIVATE_T_H__

#include <string>
#include <iostream>
#include "car_t.h"
using namespace std;

class private_t: public car_t
{
	public:
		private_t();
		private_t(size_t _capacity, size_t _accelerate, size_t _reduceSpeed);
		private_t(const private_t& _pv);
		~private_t(){;}
		
		const size_t GetAccelerate() const {return m_accelerate;}
		const size_t GetReduceSpeed() const {return m_reduceSpeed;}
		size_t SetAccelerate(size_t _num) {m_accelerate = _num;}
		size_t SetReduceSpeed(size_t _num) {m_reduceSpeed = _num;}

	private:
		size_t m_accelerate;
		size_t m_reduceSpeed;
};



#endif /*__PRIVATE_T_H__*/ 
