#ifndef COUNTER_H
#define COUNTER_H

#include "IRunnable.h"
#include <cstddef>

namespace advcpp{

class Counter : public IRunnable
{
public:
	Counter(size_t end);
	virtual ~Counter();
	
	virtual void Run();
	size_t GetCount() const;
	
private:
	size_t m_end;
	size_t m_count;
};

}

#endif /*COUNTER_H*/ 
