#ifndef __CITY_T_H__
#define __CITY_T_H__

#include <vector>
#include "Street_t.h"

template <class T1, class T2, class T3> class City_t
{
	public:
		City_t();
		City_t(const T3 _id);
		City_t(const City_t& _ct);
		~City_t();
		const City_t& operator= (const City_t& _ct);
		
		const T3& GetCityID() const;
		void SetCityID(const T3 _id);
		void AddStreet(Street_t<T1, T2>* _st);
		Street_t<T1, T2>* GetStreet(size_t _index) const;
	
	private:
		T3 m_id;
		vector<Street_t<T1,T2>*>m_vec;
}; 

template <class T1, class T2, class T3>
City_t<T1,T2,T3>:: City_t() {}

template <class T1, class T2, class T3>
City_t<T1,T2,T3>:: City_t(const T3 _id)
{
	m_id = _id;
}

template <class T1, class T2, class T3>
City_t<T1,T2,T3>:: City_t(const City_t& _ct)
{
	m_id = _ct.m_id;
}


template <class T1, class T2, class T3>
City_t<T1,T2,T3>:: ~City_t() {}


template <class T1, class T2, class T3>
const City_t<T1,T2,T3>& City_t<T1,T2, T3>:: operator= (const City_t& _ct)
{
	if (this != &_ct)
	{
		m_id = _ct.m_id;
	}
	return *this;
}

template <class T1, class T2, class T3>
const T3& City_t<T1,T2,T3>:: GetCityID() const
{
	return m_id;
}

template <class T1, class T2, class T3>
void City_t<T1, T2, T3>:: SetCityID(const T3 _id)
{
	m_id = _id;
}

template <class T1, class T2, class T3>
void City_t<T1, T2,T3>:: AddStreet(Street_t<T1,T2>* _st)
{
	m_vec.push_back(_st);
}


template <class T1, class T2, class T3>
Street_t<T1,T2>* City_t<T1, T2, T3>:: GetStreet(size_t _index) const
{
	return m_vec[_index];
}

#endif /*__CITY_T_H__*/ 
