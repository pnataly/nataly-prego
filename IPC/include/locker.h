#ifndef __LOCKER_H__
#define __LOCKER_H__
#include <pthread.h>
#define LOCKER_UNINITALIZED_ERROR 0

typedef struct Locker
{
	pthread_mutex_t* m_lock;
	size_t m_numOfLock;
}Locker;

/*
 * @brief Create a locker. 
 * @param[in] _numOfLock - number of lockers. 
 * @return pointer to the mutex array.
 */
Locker* LockerCreate(size_t _numOfLock);

/*
 * @brief destroy hash map and set *_map to null.
 * @param[in] _lock : lock to be destroyed.
 * @return void.
 */
void LockerDestroy(Locker** _lock);

/*
 * @brief Lock. 
 * @param[in] _lock - pointer to the lock.
 * @param[in] _index - the index to lock. 
 * @return void.
 */
void Lock(Locker* _lock, size_t _index);

/*
 * @brief Unlock. 
 * @param[in] _lock - pointer to the lock.
 * @param[in] _index - the index to lock. 
 * @return void.
 */
void UnLock(Locker* _lock, size_t _index);

/*
 * @brief get the number to lockers. 
 * @param[in] _lock - pointer to the lock.
 * @return: number to lockers.
 */
size_t GetNumOfLock(Locker* _lock);

#endif /*__LOCKER_H__*/ 
