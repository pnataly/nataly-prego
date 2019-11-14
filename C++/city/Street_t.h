#ifndef __STREET_T_H__
#define __STREET_T_H__

#include <vector>
#include "Building_t.h"
using namespace std;

template <class T1, class T2> class Street_t
{
	public:
		Street_t();
		Street_t(const T2 _id);
		Street_t(const Street_t& _st);
		~Street_t();
		const Street_t& operator= (const Street_t& _st);
		
		const T2& GetStreetID() const;
		void SetStreetID(const T2 _id);
		void AddBuilding2Street(Building_t<T1>* _b);
		Building_t<T1>* GetBuilding(size_t _index) const;

	private:
		T2 m_id;
		vector<Building_t<T1>*>m_vec;
}; 

template <class T1, class T2>
Street_t<T1,T2>:: Street_t() {}

template <class T1, class T2>
Street_t<T1,T2>:: Street_t(const T2 _id)
{
	m_id = _id;
}

template <class T1, class T2>
Street_t<T1, T2>:: Street_t(const Street_t& _st)
{
	m_id = _st.m_id;
}

template <class T1, class T2>
Street_t<T1,T2>:: ~Street_t() {}

template <class T1, class T2>
const Street_t<T1,T2>& Street_t<T1,T2>:: operator= (const Street_t& _st)
{
	if (this != &_st)
	{
		m_id = _st.m_id;
	}
	return *this;
}

template <class T1, class T2>
const T2& Street_t<T1,T2>:: GetStreetID() const
{
	return m_id;
}

template <class T1, class T2>
void Street_t<T1,T2>:: SetStreetID(const T2 _id)
{
	m_id = _id;
}

template <class T1, class T2>
void Street_t<T1,T2>:: AddBuilding2Street(Building_t<T1>* _b) 
{
	m_vec.push_back(_b);
}

template <class T1, class T2>
Building_t<T1>* Street_t<T1,T2>:: GetBuilding(size_t _index) const
{
	return m_vec[_index];
}

#endif /*__STREET_T_H__*/ 

