#ifndef __DBLBARR_H__
#define __DBLBARR_H__

typedef struct DB DB; 
typedef void(*Func)(void*);

DB* CreateDoubleBarrier(size_t _numOfThreads);

void DestroyDoubleBarrier(DB** _db);

void BarrWait(DB* _db, void(*_func)(void* _item), void* _context);


#endif /*__DBLBARR_H__*/ 
