#ifndef FLAG_H
#define FLAG_H

#include <iostream>
#include <cstddef>
#include <exception>

namespace advcpp {

class Flag
{
typedef bool Flag_Type;
public:
	typedef Flag_Type* Iter;

	Flag(size_t c);
	Flag(const Flag& f);
	Flag& operator= (const Flag& f);
	~Flag();
	
	bool isMark(size_t index) const;
	void Mark(size_t index);
	void Unmark(size_t index);

	void Swap(Flag& f);

	const Iter Begin() const;
	const Iter End() const;
	
private:
	Flag_Type* m_flag;
	size_t m_cap;
};




Flag::Flag(size_t c)
:	m_flag(new Flag_Type[c]())
,	m_cap(c)
{}

Flag::Flag(const Flag& f)
:	m_flag(new Flag_Type[f.m_cap])	
,	m_cap(f.m_cap)
{
	std::copy(f.Begin(), f.End(), Begin());
}

void Flag::Swap(Flag& f)
{
	std::swap(f.m_flag, m_flag);
	std::swap(f.m_cap, m_cap);
}

Flag& Flag::operator= (const Flag& f)
{
	if(this != &f)
	{
		Flag temp(f);
		Swap(temp);
	}
	return *this;
}

Flag::~Flag()
{
	delete[] m_flag;
}

bool Flag::isMark(size_t index) const
{
	return m_flag[index];
}

void Flag::Mark(size_t index)
{
	m_flag[index] = !0;
}

void Flag::Unmark(size_t index)
{
	m_flag[index] = 0;
}


const Flag::Iter Flag::Begin() const
{
	return reinterpret_cast<Iter> (m_flag);
}


const Flag::Iter Flag::End() const
{
	return reinterpret_cast<Iter> (m_flag + m_cap);
}

}

#endif /*FLAG_H*/ 

