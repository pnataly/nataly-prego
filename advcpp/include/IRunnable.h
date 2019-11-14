#ifndef IRUNNABLE_H
#define IRUNNABLE_H

namespace advcpp{

class IRunnable
{
public:
	IRunnable(){}
	virtual void Run() = 0;
	
protected:
	virtual ~IRunnable(){}
};

}

#endif /*IRUNNABLE_H*/ 
