#ifndef IDEQUEUE_H
#define IDEQUEUE_H

namespace smarthome{

template<typename T>
class IDequeue
{
public:
	virtual ~IDequeue(){}
	virtual T Dequeue() = 0;
	virtual size_t Size() = 0; //TODO
};

}



#endif /*IDEQUEUE_H*/ 
