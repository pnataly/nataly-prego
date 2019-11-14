#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "WQueue.h"

typedef struct Consumer Consumer;

Consumer* Create_Consumers(WQ* _wq, size_t _num);

void Join_Consumers(Consumer* _cons);

void Kill_Consumers(Consumer* _cons);

#endif /*__CONSUMER_H__*/ 
