#include <stdlib.h>
#include "Task.h"


struct Task
{
	Taskfunc m_taskFunc;
	size_t m_timePeriod; /*in milisecond*/
	size_t m_timeToRun;	/*in milisecond*/
	void* m_context;
};

Task* TaskCreate(Taskfunc _func, size_t _period, void* _context)
{
	Task* task;
	if(_func == NULL)
	{
		return NULL;
	}
	task = (Task*)malloc(sizeof(Task));
	if(task == NULL)
	{
		return NULL;
	}
	task->m_taskFunc = _func;
	task->m_timePeriod = _period;
	task->m_timeToRun = _period;
	task->m_context = _context;
	return task;
}

void TaskDestroy(Task** _task)
{
	if(_task == NULL || *_task == NULL)
	{
		return;
	}
	free(*_task);
	*_task = NULL;
}

void* GetTaskContext(Task* _task)
{
	if(_task == NULL)
	{
		return NULL;
	}
	return _task->m_context;
}

int TaskRun(Task* _task, void* _context)
{
	if(_task == NULL)
	{
		return NULL_POINTER;
	}
	return _task->m_taskFunc(_context);
}

size_t GetTaskPeriodTime(Task* _task)
{
	if(_task == NULL)
	{
		return 0;
	}
	return _task->m_timePeriod;
}

void SetTaskRunTime(Task* _task, size_t _time)
{
	if(_task == NULL)
	{
		return;
	}
	_task->m_timeToRun = _time;
}

int ResetTime(const void* _element, void* _context)
{
	if(_element == NULL)
	{
		return NULL_POINTER;
	}
	((Task*)_element)->m_timeToRun = ((Task*)_element)->m_timePeriod;
	return DONE;
}
