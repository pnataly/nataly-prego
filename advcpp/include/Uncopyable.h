#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H

namespace advcpp{

class Uncopyable
{
public:
	Uncopyable(){}
	~Uncopyable(){}
	
private:
	Uncopyable(const Uncopyable& unc);
	Uncopyable& operator= (const Uncopyable& unc);
};

}

#endif /*UNCOPYABLE_H*/ 
