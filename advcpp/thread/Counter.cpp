#include "Counter.h"
#include "IRunnable.h"

namespace advcpp{

Counter::Counter(size_t end)
:	m_end(end)
,	m_count(0)
{}

Counter::~Counter()
{}

void Counter::Run()
{
	for(size_t i = 0; i<m_end; ++i)
	{
		++m_count; 
	}
}

size_t Counter::GetCount() const
{
	return m_count;
}

}
