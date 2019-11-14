#ifndef IENQUEUE_H
#define IENQUEUE_H

namespace smarthome{

template<typename T>
class IEnqueue
{
public:
	virtual ~IEnqueue(){}
	virtual void Enqueue(T item) = 0;
};

}



#endif /*IENQUEUE_H*/ 
