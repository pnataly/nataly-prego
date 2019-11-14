#ifndef STRING_H
#define STRING_H

#include "Buffer.h"
#include "Util.h"


namespace advcpp {

template <class T> 
class String
{
public:
	String(const T* s = 0);		
		
	String& operator+= (const String& a);

	const T* operator[] (size_t index) const;	
	T* operator[](size_t index);
	
	//SetString();
	size_t Size() const;

	typedef T* Iter;
	Iter Begin() const;
	Iter End() const;
	
private:
	size_t m_size;			
	Buffer<T> m_buf;
};



template <class T>
std::ostream& operator<< (std::ostream& os, const String<T>& st)
{
	os << st.Begin();
	return os;
}

/*
template <class T>
std::istream& operator>> (std::istream&is, String<T>& st);
*/

template <class T>
String<T> operator+ (const String<T>& a, const String<T>& b)
{
	String<T> r(a);
	r += b;
	return r;
}	

template <class T>
bool operator== (const String<T>& a, const String<T>& b)
{
	return Util<T>::Compare(a.Begin(), b.Begin()) == 0;
}

template <class T>
bool operator!= (const String<T>& a, const String<T>& b)
{
	return !(a == b);
}	

template <class T>		
bool operator> (const String<T>& a, const String<T>& b)
{
	return Util<T>::Compare(a.Begin(), b.Begin());
}

template <class T>				
bool operator< (const String<T>& a, const String<T>& b)
{
	return b>a;
}	


template <class T>			
bool operator>= (const String<T>& a, const String<T>& b)
{
	return Util<T>::Compare(a.Begin(), b.Begin()) >= 0;
}

template <class T>			
bool operator<= (const String<T>& a, const String<T>& b)
{
	return b>=a;
}


template <class T>			
String<T>& toUpper(String<T>& s)
{
	return Util<T>::ToUpper(reinterpret_cast<T*> (s.Begin()));
}	

template <class T>			
long toLong(const String<T>& s)
{
	return Util<T>::ToLong(reinterpret_cast<T*> (s.Begin()));
}


template <class T>
String<T>::String(const T* s)
:	m_size(Util<T>::Size(s))	
,	m_buf(m_size)
{
	for(size_t i =0; i<m_size; ++i)
	{
		m_buf.Put(i, s[i]);
	}
	m_buf.Put(m_size, T(0));
}


template <class T>
size_t String<T>::Size() const
{
	return m_size;
}

template <class T>
String<T>& String<T>::operator+= (const String& a)
{
	size_t old = m_size;

	Iter end = End();
	Iter src = a.Begin();
	
	m_buf.Grow(m_size + a.m_size);
	m_size += a.m_size;
	
	*end++ = *src++; 
	for(size_t i = old ; src != a.End(); ++i)
	{
		m_buf.Put(i, *src++);
	}
	m_buf.Put(m_size, T(0));
	return *this;
} 

template <class T>
const T* String<T>::operator[] (size_t index) const
{
	return m_buf[index];
}	

template <class T>
T* String<T>::operator[] (size_t index)
{
	return m_buf[index];
}

template <class T>
typename String<T>::Iter String<T>::Begin() const
{
	return m_buf.Begin();
}

template <class T>
typename String<T>::Iter String<T>::End() const
{
	return m_buf.End();
}

}

#endif /*STRING_H*/ 

