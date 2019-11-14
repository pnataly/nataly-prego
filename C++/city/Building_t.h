#ifndef __BUILDING_T_H__
#define __BUILDING_T_H__


template <class T> class Building_t 
{
	public:
		Building_t();
		Building_t(const T _id);
		Building_t(const Building_t& _bd);
		~Building_t();
		const Building_t& operator= (const Building_t& _bd);
		
		const T& GetBuildingID() const;
		void SetBuildingID(const T _id);
	
	private:
		T m_id;
};


template <class T>
Building_t<T>:: Building_t() {}


template <class T>
Building_t<T>:: Building_t(const T _id)
{
	m_id = _id; 
}


template <class T>
Building_t<T>:: Building_t(const Building_t& _bd)
{
	m_id = _bd.m_id;
}


template <class T>
Building_t<T>:: ~Building_t() {}


template <class T>
const Building_t<T>& Building_t<T>::operator= (const Building_t& _bd)
{
	if (this != &_bd)
	{
		m_id = _bd.m_id;
	}
	return *this;
}


template <class T>
const T& Building_t<T>:: GetBuildingID() const
{
	return m_id;
}

template <class T>
void Building_t<T>:: SetBuildingID(T _id)
{
	m_id = _id;
}

#endif /*__BUILDING_T_H__*/ 
