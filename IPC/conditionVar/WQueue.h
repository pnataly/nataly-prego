#ifndef __WQUEUE_H__
#define __WQUEUE_H__

#include <semaphore.h>
#include <pthread.h>

typedef struct WQ WQ;

typedef struct condVar condVar;

WQ* WQueue_Create(size_t _size);

void WQueue_Enqueue(WQ* _wq, void* _item);

void WQueue_Dequeue(WQ* _wq, void** _pValue);

void WQueue_Destroy(WQ** _wq, void (*_elementDestroy)(void* _item));

#endif /*__WQUEUE_H__*/ 
