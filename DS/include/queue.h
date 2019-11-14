#ifndef _QUEUE_H
#define _QUEUE_H
#include "ADTErr.h"

typedef struct Queue Queue;

/* @Description: Create a fix size queue of integer number.
 * @Input: _size - the lentgh of the queue (must be more then 0).
 * @Return: pointer to the created queue or NULL- if not succseeded.
*/ 
Queue* QueueCreate(size_t _size);


/* @Description: Destroy the queue.
 * @Input: _queue- pointer to queue created by QueueCreate().
 * @Return: void.
*/ 
void QueueDestroy(Queue* _queue);


/* @Description: Add integer number to queue tail.
 * @Input: _queue- pointer to queue created by QueueCreate().
 * @Input: _item- the number we want to insert.
 * @Return: 
 * ERR_OK- if the number add to the queue.
 * ERR_OVER_FLOW- no room in queue.
 * ERR_UNINITINALAIZED - the pointer to the queue is NULL.
*/ 
ADTErr QueueInsert(Queue* _queue, int _item);


/* @Description: Remove item from the queue head.
 * @Input: _queue- pointer to queue created by QueueCreate()
 * @Input: _item- the number we remove from the queue.
 * @Return: 
   EE_OK- if the number remove from the queue.
 * ERR_EMPTY- the queue is empty and there is no item to remove.
 * ERR_UNINITINALAIZED - queue not created.
*/ 
ADTErr QueueRemove(Queue* _queue, int* _item);


/* @Description: Check if the queue is empty.
 * @Input: _queue- pointer to queue created by QueueCreate().
 * @Return: TRUE- if the queue is empty or NULL.
 * @Return: FALSE- if the queue is not empty.
 * @Error: UNINITINALAIZED - queue not created.
*/
int IsEmptyQueue(const Queue* _queue); /*Boolean*/


/* @Description: Prints the items in the queue.
 * @Input: _queue- pointer to queue created by QueueCreate().
 * @Return: void.
*/
void PrintQueue(const Queue* _queue); /*check int print*/


#endif /*_QUEUE_H*/ 
