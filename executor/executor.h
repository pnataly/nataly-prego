/*
 *  @file executor.h
 * 		a framework for Executor functions.
 * 		Version 0.01
 *  @author Nataly Prego.
 */

#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__
#include "genericVector.h"
#include "genericHeap.h"
#include "Task.h"
#include "Time.h"


#define TRUE 1
#define FALSE 0

typedef struct Executor Executor;

/*the task's functions should be in this format
return 1 if need reschedule task or 0 if need to remove from the Executor
typedef int(*Taskfunc)(void*); */

typedef enum Executor_Result {
	EXECUTOR_SUCCESS = 0,
	EXECUTOR_INPUT_NULL,
	EXECUTOR_UNINITIALIZED_ERROR, 		
	EXECUTOR_ALLOCATION_ERROR,
	EXECUTOR_PAUSE		
} Executor_Result;

/*
 * @brief Create a new Executor.
 * @param: _initialSize - the initial size.
 * @param: _extensionBlockSize - the extenstion block size.
 * @return newly created Executor or NULL on failure.
 */
Executor* ExecutorCreate(size_t _initialTasksSize, size_t _extensionTasksSize);

/*
 * @brief destroy the Executor.
 * @param[in] _executor : Executor to be destroyed.
 */
void ExecutorDestroy(Executor** _executor);

/*
 * @brief Insert a task to the Executor.
 * @param: _executor - pointer to the Executor created.
 * @param: Taskfunc - pointer to the task function.
 * @param: _period - the interval time to run the task - in miliseconds.
 * @return EXECUTOR_SUCCESS if succes.
 * @return EXECUTOR_ALLOCATION_ERROR if allocation fail.
 * @return EXECUTOR_UNINITIALIZED_ERROR if Executor is NULL.
 * @return EXECUTOR_INPUT_NULL if Taskfunc is NULL.
 */
Executor_Result AddTask(Executor* _executor, Taskfunc _func, size_t _period, void* _context);

/*
 * @brief running the tasks in the Executor by order of min time.
 * @param: _executor - pointer to the Executor created.
 * @return EXECUTOR_SUCCESS if succes.
 * @return EXECUTOR_UNINITIALIZED_ERROR if Executor is NULL.
 * @return EXECUTOR_PAUSE if pause.
 */
Executor_Result ExecutorRun(Executor* _executor);

/*
 * @brief pause the Executor.
 * @param: _executor - pointer to the Executor created.
 */
void Pause(Executor* _executor); /*need to give executor to pause */

Executor_Result ExecutorPause(Executor* _executor);




#endif /*__EXECUTOR_H__*/ 
