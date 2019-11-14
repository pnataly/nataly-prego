#ifndef __TASK_H__
#define __TASK_H__
#define NULL_POINTER -1
#define DONE 2
typedef struct Task Task;
typedef int(*Taskfunc)(void*);

/*
 * @brief create a task.
 * @param: Taskfunc - pointer to the task function.
 * @param: _period - the interval time to run the task.
 * @return newly created Task or NULL on failure.
 */
Task* TaskCreate(int(*Taskfunc)(void*), size_t _period, void* _context);

/*
 * @brief destroy the Task.
 * @param: _task - Task to be destroyed.
 */
void TaskDestroy(Task** _task);

/*
 * @brief get task's context.
 * @param: _task - the task.
 * @return the context.
 */
void* GetTaskContext(Task* _task);

/*
 * @brief running the task.
 * @param: _task - Task to run.
 * @return 1 if need reschedule task or 0 if need to remove from the Executor.
 */
int TaskRun(Task* _task, void* _context);

/*
 * @brief get task's period time.
 * @param: _task - Task to go get period time.
 * @return the period time.
 */
size_t GetTaskPeriodTime(Task* _task);

/*
 * @brief set task's run time.
 * @param: _task - Task to go set run time.
 */
void SetTaskRunTime(Task* _task, size_t _time);


/*
 * @brief reset the time of the tasks in the executor when pause.
 * @param: _element - .
 * @param: _context - .
 * @return NULL_POINTER if element is NULL.
 * @return DONE if sucess.
 */
int ResetTime(const void* _element, void* _context);

#endif /*__TASK_H__*/ 
