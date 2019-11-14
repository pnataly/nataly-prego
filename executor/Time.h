#ifndef __TIME_H__
#define __TIME_H__
#include <time.h>

#define TRUE 1
#define FALSE 0

/*
 * @brief compare between two times.
 * @param: _time1.
 * @param: _time2.
 * @return TRUE if time1 < time2.
 * @return FALSE if not.
 */
int TimeLessCheck(const void* _time1, const void* _time2);

/*
 * @brief start timer.
 * @return the start time.
 */
size_t GetTimer();

/*
 * @brief end timer.
 * @return the end time.
 */
size_t TimerEnd();

/*
 * @brief sleep ZzZzZz.
 * @param: _time - time to sleep.
 * @return.
 */
void ToSleep(size_t _time);


#endif /*__TIME_H__*/ 
