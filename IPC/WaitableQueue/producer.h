#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "WQueue.h"

typedef struct Producer Producer;

Producer* Create_Producers(WQ* _wq, size_t _num);

void Join_Producers(Producer* _prod);

#endif /*__PRODUCER_H__*/ 
