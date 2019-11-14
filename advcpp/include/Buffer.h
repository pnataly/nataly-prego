#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <exception>
#include <algorithm>
#include "Flag.h"

namespace advcpp {

template <class T> 
class Buffer
{
typedef unsigned char Byte;
template <class U>  
friend class Copy;

public:

	Buffer(size_t c);
	Buffer(const Buffer& b);
	Buffer& operator= (const Buffer& b);
	~Buffer();
	
	const T* operator[] (size_t index) const;
	T* operator[](size_t index);
	
	void Grow(size_t c);
	void Shrink(size_t c); 
	
	void Put(size_t index, const T& t);
	T* Get(size_t index) const;
	
	size_t Capacity() const;

	void Swap(Buffer<T> b);
	
	typedef T* Iter;
	const Iter Begin() const;
	const Iter End() const;

private:
	void copyBuffer(const Buffer& source, Buffer& target);

private:
	Byte* m_data;
	size_t m_cap;
	Flag m_flag;
};




template <class T> 
Buffer<T>::Buffer(size_t c)
:	m_data(new Byte[c*sizeof(T)])
, 	m_cap(c)
,	m_flag(c)
{}
	

template <class T> 
Buffer<T>::Buffer(const Buffer& b)
:	m_data(new Byte[sizeof(T)*b.m_cap])	
,	m_cap(b.m_cap)
,	m_flag(b.m_flag)
{
	copyBuffer(b, *this);
}	



template <class T>
class Destroy
{
public:
	Destroy(const Flag& f);
	void operator()(T& obj);
private:
	size_t index;
	const Flag& m_flag;	
};

template <class T>
Destroy<T>::Destroy(const Flag& f)
:	index(0)
,	m_flag(f)
{}

template <class T>
void Destroy<T>::operator()(T& obj)
{
	if(m_flag.isMark(index++))
	{
		obj.T::~T();
	}
}


template <class T> 
Buffer<T>::~Buffer()
{
	std::for_each(Begin(), End(), Destroy<T>(m_flag));
	delete[] m_data;
}

template <class T> 
void Buffer<T>::Swap(Buffer<T> b)
{
	std::swap(b.m_cap, m_cap);
	std::swap(b.m_data, m_data);
	std::swap(b.m_flag, m_flag);
}

template <class T> 
Buffer<T>& Buffer<T>::operator= (const Buffer& b)
{
	if(this == &b)
	{
		return *this;
	}	
	Buffer<T> temp(b);
	Swap(temp);
	return *this;
}


template <class T> 
const T* Buffer<T>::operator[] (size_t index) const
{
	return reinterpret_cast<T*> (m_data[index*sizeof(T)]);
}

template <class T> 
T* Buffer<T>::operator[] (size_t index)
{
	return reinterpret_cast<T*> (m_data[index * sizeof(T)]);
}

template <class T> 
size_t Buffer<T>::Capacity() const
{
	return m_cap;
}

template <class T> 
T* Buffer<T>::Get(size_t index) const
{
	if(index > m_cap)
	{
		throw std::out_of_range("The index is out of range");
	}
	if(!m_flag.isMark(index) )	
	{
		throw std::invalid_argument("there is no element in this index");
	}
	return reinterpret_cast<T*> (m_data[index * sizeof(T)]);
}


template <class T> 
void Buffer<T>::Put(size_t index, const T& t)
{
	if(index > m_cap)
	{
		throw std::out_of_range("The index is out of range");
	}
	Iter it = Begin();
	it += index;
	if(m_flag.isMark(index)) 
	{
		*it = t;
	}
	else
	{
		new(it) T(t);
		m_flag.Mark(index); 
	}
}


template <class T> 
const typename Buffer<T>::Iter Buffer<T>:: Begin() const
{
	return reinterpret_cast<Iter> (m_data);
}

template <class T> 
const typename Buffer<T>::Iter Buffer<T>:: End() const
{
	return reinterpret_cast<Iter> (m_data + m_cap*sizeof(T));
}



template <class U>
class Copy
{
public:
	Copy(Buffer<U>& buffer);
	void operator()(U& obj);
private:
	size_t index;
	Buffer<U>& m_buf;
	typename Buffer<U>::Iter target;	
};

template <class U>
Copy<U>::Copy(Buffer<U>& buffer)
:	index(0)
,	m_buf(buffer)
,	target(buffer.Begin())
{}

template <class U>
void Copy<U>::operator()(U& obj)
{
	if(m_buf.m_flag.isMark(index++))
	{
		new(target) U(obj);
	}
	++target;
}

template <class T>
void Buffer<T>::Grow(size_t c) 
{
	if(c <= m_cap)
	{
		return;
	}
	Buffer<T> temp(c);
	std::for_each(Begin(), End(), Copy<T>(temp));
	Swap(temp);
}

template <class T>
void Buffer<T>::Shrink(size_t c) 
{
	if(c >= m_cap)
	{
		return;
	}
	Buffer<T> temp(c);
	std::for_each(Begin(), End(), Copy<T>(temp));
	Swap(temp);	
}

template <class T> 
void Buffer<T>::copyBuffer(const Buffer& source, Buffer& target)
{
	std::for_each(source.Begin(), source.End(), Copy<T>(target));
}

}

#endif /*BUFFER_H*/ 

