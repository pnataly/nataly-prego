#define _XOPEN_SOURCE 500

#include <stdlib.h>
#include <unistd.h> /* for usleep */
#include <stdint.h>
#include "Time.h"

int TimeLessCheck(const void* _time1, const void* _time2)
{
	if(_time1 == NULL || _time2 == NULL)
	{
		return FALSE;
	}
	if(*(size_t*)_time1 < *(size_t*)_time2)
	{
		return TRUE;
	}
	return FALSE;
}

size_t GetTimer()
{
	time_t begin;
	begin = time(NULL);
	return begin;
}

size_t TimerEnd()
{
	time_t end;
	end = time(NULL);
	return end;
}

void ToSleep(size_t _time)
{
	usleep(_time * 1000);
}

