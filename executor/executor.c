#include <stdlib.h>
#include "executor.h"

struct Executor
{
	Heap* m_heap;
	size_t numOfTasks;
	int m_IsPauseFlag;
};

static int IsPause(Executor* _executor);

Executor* ExecutorCreate(size_t _initialTasksSize, size_t _extensionTasksSize)
{
	Executor* executor;
	Vector* vector;
	Heap* heap;
	vector = VectorCreate(_initialTasksSize, _extensionTasksSize);
	if(vector == NULL)
	{
		return NULL;
	}
	heap = Heap_Build(vector, TimeLessCheck);
	if(heap == NULL)
	{
		VectorDestroy(&vector, NULL);
		return NULL;
	}
	executor = (Executor*)malloc(sizeof(Executor));
	if(executor == NULL)
	{
		vector = Heap_Destroy(&heap);
		VectorDestroy(&vector, NULL);
		return NULL;
	}
	executor->m_heap = heap;
	executor->numOfTasks = 0;
	executor->m_IsPauseFlag = 0;
	return executor;
}

void ExecutorDestroy(Executor** _executor)
{
	Task* task;
	Vector* vector;
	if(_executor == NULL || *_executor == NULL)
	{
		return;
	}
	while((*_executor)->numOfTasks >0)
	{
		task = Heap_Extract((*_executor)->m_heap);
		TaskDestroy(&task);
		(*_executor)->numOfTasks--;
	}
	vector = Heap_Destroy(&(*_executor)->m_heap);
	VectorDestroy(&vector, NULL);
	free(*_executor);
	*_executor = NULL;
}

Executor_Result ExecutorRun(Executor* _executor)
{
	size_t time, newTime;
	Task* task;
	if(_executor == NULL)
	{
		return EXECUTOR_UNINITIALIZED_ERROR;
	}
	while(_executor->numOfTasks > 0)
	{
		time = GetTimer();
		task = Heap_Extract(_executor->m_heap);
		ToSleep(GetTaskPeriodTime(task)); 
		if (TaskRun(task, GetTaskContext(task)) == 0)
		{
			_executor->numOfTasks--;
			TaskDestroy(&task);
		}
		else
		{
			newTime = time + GetTaskPeriodTime(task);
			SetTaskRunTime(task, newTime);
			Heap_Insert(_executor->m_heap, task);
		}
		if (IsPause(_executor) == TRUE)
		{
			_executor->m_IsPauseFlag = 0;
			return ExecutorPause(_executor);
		}
	}
	time = TimerEnd();
	return EXECUTOR_SUCCESS; 
}

Executor_Result AddTask(Executor* _executor, Taskfunc _func, size_t _period, void* _context)
{
	Task* task;
	if(_executor == NULL)
	{
		return EXECUTOR_UNINITIALIZED_ERROR;
	}
	if(_func == NULL)
	{
		return EXECUTOR_INPUT_NULL;
	}
	task = TaskCreate(_func, _period, _context);
	if(task == NULL)
	{
		return EXECUTOR_ALLOCATION_ERROR;
	}
	Heap_Insert(_executor->m_heap, task);
	_executor->numOfTasks++;
	return EXECUTOR_SUCCESS;
}

Executor_Result ExecutorPause(Executor* _executor)
{
	Vector* vector;
	Heap* heap;
	if (_executor == NULL)
	{
		return EXECUTOR_UNINITIALIZED_ERROR;
	}
	Heap_ForEach(_executor->m_heap, ResetTime, NULL);
	vector = Heap_Destroy(&_executor->m_heap);
	heap = Heap_Build(vector, TimeLessCheck);
	if (heap == NULL)
	{
		return EXECUTOR_ALLOCATION_ERROR;
	}
	_executor->m_heap = heap;
	_executor->m_IsPauseFlag = 1;
	return EXECUTOR_PAUSE;
}

static int IsPause(Executor* _executor)
{
	if(_executor == NULL)
	{
		return FALSE;
	}
	if(_executor->m_IsPauseFlag == 1)
	{
		return TRUE;
	}
	return FALSE;
}

void Pause(Executor* _executor)
{
	_executor->m_IsPauseFlag = 1;
}
